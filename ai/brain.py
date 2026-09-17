from openai import OpenAI
import os
from dotenv import load_dotenv


load_dotenv()

QWEN_API_KEY = os.getenv("QWEN_API_KEY")
QWEN_API_URL = os.getenv("QWEN_API_URL")

client = OpenAI(
    api_key=QWEN_API_KEY,
    base_url=QWEN_API_URL,
)

class AgentBrain:
    def __init__(self, model: str = "qwen3.6-flash"):
        self.model = model

    def think(self, prompt: str):
        try:
            response = client.chat.completions.create(
                model=self.model,
                messages=[
                    {
                        "role": "user",
                        "content": prompt
                    },
                ],
                temperature=0.5,
                max_tokens=500,
            )
            reasoning = response.choices[0].message.content
            return reasoning.strip()
        except Exception as e:
            print(f"Error during thinking: {e}")
            return "抱歉，我在思考时遇到了问题。"


if __name__ == "__main__":
    brain = AgentBrain()
    test_prompt = "你好，请介绍一下自己"
    print("测试提问:", test_prompt)
    print("大脑回复:", brain.think(test_prompt))
