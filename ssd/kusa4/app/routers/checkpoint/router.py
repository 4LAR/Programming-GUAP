from fastapi import APIRouter

from .add_card import add_card
from .card_list import card_list
from .door import door
from .get_audit import get_audit
from .get_audit_pdf import get_audit_pdf

checkpoint_router = APIRouter(
    prefix="/checkpoint",
    tags=["Сheckpoint"]
)

checkpoint_router.add_api_route(
    "/add_card",
    add_card,
    methods=['POST']
)

checkpoint_router.add_api_route(
    "/card_list",
    card_list,
    methods=['POST']
)

checkpoint_router.add_api_route(
    "/door",
    door,
    methods=['POST']
)

checkpoint_router.add_api_route(
    "/get_audit",
    get_audit,
    methods=['POST']
)

checkpoint_router.add_api_route(
    "/get_audit_pdf",
    get_audit_pdf,
    methods=['GET']
)
