from typing import  Any, Dict, List, Callable
import time

# ------------
# Memory 
# ------------
class Memory:
    def __init__(self):
        self.short = {} # 当前会话上下文
        self.long = {} # 长期偏好 / 联系人等

    def get_short(self, k, defalut=None):
        return self.short.get(k, defalut)

    def set_short(self, k, v):
        self.short[k] = v

    def get_long(self, k, defalut=None):
        return self.long.get(k, defalut)

    def set_long(self, k, v):
        self.long[k] = v

# ------------
# LLM 
# ------------
class LLMInterface:
    def generate(self, prompt: str) -> str:
        """
        这里给出一个简单的柜子模拟回答器
        """
        if "是否下雨" in prompt or "下雨" in prompt:
            return "请先查询天气；如果有雨，请生成提醒并发送给目标联系人。"
        if "生成提醒" in prompt:
            return "请提醒小王：明天北京有雨，请带伞。"
        return "我理解了"

# ------------
# 工具注册与模拟工具
# ------------
class ToolRegistry:
    def __init__(self):
        self.tools: Dict[str, Callable[..., Any]] = {}

    def register(self, name: str, fn: Callable[..., Any]):
        self.tools[name] = fn

    def call(self, name: str, *args, **kwargs):
        if name not in self.tools:
            raise ValueError(f"工具未注册：{name}")
        return self.tools[name](*args, **kwargs)

# 模拟工具: 天气查询
def mock_weather_api(city: str, date: str) -> Dict[str, Any]:
    if "北京" in city and "明天" in date:
        return  {"city": "北京", "date": "明天", "cond": "雨", "precip_mm": 5}
    return {"city": city, "date": date, "cond": "晴", "precip_mm": 0}

# 模拟工具： 发送消息
def mock_send_message(contact: str, message: str) -> bool:
    print(f"[发送消息] 给 {contact}: {message}")
    return True

# 模拟工具: 简单搜索
def mock_search(query: str) -> str:
    return f"搜索结果：{query} 的相关信息。"

# ------------
# Planner
# ------------
class SimplePlanner:
    def plan(self, goal: str) -> List[Dict[str, Any]]:
        steps = []

        if "天气" in goal or "下雨" in goal:
            steps.append({"action": "query_weather", "params": {"city": "北京", "date": "明天"}})
            steps.append({"action": "decide_and_notify", "params": {"contact": "小王"}})
        else:
            steps.append({"action": "search", "params": {"query": goal}})
        return steps

class Executor:
    def __init__(self, tools: ToolRegistry, llm: LLMInterface, memory: Memory):
        self.tools = tools
        self.llm = llm
        self.memory = memory

    def run_step(self, step: Dict[str, Any]):
        action = step["action"]
        params = step.get("params", {})

        if action == "query_weather":
            res = self.tools.call("weather_api", params["city"], params["date"])
            self.memory.set_short("last_weather", res)
            return res
        if action == "decide_and_notify":
            weather = self.memory.get_short("last_weather")
            if weather and weather["cond"] == "雨":
                message = self.llm.generate("生成提醒")
                self.tools.call("send_message", params["contact"], message)
                return {"notified": True, "message": message}
            else:
                return {"notified": False, "message": "天气良好，无需提醒。"}
        if action == "search":
            result = self.tools.call("search", params["query"])

        raise ValueError(f"未知的操作：{action}")


# ------------
# Agent
# ------------
class SimpleAgent:
    def __init__(self):
        self.memory = Memory()
        self.llm = LLMInterface()
        self.tools = ToolRegistry()
        self.planner = SimplePlanner()
        self.executor = Executor(self.tools, self.llm, self.memory)

        # 注册工具
        self.tools.register("weather_api", mock_weather_api)
        self.tools.register("send_message", mock_send_message)
        self.tools.register("search", mock_search)

    def handle(self, user_prompt: str):
        intent = self.llm.generate(user_prompt)
        print(f"[Agent] 目标: {user_prompt}")
        steps = self.planner.plan(user_prompt)
        results = []
        for step in steps:
            print(f"[Agent] 执行步骤: {step}")
            result = self.executor.run_step(step)
            print(f"[Agent] 步骤结果: {result}")
            time.sleep(1)  # 模拟执行时间
            results.append({"step": step, "result": result})
        return {"intent": intent, "steps": results}

# ------------
# 测试
# ------------
if __name__ == "__main__":
    agent = SimpleAgent()
    user_prompt = "请帮我查询明天北京的天气，并提醒小王带伞。"
    final_result = agent.handle(user_prompt)
    print(f"[Agent] 最终结果: {final_result}")