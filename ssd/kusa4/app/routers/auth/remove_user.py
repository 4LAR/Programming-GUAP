from typing import Annotated
from fastapi import Form, Depends, HTTPException
from globals import mongodb_users
from token_manager import token_manager
import bcrypt

async def remove_user(
    login: Annotated[str, Form()],
    user = Depends(token_manager)
):
    """
    Удаление пользователя
    """
    if (user["user"]["role"] != "admin"):
        raise HTTPException(status_code=400, detail="You not a admin")

    await mongodb_users.delete_one({"login": login})

    return {"message": "Successfully remove user"}
