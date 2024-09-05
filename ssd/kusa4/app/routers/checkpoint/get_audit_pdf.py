from typing import List
from fastapi import Depends, HTTPException, FastAPI, Query
from fastapi.responses import FileResponse
from pydantic import BaseModel
from bson import ObjectId
from globals import mongodb_audit
from token_manager import token_manager
from datetime import datetime
from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas
import os

app = FastAPI()

class Audit(BaseModel):
    token: str
    user: str
    datetime: str

    class Config:
        json_encoders = {
            ObjectId: str
        }

def generate_pdf(audits: List[Audit], file_path: str) -> None:
    c = canvas.Canvas(file_path, pagesize=letter)
    width, height = letter
    c.drawString(100, height - 50, "Audit Report")
    c.drawString(100, height - 70, "Date: " + str(datetime.now().date()))
    y = height - 100

    for audit in audits:
        c.drawString(100, y, f"Token: {audit.token}, User: {audit.user}, DateTime: {audit.datetime}")
        y -= 20

    c.save()

# @app.get("/audit/pdf", response_class=FileResponse)
async def get_audit_pdf(
    user = Depends(token_manager),
    date_str: str = Query(..., description="Дата в формате YYYY-MM-DD")
) -> FileResponse:
    try:
        filter_date = datetime.strptime(date_str, "%Y-%m-%d").date()
    except ValueError:
        raise HTTPException(status_code=400, detail="Неверный формат даты. Используйте YYYY-MM-DD.")

    audit_cursor = mongodb_audit.find()
    audits = await audit_cursor.to_list(length=None)

    audit_list = []
    for audit in audits:
        audit_date = audit["datetime"].date() if isinstance(audit["datetime"], datetime) else audit["datetime"]

        if audit_date == filter_date:
            datetime_str = audit["datetime"].isoformat() if isinstance(audit["datetime"], datetime) else str(audit["datetime"])
            audit_list.append(Audit(token=audit["token"], user=audit["user"], datetime=datetime_str))

    if not audit_list:
        raise HTTPException(status_code=404, detail="Нет записей за указанную дату.")

    pdf_file_path = "audit_report.pdf"
    generate_pdf(audit_list, pdf_file_path)

    return FileResponse(pdf_file_path, media_type='application/pdf', filename='audit_report.pdf')
