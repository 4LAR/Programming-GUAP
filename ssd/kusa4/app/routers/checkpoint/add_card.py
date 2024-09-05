from typing import Annotated
from fastapi import Form, Depends, HTTPException
from globals import mongodb_cards
from token_manager import token_manager
import bcrypt
import secrets

async def add_card(
    name: Annotated[str, Form()],
    user = Depends(token_manager)
):
    """
    Добавление нового пропуска
    """
    if (user["user"]["role"] != "admin"):
        raise HTTPException(status_code=400, detail="You not a admin")

    token = secrets.token_urlsafe(10)

    await mongodb_cards.insert_one({
        "name": name,
        "token": token
    })

    return {"message": "Successfully create card"}
