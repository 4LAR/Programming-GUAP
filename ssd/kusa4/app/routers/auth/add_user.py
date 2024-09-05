from typing import Annotated
from fastapi import Form, Depends, HTTPException
from globals import mongodb_users
from token_manager import token_manager
import bcrypt

async def add_user(
    login: Annotated[str, Form()],
    password: Annotated[str, Form()],
    role: Annotated[str, Form()],
    user = Depends(token_manager)
):
    """
    Добавление нового пользователя
    """
    if (user["user"]["role"] != "admin"):
        raise HTTPException(status_code=400, detail="You not a admin")

    await mongodb_users.insert_one({
        "login": login,
        "password": password,
        "role": role
    })

    return {"message": "Successfully create user"}
