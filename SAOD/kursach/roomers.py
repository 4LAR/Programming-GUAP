# информация о постояльцах
import random

class Roomer:
    def __init__(self, pasport, birth, adress, purpose, name):
        self.pasport = pasport  # (строка) номер паспорта формата NNNN-NNNNNN (N - цифра)
        self.birth = birth      # (число) год рождения
        self.adress = adress    # (строка) адресс
        self.purpose = purpose  # (строка) цель прибывания
        self.name = name

    def print(self):
        print("%s %s %s %s" % (
            self.pasport,
            self.birth,
            self.adress,
            self.purpose
        ))

class HashTable:
    def __init__(self, template_key="NNNN-NNNNNN", count_sigments=2000):
        self.template_key = template_key        # формат ключа (N - число, C - символ)
        self.count_sigments = count_sigments
        self.hash_dict = {}

    def generate_hash(self, key):
        out = 1
        for el in key:
            out += ord(el) ** 2

        return int(out % self.count_sigments)

    def add(self, roomer):
        hash = self.generate_hash(roomer.pasport)
        count_collision = 1
        while True:
            if hash in self.hash_dict:
                hash += count_collision
                count_collision *= 2

            else:
                self.hash_dict[hash] = roomer
                break

    def get_by_hash(self, hash):
        return self.hash_dict[hash]

    def remove(self, hash):
        return self.hash_dict.pop(hash)

    def get_by_hash(self, hash):
        return self.hash_dict[hash]

    def clear_table(self):
        self.hash_dict = {}

    def print_table(self):
        for el in self.hash_dict:
            print("%d\t" % el, end="")
            self.hash_dict[el].print()

################################################################################
# поиск по заданию

    def find_by_pasport(self, pasport):
        for hash in self.hash_dict:
            if pasport == self.hash_dict[hash].pasport:
                return hash, self.hash_dict[hash]

        return None, None

    def find_by_name(self, name):
        for hash in self.hash_dict:
            if name == self.hash_dict[hash].name:
                return hash, self.hash_dict[hash]

        return None, None
