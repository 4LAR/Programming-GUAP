
--
-- а. достопримечательности, в которых есть слово «Дворец», но с него название не начинается
-- б. город без улиц
-- в. улица, на которой есть и памятники, и музеи
-- г. город, в котором нет памятников, но архитектурные комплексы
-- д. улица, на которой музеев больше среднего
-- е. улица с самыми старыми достопримечательностями
-- ж. тип достопримечательностей, который есть во всех городах, где есть достопримечательности

-- СПБ https://www.tripadvisor.ru/Attractions-g298507-Activities-St_Petersburg_Northwestern_District.html
INSERT INTO City (IDCity, NameCity) VALUES (1, 'Санкт Петербург');

INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (1, 1, 'Театральная площадь');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (2, 1, 'Набережная реки Фонтанки');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (3, 1, 'Дворцовый проспект');

INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (1, '1', 1);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (2, '21 Шуваловский дворец', 2);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (3, 'д. 48, лит А', 3);

INSERT INTO TypeSight (IDTypeSight, TypeSightName) VALUES (1, 'Музей');
INSERT INTO TypeSight (IDTypeSight, TypeSightName) VALUES (2, 'театр');

INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (1, 'Музей Фаберже', '2013 г.', 2, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (2, 'Музей-заповедник "Ораниенбаум"', '1711 г.', 3, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (3, 'Мариинский театр', '2 октября 1860 г.', 1, 2);

-- МСК https://www.tripadvisor.ru/Attractions-g298484-Activities-Moscow_Central_Russia.html
INSERT INTO City (IDCity, NameCity) VALUES (2, 'Москва');

INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (4, 2, 'Дольская улица');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (5, 2, 'Андропова проспект');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (6, 2, 'Театральная пл');

INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (4, 'д. 1', 4);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (5, '39', 5);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (6, '1', 6);

INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (4, 'Царицыно Музей-Заповедник', '1984 г', 4, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (5, 'Московский Государственный Объединенный Музей-Заповедник "Коломенское"', '2005 г', 5, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (6, 'Большой театр', '28 марта 1776 года', 6, 2);

-- ИЖЕВСК https://www.tripadvisor.ru/Attractions-g673777-Activities-Izhevsk_Udmurt_Republic_Volga_District.html

INSERT INTO City (IDCity, NameCity) VALUES (3, 'Ижевск');

INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (7, 3, 'ул. Бородина');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (8, 3, 'ул. Карла Маркса');
INSERT INTO Street (IDStreet, IDCity, StrretName) VALUES (9, 3, 'Коммунаров улица');

INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (7, 'д. 19', 7);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (8, '222', 8);
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (9, '287', 9);

INSERT INTO TypeSight (IDTypeSight, TypeSightName) VALUES (3, 'Памятник');

INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (7, 'Музейно-выставочный комплекс стрелкового оружия им. М.Т. Калашникова', '2004 г', 7, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (8, 'Памятник благоверным Петру и Февронии Муромским', '2008 г', 8, 3);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (9, 'Национальный Музей Удмуртской Республики', '1920 г', 9, 1);

-- для условий

INSERT INTO City (IDCity, NameCity) VALUES (4, 'Пустырь');
INSERT INTO City (IDCity, NameCity) VALUES (5, 'Поле');
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (10, 'Музей веселья', '2077', 8, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (11, 'какой-то памятник', '2999 г.', 2, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (12, 'какой-то дворец', '3333 г.', 2, 1);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (13, 'Архитектурный комплекс', '1389', 1, 2);
INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (14, 'Музей страданий', '2077', 8, 1);

--

UPDATE Sight SET IDSight = IDSight * 10;
DELETE FROM Sight WHERE IDSight % 2 = 0;

--
MERGE INTO Sight AS TARGET
USING Sight2 AS SOURCE
ON TARGET.IDSight=SOURCE.IDSight
WHEN MATCHED THEN
	UPDATE SET IDSight=SOURCE.IDSight, NameSight=SOURCE.NameSight, CreateDate=SOURCE.CreateDate, IDAdress=SOURCE.IDAdress, IDTypeSight=SOURCE.IDTypeSight
WHEN NOT MATCHED THEN
 	INSERT (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight)
	VALUES (SOURCE.IDSight, SOURCE.NameSight, SOURCE.CreateDate, SOURCE.IDAdress, SOURCE.IDTypeSight)

-- не работают
UPDATE Sight SET IDSight = IDSight + 1;
INSERT INTO Addres (IDAdress, House, IDStreet) VALUES (1, '1');
INSERT INTO City (IDCity, NameCity) VALUES (1, NULL);
