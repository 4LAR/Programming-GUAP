-- Создание таблицы "City"
CREATE TABLE City (
    IDCity INT PRIMARY KEY,
    NameCity VARCHAR(50)
);

-- Создание таблицы "Street"
CREATE TABLE Street (
    IDStreet INT PRIMARY KEY,
    IDCity INT,
    StrretName VARCHAR(255),
    FOREIGN KEY (IDCity) REFERENCES City (IDCity)
ON DELETE CASCADE ON UPDATE RESTRICT
);

-- Создание таблицы "Addres"
CREATE TABLE Addres (
    IDAdress INT PRIMARY KEY,
    House VARCHAR(50),
    IDStreet INT,
    FOREIGN KEY (IDStreet) REFERENCES Street (IDStreet)
ON DELETE CASCADE ON UPDATE RESTRICT
);

-- Создание таблицы "TypeSight"
CREATE TABLE TypeSight (
    IDTypeSight INT PRIMARY KEY,
    TypeSightName VARCHAR(255)

);

-- Создание таблицы "Sight"
CREATE TABLE Sight (
    IDSight INT PRIMARY KEY,
    NameSight VARCHAR(255),
    CreateDate DATE,
    IDAdress INT,
    IDTypeSight INT,

    FOREIGN KEY (IDAdress) REFERENCES Addres (IDAdress)
ON DELETE CASCADE ON UPDATE RESTRICT,

    FOREIGN KEY (IDTypeSight) REFERENCES TypeSight (IDTypeSight)
ON DELETE CASCADE ON UPDATE RESTRICT
);

-- Создание таблицы "Sight"
CREATE TABLE Sight2 (
    IDSight INT PRIMARY KEY,
    NameSight VARCHAR(255),
    CreateDate VARCHAR(255),
    IDAdress INT,
    IDTypeSight INT,

    FOREIGN KEY (IDAdress) REFERENCES Addres (IDAdress)
ON DELETE CASCADE ON UPDATE RESTRICT,

    FOREIGN KEY (IDTypeSight) REFERENCES TypeSight (IDTypeSight)
ON DELETE CASCADE ON UPDATE RESTRICT
);

--------------------------------------------------------------------------------

INSERT INTO City (IDCity, NameCity) VALUES (1, 'Санкт Петербург');

INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (1, 1, 'Театральная площадь');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (2, 1, 'Набережная реки Фонтанки');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (3, 1, 'Дворцовый проспект');

INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (1, '1', 1);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (2, '21 Шуваловский дворец', 2);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (3, 'д. 48, лит А', 3);

INSERT INTO TypeSight (IDTypeSight, TypeSightName) VALUES (1, 'Музей');
INSERT INTO TypeSight (IDTypeSight, TypeSightName) VALUES (2, 'театр');

INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (1, 'Музей Фаберже', '2013-01-01', 2, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (2, 'Музей-заповедник "Ораниенбаум"', '1711-01-01', 3, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (3, 'Мариинский театр', '1860-01-01', 1, 2);

-- МСК https://www.tripadvisor.ru/Attractions-g298484-Activities-Moscow_Central_Russia.html
INSERT INTO City (IDCity, NameCity) VALUES (2, 'Москва');

INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (4, 2, 'Дольская улица');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (5, 2, 'Андропова проспект');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (6, 2, 'Театральная пл');

INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (4, 'д. 1', 4);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (5, '39', 5);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (6, '1', 6);

INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (4, 'Царицыно Музей-Заповедник', '1984-01-01', 4, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (5, 'Московский Государственный Объединенный Музей-Заповедник "Коломенское"', '2005-01-01', 5, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (6, 'Большой театр', '1776-01-01', 6, 2);

-- ИЖЕВСК https://www.tripadvisor.ru/Attractions-g673777-Activities-Izhevsk_Udmurt_Republic_Volga_District.html

INSERT INTO City (IDCity, NameCity) VALUES (3, 'Ижевск');

INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (7, 3, 'ул. Бородина');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (8, 3, 'ул. Карла Маркса');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (9, 3, 'Коммунаров улица');

INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (7, 'д. 19', 7);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (8, '222', 8);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (9, '287', 9);

INSERT INTO TypeSight (IDTypeSight, TypeSightName) VALUES (3, 'Памятник');

INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (7, 'Музейно-выставочный комплекс стрелкового оружия им. М.Т. Калашникова', '2004-01-01', 7, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (8, 'Памятник благоверным Петру и Февронии Муромским', '2008-01-01', 8, 3);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (9, 'Национальный Музей Удмуртской Республики', '1920-01-01', 9, 1);

-- для условий

INSERT INTO City (IDCity, NameCity) VALUES (4, 'Пустырь');
INSERT INTO City (IDCity, NameCity) VALUES (5, 'Поле');
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (10, 'Музей веселья', '2077-01-01', 8, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (11, 'какой-то памятник', '2009-01-01', 2, 3);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (12, 'какой-то дворец', '2033-01-01', 2, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (13, 'Архитектурный комплекс', '1389-01-01', 1, 2);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (14, 'Музей страданий', '2077-01-01', 8, 1);

INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (100, 'Памятник уныния', '2000-01-01', 8, 1);
