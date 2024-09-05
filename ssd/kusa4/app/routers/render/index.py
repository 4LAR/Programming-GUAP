from fastapi import Request

from globals import templates

async def index(request: Request):
    return templates.TemplateResponse("index.html", {"request": request})
