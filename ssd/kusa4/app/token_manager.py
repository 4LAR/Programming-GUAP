from fastapi import Depends, HTTPException
from fastapi.security import HTTPBearer, HTTPAuthorizationCredentials
from globals import mongodb_users

security = HTTPBearer()

async def token_manager(credentials: HTTPAuthorizationCredentials = Depends(security)):
    user = await mongodb_users.find_one({"tokens": credentials.credentials})

    if not user:
        raise HTTPException(status_code=400, detail="Token is invalid or not found")

    return {
        "user": user,
        "token": credentials.credentials
    }
