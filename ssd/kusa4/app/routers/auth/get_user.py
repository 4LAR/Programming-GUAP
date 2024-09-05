from typing import Annotated
from fastapi import Form, HTTPException, Depends
from token_manager import token_manager

async def get_user(
    user = Depends(token_manager)
):
    """
    Получить данные о пользователе
    """

    return {
        "login": user["user"]["login"],
        "role": user["user"]["role"]
    }
