from fastapi import APIRouter

from .video_feed import video_feed
from .list import list

cameras_router = APIRouter(
    prefix="/cameras",
    tags=["Cameras"]
)

cameras_router.add_api_route(
    "/video_feed",
    video_feed,
    methods=['GET']
)

cameras_router.add_api_route(
    "/list",
    list,
    methods=['GET']
)
