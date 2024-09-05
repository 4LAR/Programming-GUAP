from typing import Annotated
from fastapi import Form, Depends, HTTPException
from globals import mongodb_cards
from globals import mongodb_audit
from token_manager import token_manager
from datetime import datetime, timedelta

async def door(
    token: Annotated[str, Form()]
):
    """
    Проверка пропуска
    """

    # Use the token provided in the form data to find the card
    card = await mongodb_cards.find_one({"token": token})

    if not card:
        return {"status": False}

    await mongodb_audit.insert_one({
        "token": token,
        "user": card["name"],
        "datetime": datetime.utcnow() + timedelta(hours=3)
    })

    return {"status": True}
