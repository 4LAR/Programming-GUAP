from typing import List
from fastapi import Depends, HTTPException
from pydantic import BaseModel
from bson import ObjectId
from globals import mongodb_cards
from token_manager import token_manager

# Pydantic model for a card
class Card(BaseModel):
    id: str  # This will hold the string representation of ObjectId
    name: str
    token: str
    # Add other fields as necessary

    class Config:
        # This will allow us to use ObjectId directly in the model
        json_encoders = {
            ObjectId: str  # Convert ObjectId to string
        }

# Response model
class CardListResponse(BaseModel):
    cards: List[Card]

async def card_list(
    user = Depends(token_manager)
) -> CardListResponse:
    """
    Список пропусков
    """
    if user["user"]["role"] != "admin":
        raise HTTPException(status_code=400, detail="You are not an admin")

    # Retrieve all cards from the database
    cards_cursor = mongodb_cards.find()
    cards = await cards_cursor.to_list(length=None)

    # Convert MongoDB documents to Pydantic models
    card_list = [Card(id=str(card["_id"]), name=card["name"], token=card["token"]) for card in cards]

    return CardListResponse(cards=card_list)
