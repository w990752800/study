import os
from dotenv import load_dotenv
from openai import OpenAI

load_dotenv()

QWEN_API_KEY = os.getenv("QWEN_API_KEY")
QWEN_API_URL = os.getenv("QWEN_API_URL")

client = OpenAI(
    api_key=QWEN_API_KEY,
    base_url=QWEN_API_URL,
)

response = client.chat.completions.create(
    model="qwen3.6-flash",
    messages=[
        {
            "role": "system",
            "content": "你是一个智能助手，帮助用户处理各种任务。"
        },
        {
            "role": "user",
            "content": "今天天气怎么样？"
        },
    ],
    stream=False,
)

print(response.choices[0].message.content)