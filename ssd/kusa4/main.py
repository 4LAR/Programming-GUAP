from fastapi import FastAPI, Form, HTTPException
from fastapi.responses import HTMLResponse, RedirectResponse, StreamingResponse
from motor.motor_asyncio import AsyncIOMotorClient
import aiofiles
import cv2
from pydantic import BaseModel
from typing import List

app = FastAPI()

# Настройка подключения к MongoDB
MONGODB_URL = "mongodb://stolar:6079815243@194.87.214.70:27020/?authMechanism=DEFAULT"
client = AsyncIOMotorClient(MONGODB_URL)
db = client["user_database"]
users_collection = db["users"]

# Модель пользователя
class User(BaseModel):
    username: str

@app.get("/", response_class=HTMLResponse)
async def get():
    async with aiofiles.open('templates/index.html', mode='r') as f:
        return await f.read()

@app.post("/login")
async def login(username: str = Form(...), password: str = Form(...)):
    user = await users_collection.find_one({"username": username})
    if user and user["password"] == password:  # В реальном приложении используйте хеширование паролей
        return RedirectResponse(url="/video", status_code=303)
    else:
        raise HTTPException(status_code=400, detail="Incorrect username or password")

@app.get("/users", response_model=List[User])
async def get_users():
    users = []
    async for user in users_collection.find():
        print(user)
        users.append(User(username=user["username"]))
    return users

@app.get("/cameras")
async def get_cameras():
    cameras = []
    index = 0
    while True:
        cap = cv2.VideoCapture(index)  # Используем DirectShow
        if not cap.isOpened():
            break
        cameras.append({"id": index, "name": f"Камера {index + 1}"})
        cap.release()
        index += 1
    return cameras

@app.get("/video_feed")
async def video_feed(camera_id: int = 0):
    # Открываем выбранную камеру
    cap = cv2.VideoCapture(camera_id, cv2.CAP_DSHOW)  # Используем DirectShow

    def generate_frames():
        while True:
            success, frame = cap.read()  # Читаем кадр из веб-камеры
            if not success:
                break
            else:
                # Кодируем кадр в формате JPEG
                ret, buffer = cv2.imencode('.jpg', frame)
                frame = buffer.tobytes()
                yield (b'--frame\r\n'
                       b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')

    return StreamingResponse(generate_frames(), media_type='multipart/x-mixed-replace; boundary=frame')

@app.get("/video", response_class=HTMLResponse)
async def video():
    async with aiofiles.open('templates/video.html', mode='r') as f:
        return await f.read()

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
