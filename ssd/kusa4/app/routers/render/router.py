from fastapi import APIRouter

from .index import index

render_router = APIRouter(
    tags=["Render"]
)

render_router.add_api_route(
    "/",
    index,
    methods=['GET']
)
