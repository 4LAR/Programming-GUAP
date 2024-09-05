from typing import Annotated
from fastapi import Depends, HTTPException
from globals import mongodb_users
from token_manager import token_manager

async def logout(user = Depends(token_manager)):
    """
    Выход из системы
    """
    # Удаление токена из массива tokens пользователя
    result = await mongodb_users.update_one(
        {"tokens": user["token"]},
        {"$pull": {"tokens": user["token"]}}
    )

    if result.modified_count == 0:
        raise HTTPException(status_code=400, detail="Token not found or already removed")

    return {"message": "Successfully logged out"}
