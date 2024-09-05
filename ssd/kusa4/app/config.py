
# def retrieve_name(var):
#     callers_local_vars = inspect.currentframe().f_back.f_locals.items()
#     return [var_name for var_name, var_val in callers_local_vars if var_val is var]
#

import configparser
import os

# преобразование строки в boolean
def get_bool(str):
    return True if str.lower() == 'true' else False

class Config:
    def __init__(self, file_name):
        self.file_name = file_name

        # набор параметров
        self.options = {
            "FastAPI": {
                "host": "0.0.0.0",
                "port": 80,
                "reload": True
            },
            "MongoDB": {
                "url": "mongodb://localhost:27017"
            }
        }

        self.read()

    # преобразование строки в нужный формат данных
    def set_settings(self, section, parameter, state):
        if (type(self.options[section][parameter]) == str):
            self.options[section][parameter] = state

        elif (type(self.options[section][parameter]) == bool):
            self.options[section][parameter] = get_bool(state)

        elif (type(self.options[section][parameter]) == int):
            self.options[section][parameter] = int(state)

        elif (type(self.options[section][parameter]) == float):
            self.options[section][parameter] = float(state)

    # запись настроек в файл
    def save(self):
        config = configparser.ConfigParser()

        for section in self.options:
            config.add_section(section)

            for parameter in self.options[section]:
                config.set(section, str(parameter), str(self.options[section][parameter]))

        with open(self.file_name, "w") as config_file:
            config.write(config_file)

    # чтение настроек в файл
    def read(self):
        if not os.path.exists(self.file_name):
            #
            self.save()
            self.read()

        else:
            config = configparser.ConfigParser()
            config.read(self.file_name)

            error_bool = False

            # проверка каждого параметра
            for section in self.options:
                for parameter in self.options[section]:
                    try:
                        parameter_buf = config.get(section, parameter)
                        parameter_buf = os.environ.get(f"{section.upper()}_{parameter.upper()}", parameter_buf)
                        self.set_settings(section, parameter, parameter_buf)

                    except:
                        error_bool = True

            # если возникли проблемы при чтении, то пересохраняем настройки
            if error_bool:
                self.save()

    # возврат конктретной группы настроек
    def get(self, section):
        return self.options[section]

    # вывод всех настроек в консоль
    def print(self):
        for section in self.options:
            print(f"{section.upper()}:")
            for parameter in self.options[section]:
                print(f"\t{parameter.upper()} = {self.options[section][parameter]}")

    # возврат всех настроек
    def get_all(self):
        return self.options
