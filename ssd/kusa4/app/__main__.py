import uvicorn
import main
from globals import config

if __name__ == "__main__":
    uvicorn.run(
        "main:app",
        host=config.get("FastAPI")["host"],
        port=config.get("FastAPI")["port"],
        reload=config.get("FastAPI")["reload"]
    )
