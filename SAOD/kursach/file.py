
import os
import json

def save_dict(dict, name):
    json.dump(dict, open(str(name) + '.json','w'), indent=2)

def read_dict(name):
    with open(str(name) + '.json', encoding='utf-8') as fh:
        data = json.load(fh)
    return data

class Data_file:
    def __init__(self, file_name="data"):
        self.file_name = file_name

        self.roomers = {}
        self.hotel_rooms = []
        self.move_roomer = []

        self.read()

    def clear(self):
        self.roomers = {}
        self.hotel_rooms = []
        self.move_roomer = []

    def save(self):
        data = {
            "roomers": self.roomers,
            "hotel_rooms": self.hotel_rooms,
            "move_roomer": self.move_roomer
        }
        save_dict(data, self.file_name)

    def read(self):
        if not os.path.exists(self.file_name + '.json'):
            self.save()
            self.read()
            return

        data = read_dict(self.file_name)

        self.roomers = data["roomers"]
        self.hotel_rooms = data["hotel_rooms"]
        self.move_roomer = data["move_roomer"]

    def get_all(self):
        return self.roomers, self.hotel_rooms, self.move_roomer
