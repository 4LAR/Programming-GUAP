from typing import List
from fastapi import Depends, HTTPException
from pydantic import BaseModel
from bson import ObjectId
from globals import mongodb_audit
from token_manager import token_manager
from datetime import datetime

# Pydantic model for an audit entry
class Audit(BaseModel):
    token: str
    user: str
    datetime: str  # Expecting a string representation of the datetime

    class Config:
        # This will allow us to use ObjectId directly in the model
        json_encoders = {
            ObjectId: str  # Convert ObjectId to string
        }

# Response model
class AuditListResponse(BaseModel):
    audit: List[Audit]

async def get_audit(
    user = Depends(token_manager)
) -> AuditListResponse:
    """
    Аудит пропусков
    """

    # Retrieve all audit entries from the database
    audit_cursor = mongodb_audit.find()
    audits = await audit_cursor.to_list(length=None)

    # Convert MongoDB documents to Pydantic models
    audit_list = []
    for audit in audits:
        # Convert the datetime field to a string if it's not already
        datetime_str = audit["datetime"].isoformat() if isinstance(audit["datetime"], datetime) else str(audit["datetime"])

        audit_list.append(Audit(token=audit["token"], user=audit["user"], datetime=datetime_str))

    return AuditListResponse(audit=audit_list)
