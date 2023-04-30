# Номер студенческого билета: 2021/3026
# Предметная область: 2 Регистрация постояльцев в гостинице (см. п. 9.3)
# Метод хеширования: 2 Закрытое хеширование с квадратичным опробованием
# Метод сортировки: 5 Слиянием
# Вид списка: 1 Линейный двунаправленный
# Метод обхода дерева: 2 Прямой
# Алгоритм поиска слова в тексте: 0 Боуера и Мура (БМ)

import datetime

from avltree import *
from roomers import *
from hotel_rooms import *
from move_roomers import *
from file import *
from menu import *

# более подробный вывод
# удаление из move_roomer постаяльца если мы его удаляем
# ограничение на количество человек в номере

################################################################################

def get_current_year():
    return datetime.datetime.now().year

################################################################################

data_file = Data_file("data")

move_list = None
tree = AVLTree()
hash_table = HashTable()

################################################################################

def read_file():
    global move_list

    for key in data_file.roomers:
        hash_table.add(Roomer(**data_file.roomers[key]))

    for el in data_file.hotel_rooms:
        tree.insert(tree, Room(**el))

    for el in data_file.move_roomer:
        move_roomer = Move_roomer(**el)
        if move_list == None:
            move_list = Element_list(move_roomer)
        else:
            move_list.add(move_roomer)

def save_to_file():
    data_file.clear()
    for key in hash_table.hash_dict:
        data = {}
        data["name"] = hash_table.hash_dict[key].name
        data["pasport"] = hash_table.hash_dict[key].pasport
        data["birth"] = hash_table.hash_dict[key].birth
        data["adress"] = hash_table.hash_dict[key].adress
        data["purpose"] = hash_table.hash_dict[key].purpose
        data_file.roomers[key] = data

    tree_return = tree.pre_order_return(tree)
    for el in tree_return:
        data = {}
        data["number"] = el.number
        data["count_seats"] = el.count_seats
        data["count_rooms"] = el.count_rooms
        data["bathroom"] = el.bathroom
        data["equipment"] = el.equipment
        data_file.hotel_rooms.append(data)

    if move_list != None:
        move_list_out = move_list.get_all()
        for el in move_list_out:
            data = {}
            data["pasport"] = el.pasport
            data["number"] = el.number
            data["date_in"] = el.date_in
            data["date_out"] = el.date_out
            data_file.move_roomer.append(data)

    data_file.save()

read_file()

################################################################################

def add_roomer():
    global hash_table
    data = {}
    data["name"] = input("ФИО: ")
    data["pasport"] = input("Номер паспорта(NNNN-NNNNNN): ")
    if not check_format(data["pasport"], "NNNN-NNNNNN"):
        print("Строка не соответствует формату")
        return

    data["birth"] = int(input("Год рождения: "))
    if (data["birth"] < 1900 and data["birth"] < get_current_year()):
        print("Дата не корректна")
        return

    data["adress"] = input("Адресс: ")
    data["purpose"] = input("Цель прибывания: ")

    hash_table.add(Roomer(**data))

def delete_roomer():
    pasport = input("Номер паспорта постаяльца(NNNN-NNNNNN): ")
    if not check_format(pasport, "NNNN-NNNNNN"):
        print("Строка не соответствует формату")
        return

    hash, roomer = hash_table.find_by_pasport(pasport)
    if hash == None:
        print("Такого постаяльца нет")
        return

    hash_table.remove(hash)

def show_roomers():
    hash_table.print_table()

def clear_roomers():
    hash_table.clear_table()

def find_roomer_by_passport():
    pasport = input("Номер паспорта постаяльца(NNNN-NNNNNN): ")
    if not check_format(pasport, "NNNN-NNNNNN"):
        print("Строка не соответствует формату")
        return

    hash, roomer = hash_table.find_by_pasport(pasport)
    if hash == None:
        print("Такого постаяльца нет")
        return

    roomer.print()

def find_roomer_by_name():
    name = input("ФИО постаяльца: ")

    hash, roomer = hash_table.find_by_name(name)
    if hash == None:
        print("Такого постаяльца нет")
        return

    roomer.print()

