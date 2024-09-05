import secrets
import bcrypt
from typing import Annotated
from fastapi import Form, HTTPException
from globals import mongodb_users

async def login(
    login: Annotated[str, Form()],
    password: Annotated[str, Form()]
):
    """
    Авторизация
    """
    # Поиск пользователя в базе данных по логину или email
    user = await mongodb_users.find_one({"$or": [{"login": login}, {"email": login}]})

    if not user:
        raise HTTPException(status_code=400, detail="Incorrect login or password")

    # Проверка пароля
    if user["password"] != password:
        raise HTTPException(status_code=400, detail="Incorrect login or password")

    # Генерация токена длиной 60 символов
    token = secrets.token_urlsafe(60)

    # Добавление токена в массив tokens пользователя
    await mongodb_users.update_one(
        {"$or": [{"login": login}, {"email": login}]},
        {"$push": {"tokens": token}}
    )

    return {"token": token}
