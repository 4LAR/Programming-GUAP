from fastapi import APIRouter

from .login import login
from .logout import logout
from .get_user import get_user
from .add_user import add_user
from .remove_user import remove_user
from .get_users import get_users

auth_router = APIRouter(
    prefix="/auth",
    tags=["Auth"]
)

auth_router.add_api_route(
    "/login",
    login,
    methods=['POST']
)

auth_router.add_api_route(
    "/logout",
    logout,
    methods=['POST']
)

auth_router.add_api_route(
    "/get_user",
    get_user,
    methods=['POST']
)

auth_router.add_api_route(
    "/add_user",
    add_user,
    methods=['POST']
)

auth_router.add_api_route(
    "/remove_user",
    remove_user,
    methods=['POST']
)

auth_router.add_api_route(
    "/get_users",
    get_users,
    methods=['POST']
)
