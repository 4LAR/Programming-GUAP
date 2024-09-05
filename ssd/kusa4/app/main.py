from fastapi import FastAPI
from fastapi import Request
from fastapi.responses import HTMLResponse
from fastapi.staticfiles import StaticFiles
from fastapi import Depends
import os

from routers import auth_router
from routers import cameras_router
from routers import render_router
from routers import checkpoint_router

app = FastAPI(
    title='WatchGuard'
)

app.mount("/static", StaticFiles(directory=f"{os.path.dirname(os.path.abspath(__file__))}/static"), name="static")

################################################################################

app.include_router(auth_router)
app.include_router(cameras_router)
app.include_router(render_router)
app.include_router(checkpoint_router)

################################################################################
# qsBJXfvsORCrN8uTexgN2ZN2kIHRpEwpvCJM0DjUFVXtrMeDNA5MFviJ5J-Hvy4hkRGDcoHP_y_yFZFH
################################################################################
