-- Вставка данных в таблицу City
INSERT INTO City (NameCity) VALUES ('Нью-Йорк');
INSERT INTO City (NameCity) VALUES ('Лондон');
INSERT INTO City (NameCity) VALUES ('Париж');

-- Вставка данных в таблицу Street
INSERT INTO Street (IDCity, StreetName) VALUES (1, 'Уолл-стрит');
INSERT INTO Street (IDCity, StreetName) VALUES (1, 'Бродвей');
INSERT INTO Street (IDCity, StreetName) VALUES (2, 'Оксфорд-стрит');
INSERT INTO Street (IDCity, StreetName) VALUES (3, 'Шанз-Элизе');

-- Вставка данных в таблицу Address
INSERT INTO Address (AddressInfo) VALUES (ROW('10', 1));  -- Уолл-стрит, дом 10
INSERT INTO Address (AddressInfo) VALUES (ROW('100', 2)); -- Бродвей, дом 100
INSERT INTO Address (AddressInfo) VALUES (ROW('50', 3));  -- Оксфорд-стрит, дом 50
INSERT INTO Address (AddressInfo) VALUES (ROW('20', 4));  -- Шанз-Элизе, дом 20

-- Вставка данных в таблицу TypeSight
INSERT INTO TypeSight (TypeSightName) VALUES ('Музей');
INSERT INTO TypeSight (TypeSightName) VALUES ('Театр');
INSERT INTO TypeSight (TypeSightName) VALUES ('Галерея');

-- Вставка данных в таблицу Museum
INSERT INTO Museum (NameSight, CreateDate, IDAddress, IDTypeSight, Exhibition)
VALUES ('Метрополитен-музей', '1880 г.', 1, 1, 'Выставка американского искусства');

-- Вставка данных в таблицу Theater
INSERT INTO Theater (NameSight, CreateDate, IDAddress, IDTypeSight, Director)
VALUES ('Бродвейский театр', '1900 г.', 2, 2, 'Джон Смит');

-- Вставка данных в таблицу Sight (для примера)
INSERT INTO Sight (NameSight, CreateDate, IDAddress, IDTypeSight)
VALUES ('Лувр', '1793 г.', 3, 1);

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------

-- выборка с условием
-- Выборка всех музеев и театров с их адресами
SELECT
    S.NameSight AS SightName,
    S.CreateDate AS CreateDate,
    A.AddressInfo AS Address,
    TS.TypeSightName AS Type
FROM
    Sight S
JOIN
    Address A ON S.IDAddress = A.IDAddress
JOIN
    TypeSight TS ON S.IDTypeSight = TS.IDTypeSight;

--------------------------------------------------------------------------------

-- запрос выборки предку
-- Выборка всех объектов Sight
SELECT
    IDSight,
    NameSight,
    CreateDate
FROM
    Sight;

--------------------------------------------------------------------------------

SELECT
    T.IDSight,
    T.NameSight,
    T.CreateDate,
    NULL AS Exhibition,  -- Для театров выставка не применима
    T.Director,
    'Theater' AS Type    -- Указываем тип как 'Theater'
FROM
    Theater T;

--------------------------------------------------------------------------------

-- Запрос выборки только к предку (Sight)
-- Выборка всех объектов Sight
SELECT
    IDSight,
    NameSight,
    CreateDate
FROM
    Sight;

--------------------------------------------------------------------------------

-- Запрос выборки только к потомку (Museum)
-- Выборка всех музеев
SELECT
    M.IDSight,
    M.NameSight,
    M.CreateDate,
    M.Exhibition
FROM
    Museum M;

--------------------------------------------------------------------------------

-- оператор для сравнения названий достопримечательностей.

-- Создание пользовательского оператора

CREATE OR REPLACE FUNCTION sight_name_compare(a VARCHAR, b VARCHAR) RETURNS BOOLEAN AS $$
BEGIN
    RETURN a = b;
END;
$$ LANGUAGE plpgsql;

CREATE OPERATOR <=> (
    LEFTARG = VARCHAR,
    RIGHTARG = VARCHAR,
    PROCEDURE = sight_name_compare
);

SELECT * ,sight.NameSight <=> 'Лувр' from sight

--------------------------------------------------------------------------------

-- Создание пользовательской агрегатной функции
CREATE AGGREGATE COUNT_AND_LIST_MUSEUMS (
    SFUNC = count_and_list_museums_sfunc,
    STYPE = TEXT,
    INITCOND = ''
);

CREATE OR REPLACE FUNCTION count_and_list_museums_sfunc(state TEXT, sight_name VARCHAR) RETURNS TEXT AS $$
BEGIN
    IF state = '' THEN
        RETURN sight_name;  -- Если это первый элемент, просто возвращаем его
    ELSE
        RETURN state || ', ' || sight_name;  -- Иначе добавляем к существующему состоянию
    END IF;
END;
$$ LANGUAGE plpgsql;

-- Создание функции для подсчета количества музеев

-- Пример использования агрегатной функции
SELECT COUNT_AND_LIST_MUSEUMS(NameSight) AS MuseumsList FROM Museum;

--------------------------------------------------------------------------------
