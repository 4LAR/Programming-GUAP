from typing import Annotated
from fastapi import Form, HTTPException, Depends
from fastapi.responses import StreamingResponse
from token_manager import token_manager
import cv2

from video import *

async def video_feed(
    camera_indices: str,
    user = Depends(token_manager)
):
    """
    Поток камеры
    """

    indices = list(map(int, camera_indices.split(',')))
    return StreamingResponse(
        generate_frames(indices),
        # generate_multiple_frames(indices),
        media_type='multipart/x-mixed-replace; boundary=frame'
    )