################################################################################

def add_hotel_room():
    global tree

    data = {}
    data["number"] = input("Номер (ANNN): ")
    if not check_format(data["number"], "ANNN"):
        print("Строка не соответствует формату")
        return

    data["count_seats"] = abs(int(input("Количество мест: ")))
    data["count_rooms"] = abs(int(input("Количество комнат: ")))
    data["bathroom"] = read_bool("Наличие санузла")
    data["equipment"] = input("Оборудование: ")

    room = Room(**data)
    tree.insert(tree, room)

def print_hotel_room():
    tree.pre_order(tree)

def delte_hotel_room():
    number = input("Номер (ANNN): ")
    if not check_format(number, "ANNN"):
        print("Строка не соответствует формату")
        return

    if not tree.delete_by_number(number):
        print("Такого номера не существует")

def clear_hotel_rooms():
    tree.clear()

def search_hotel_room_by_number():
    number = input("Номер (ANNN): ")
    if not check_format(number, "ANNN"):
        print("Строка не соответствует формату")
        return

    room = tree.search_by_number(number)
    if room == None:
        print("Такого номера нет")
        return

    room.print()

def search_hotel_room_by_equipment():
    equipment = input("Оборудование: ")
    arr = tree.search_by_equipment(equipment)
    for el in arr:
        print("-" * 20)
        arr.print()

################################################################################

def add_move():
    global move_list

    data = {}
    data["pasport"] = input("Номер паспорта(NNNN-NNNNNN): ")
    if not check_format(data["pasport"], "NNNN-NNNNNN"):
        print("Строка не соответствует формату")
        return

    hash, roomer = hash_table.find_by_pasport(data["pasport"])
    if hash == None:
        print("Такого постаяльца нет")
        return

    data["number"] = input("Номер (ANNN): ")
    if not check_format(data["number"], "ANNN"):
        print("Строка не соответствует формату")
        return

    room = tree.search_by_number(data["number"])
    if room == None:
        print("Такого номера нет")
        return

    data["date_in"] = input("Дата заселения: ")
    data["date_out"] = input("Дата выселения: ")

    move_roomer = Move_roomer(**data)
    if move_list == None:
        move_list = Element_list(move_roomer)
    else:
        move_list.add(move_roomer)

def delete_move():
    passport = input("Номер паспорта(NNNN-NNNNNN): ")
    if not check_format(data["pasport"], "NNNN-NNNNNN"):
        print("Строка не соответствует формату")
        return

    id = move_list.search_by_pasport(passport)
    if id == None:
        print("Такого постаяльца нет")
        return

    move_list.delete_element(id)

def print_move():
    global move_list
    for i in range(move_list.get_length()):
        print("%d) %s %s %s %s" % (
            i,
            move_list.get_current_item(i).item.pasport,
            move_list.get_current_item(i).item.number,
            move_list.get_current_item(i).item.date_in,
            move_list.get_current_item(i).item.date_out
        ))

################################################################################

menu = Menu([
    ["Выход\n", exit],

    ["Регистрация постаяльца в номер", add_move],
    ["Выселение постаяльца", delete_move],
    ["Список заселённых постаяльцев\n", print_move],

    ["Регистрация постаяльца", add_roomer],
    ["Удаление данных постаяльца", delete_roomer],
    ["Список постаяльцев", show_roomers],
    ["Очистить список постаяльцев", clear_roomers],
    ["Поиск постаяльца по номеру паспорта", find_roomer_by_passport],
    ["Поиск постаяльца по ФИО\n", find_roomer_by_name],

    ["Добавить гостиночный номер", add_hotel_room],
    ["Удалить гостиночный номер", delte_hotel_room],
    ["Вывести список гостиночных номеров", print_hotel_room],
    ["Очистить все данные о гостиночных номерах", clear_hotel_rooms],
    ["Поиск гостиночного номера по номеру", search_hotel_room_by_number],
    ["Поиск гостиночного номера по оборудованию", search_hotel_room_by_equipment]
], save_to_file)

menu.run()
