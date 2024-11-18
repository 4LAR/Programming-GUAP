-- Создание таблицы City
CREATE TABLE City (
    IDCity SERIAL PRIMARY KEY,
    NameCity VARCHAR(100) NOT NULL
);

-- Создание таблицы Street
CREATE TABLE Street (
    IDStreet SERIAL PRIMARY KEY,
    IDCity INTEGER NOT NULL,
    StreetName VARCHAR(100) NOT NULL,
    FOREIGN KEY (IDCity) REFERENCES City(IDCity) ON DELETE CASCADE
);

-- Создание составного типа для адреса
CREATE TYPE AddressType AS (
    House VARCHAR(50),
    IDStreet INTEGER
);

-- Создание таблицы Address
CREATE TABLE Address (
    IDAddress SERIAL PRIMARY KEY,
    AddressInfo AddressType NOT NULL
);

-- Создание таблицы TypeSight
CREATE TABLE TypeSight (
    IDTypeSight SERIAL PRIMARY KEY,
    TypeSightName VARCHAR(50) NOT NULL
);

-- Создание таблицы Sight (базовая таблица)
CREATE TABLE Sight (
    IDSight SERIAL PRIMARY KEY,
    NameSight VARCHAR(100) NOT NULL,
    CreateDate VARCHAR(50),
    IDAddress INTEGER NOT NULL,
    IDTypeSight INTEGER NOT NULL,
    FOREIGN KEY (IDAddress) REFERENCES Address(IDAddress) ON DELETE CASCADE,
    FOREIGN KEY (IDTypeSight) REFERENCES TypeSight(IDTypeSight) ON DELETE CASCADE
);

--------------------------------------------------------------------------------
-- FOREIGN KEY (IDSight) REFERENCES Sight(IDSight) ON DELETE CASCADE
-- Создание таблицы Museum (наследник Sight)
CREATE TABLE Museum (
    PRIMARY KEY (IDSight),
    Exhibition VARCHAR(100),
    FOREIGN KEY (IDAddress) REFERENCES Address(IDAddress) ON DELETE CASCADE,
    FOREIGN KEY (IDTypeSight) REFERENCES TypeSight(IDTypeSight) ON DELETE CASCADE
) INHERITS (Sight);

-- Создание таблицы Theater (наследник Sight)
CREATE TABLE Theater (
    PRIMARY KEY (IDSight),
    Director VARCHAR(100),
    FOREIGN KEY (IDAddress) REFERENCES Address(IDAddress) ON DELETE CASCADE,
    FOREIGN KEY (IDTypeSight) REFERENCES TypeSight(IDTypeSight) ON DELETE CASCADE
) INHERITS (Sight);

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------

-- Вставка данных
INSERT INTO City (NameCity) VALUES ('Санкт Петербург');
INSERT INTO City (NameCity) VALUES ('Москва');
INSERT INTO City (NameCity) VALUES ('Ижевск');

INSERT INTO Street (IDCity, StreetName) VALUES (1, 'Театральная площадь');
INSERT INTO Street (IDCity, StreetName) VALUES (1, 'Набережная реки Фонтанки');
INSERT INTO Street (IDCity, StreetName) VALUES (1, 'Дворцовый проспект');

INSERT INTO Address (AddressInfo) VALUES (ROW('1', 1));
INSERT INTO Address (AddressInfo) VALUES (ROW('21 Шуваловский дворец', 2));
INSERT INTO Address (AddressInfo) VALUES (ROW('д. 48, лит А', 3));

INSERT INTO TypeSight (TypeSightName) VALUES ('Музей');
INSERT INTO TypeSight (TypeSightName) VALUES ('Театр');

INSERT INTO Museum (NameSight, CreateDate, IDAddress, IDTypeSight, Exhibition) VALUES ('Музей Фаберже', '2013 г.', 2, 1, 'Выставка ювелирного искусства');
INSERT INTO Theater (NameSight, CreateDate, IDAddress, IDTypeSight, Director) VALUES ('Мариинский театр', '2 октября 1860 г.', 1, 2, 'Василий Иванов');

-- Пример вставки данных для других городов
INSERT INTO City (NameCity) VALUES ('Пустырь');
INSERT INTO City (NameCity) VALUES ('Поле');
