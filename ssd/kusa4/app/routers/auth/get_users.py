from typing import List
from fastapi import Depends, HTTPException, FastAPI
from pydantic import BaseModel
from globals import mongodb_users
from token_manager import token_manager

app = FastAPI()

class User(BaseModel):
    login: str
    role: str

async def get_users(user=Depends(token_manager)):
    """
    Получение всех пользователей
    """
    if user["user"]["role"] != "admin":
        raise HTTPException(status_code=403, detail="You are not an admin")

    users_cursor = mongodb_users.find()
    users = await users_cursor.to_list(length=None)

    user_list = []
    for user in users:
        user_list.append(User(login=user["login"], role=user["role"]))

    return user_list
