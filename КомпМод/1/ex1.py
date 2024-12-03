import openpyxl

# Создание Excel-файла
wb = openpyxl.Workbook()
ws = wb.active
ws.title = "Animal Feed Optimization"

# Запись заголовков
ws.append(["Feed Type", "Price per kg", "Nutrient A", "Nutrient B", "Nutrient C", "Amount (kg)", "Total Cost"])
ws.append(["I", 9, 1, 2, 1, 0, "=B2*F2"])  # Изначально 0, формула для стоимости
ws.append(["II", 12, 3, 4, 4, 0, "=B3*F3"])  # Изначально 0, формула для стоимости
ws.append(["III", 10, 4, 2, 3, 0, "=B4*F4"])  # Изначально 0, формула для стоимости

# Запись минимальных требований
ws.append([])
ws.append(["Minimum Requirements"])
ws.append(["Nutrient", "Required Amount"])
ws.append(["A", 60])
ws.append(["B", 50])
ws.append(["C", 12])

# Запись формул для ограничения
ws.append([])
ws.append(["Constraints"])
ws.append(["Nutrient", "Total Amount"])
ws.append(["A", "=SUMPRODUCT(C2:C4, F2:F4)"])
ws.append(["B", "=SUMPRODUCT(D2:D4, F2:F4)"])
ws.append(["C", "=SUMPRODUCT(E2:E4, F2:F4)"])

# Запись формулы для целевой функции
ws.append([])
ws.append(["Objective Function"])
ws.append(["Total Cost", "=SUM(G2:G4)"])

# Настройка Excel Solver
ws.append([])
ws.append(["Solver Setup"])
ws.append(["Set Objective", "Total Cost"])
ws.append(["To", "Min"])
ws.append(["By Changing Variable Cells", "F2:F4"])
ws.append(["Subject to the Constraints"])
ws.append(["Constraints", "Cell Reference", "Relation", "Value"])
ws.append(["A", "SUMPRODUCT(C2:C4, F2:F4)", ">=", 60])
ws.append(["B", "SUMPRODUCT(D2:D4, F2:F4)", ">=", 50])
ws.append(["C", "SUMPRODUCT(E2:E4, F2:F4)", ">=", 12])

# Сохранение файла
wb.save("animal_feed_optimization.xlsx")

print("Excel файл 'animal_feed_optimization.xlsx' успешно создан.")
