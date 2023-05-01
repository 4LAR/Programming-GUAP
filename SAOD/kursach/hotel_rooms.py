# информация о гостиночных номерах
class Room:
    def __init__(self, number, count_seats, count_rooms, bathroom, equipment):
        self.number = number            # строка формата ANNN, где A – буква,
                                        # обозначающая тип номера (Л – люкс, П – полулюкс,
                                        # О – одноместный, М – многоместный); NNN – порядковый номер (цифры)
        self.count_seats = count_seats  # Количество мест
        self.count_rooms = count_rooms  # Количество комнат
        self.bathroom = bathroom        # Наличие санузла (bool)
        self.equipment = equipment      # Оборудование

    def print(self):
        print("Номер: %s\nКоличество мест: %d\nКоличество комнат: %d\nНаличие санузла: %s\nОборудование: %s" % (
            self.number,
            self.count_seats,
            self.count_rooms,
            ("True" if self.bathroom else "False"),
            self.equipment
        ))
