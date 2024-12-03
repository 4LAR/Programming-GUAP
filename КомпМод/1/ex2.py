import pandas as pd

# Создаем данные для Excel
data = {
    "Корм": ["I", "II", "III", "Итого"],
    "Цена (руб/кг)": [9, 12, 10, ""],
    "A (ед/кг)": [1, 3, 4, ""],
    "B (ед/кг)": [2, 4, 2, ""],
    "C (ед/кг)": [1, 4, 3, ""],
    "Количество (кг)": ["", "", "", ""],
    "Суммарная стоимость": ["=B2*F2", "=B3*F3", "=B4*F4", "=SUM(G2:G4)"]
}

constraints = {
    "Питательные вещества": ["A", "B", "C"],
    "Расчетное значение": [
        "=C2*F2 + C3*F3 + C4*F4",
        "=D2*F2 + D3*F3 + D4*F4",
        "=E2*F2 + E3*F3 + E4*F4"
    ],
    "Минимум": [60, 50, 12]
}

# Создаем Excel файл
file_path = ".nimal_feed_optimization1.xlsx"
with pd.ExcelWriter(file_path, engine='xlsxwriter') as writer:
    df_data = pd.DataFrame(data)
    df_constraints = pd.DataFrame(constraints)

    # Записываем данные
    df_data.to_excel(writer, index=False, sheet_name="Данные")
    df_constraints.to_excel(writer, index=False, sheet_name="Ограничения")

    # Настраиваем ширину столбцов
    worksheet_data = writer.sheets["Данные"]
    worksheet_constraints = writer.sheets["Ограничения"]
    for sheet in [worksheet_data, worksheet_constraints]:
        sheet.set_column("A:H", 20)

file_path
