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
    CreateDate VARCHAR(255),
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
