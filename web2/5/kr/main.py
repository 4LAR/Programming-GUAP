from fastapi.responses import HTMLResponse
from fastapi.templating import Jinja2Templates
from fastapi.responses import JSONResponse
from fastapi import *
import uvicorn

from typing import Annotated


app = FastAPI()

templates = Jinja2Templates(directory="templates")

@app.post("/calculate/")
async def calculate(num1: float = Form(...), num2: float = Form(...), operator: str = Form(...)):
    if operator == "+":
        result = num1 + num2
    elif operator == "-":
        result = num1 - num2
    elif operator == "*":
        result = num1 * num2
    elif operator == "/":
        if num2 != 0:
            result = num1 / num2
        else:
            return "Ошибка: деление на ноль!"
    else:
        return "Ошибка: неверный оператор!"

    return {"result": result}

@app.get("/")
async def main(request: Request):
    return templates.TemplateResponse("index.html", {"request": request})

if __name__ == "__main__":
    uvicorn.run(
        "main:app",
        host="0.0.0.0",
        port=81,
        reload=True
    )
