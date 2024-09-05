from typing import Annotated
from fastapi import Form, HTTPException, Depends
from token_manager import token_manager
import cv2

async def list(
    user = Depends(token_manager)
):
    """
    Получить список камер
    """

    available_cameras = []
    for i in range(10):  # Check the first 10 indices
        cap = cv2.VideoCapture(i)
        if cap.isOpened():
            available_cameras.append(i)
            cap.release()  # Release the camera
    return {"available_cameras": available_cameras}
