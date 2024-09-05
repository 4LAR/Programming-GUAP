import os

from config import Config

config = Config("config.ini")
config.print()

################################################################################

from fastapi.templating import Jinja2Templates

templates = Jinja2Templates(directory=f"{os.path.dirname(os.path.abspath(__file__))}/templates")

################################################################################

import motor.motor_asyncio
mongodb_client = motor.motor_asyncio.AsyncIOMotorClient(config.get("MongoDB")["url"])
mongodb_db = mongodb_client["WatchGuard"]
mongodb_users = mongodb_db["users"]
mongodb_cards = mongodb_db["cards"]
mongodb_audit = mongodb_db["audit"]
