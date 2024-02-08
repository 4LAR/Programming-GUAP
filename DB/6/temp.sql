--1
--город, в котором нет памятников, но архитектурные комплексы 

select * from City 
join Street on City.IDCity = Street.IDCity
join Addres on Addres.IDStreet = Street.IDStreet
join Sight on Sight.IDAdress = addres.idadress
join typesight on typesight.idtypesight = sight.idtypesight
where sight.namesight = 'Архитектурный комплекс'
except
select * from City 
join Street on City.IDCity = Street.IDCity
join Addres on Addres.IDStreet = Street.IDStreet
join Sight on Sight.IDAdress = addres.idadress
join typesight on typesight.idtypesight = sight.idtypesight
where sight.namesight = 'Памятник'
;

--2
--город, в котором нет памятников, но архитектурные комплексы 

select * from City 
join Street on City.IDCity = Street.IDCity
join Addres on Addres.IDStreet = Street.IDStreet
join Sight on Sight.IDAdress = addres.idadress
join typesight on typesight.idtypesight = sight.idtypesight
where sight.namesight = 'Архитектурный комплекс'
and City.idcity not in(
select City.idcity  from City 
join Street on City.IDCity = Street.IDCity
join Addres on Addres.IDStreet = Street.IDStreet
join Sight on Sight.IDAdress = addres.idadress
join typesight on typesight.idtypesight = sight.idtypesight
where sight.namesight = 'Памятник'
)
;

--3
--город, в котором нет памятников, но архитектурные комплексы 

select * from City 
join Street on City.IDCity = Street.IDCity
join Addres on Addres.IDStreet = Street.IDStreet
join Sight on Sight.IDAdress = addres.idadress
join typesight on typesight.idtypesight = sight.idtypesight
where sight.namesight = 'Архитектурный комплекс'
and not exists(
select *  from City as c2
join Street on City.IDCity = Street.IDCity
join Addres on Addres.IDStreet = Street.IDStreet
join Sight on Sight.IDAdress = addres.idadress
join typesight on typesight.idtypesight = sight.idtypesight
where sight.namesight = 'Памятник' and c2.NameCity=City.NameCity
)
;

--4
--город, в котором нет памятников, но архитектурные комплексы 

select IDCity from City 
join Street on City.IDCity = Street.IDCity
join Addres on Addres.IDStreet = Street.IDStreet
join Sight on Sight.IDAdress = addres.idadress
join typesight on typesight.idtypesight = sight.idtypesight
left join(
select *  from City2 as c2
join Street on c2.IDCity2 = Street.IDCity
join Addres on Addres.IDStreet = Street.IDStreet
join Sight on Sight.IDAdress = addres.idadress
join typesight on typesight.idtypesight = sight.idtypesight
where sight.namesight= 'Памятник') as c2
on City.idcity = c2.idcity2
where sight.namesight = 'Архитектурный комплекс'
and c2.idcity is NULL
;

 --улица, на которой музеев больше среднего 
SELECT s.IDStreet, s.StrretName, COUNT(distinct si.IDSight) as MuseumsCount
FROM Street s
JOIN Addres a ON s.IDStreet = a.IDStreet
JOIN Sight si ON a.IDAdress = si.IDAdress
GROUP BY s.IDStreet, s.StrretName
HAVING COUNT(distinct si.IDSight) > (SELECT AVG(MuseumsCount) FROM 
(SELECT COUNT(distinct si.IDSight) as MuseumsCount
FROM Street s
JOIN Addres a ON s.IDStreet = a.IDStreet
JOIN Sight si ON a.IDAdress = si.IDAdress
GROUP BY s.IDStreet, s.StrretName) as MuseumCounts);

--улица с самыми старыми достопримечательностями 
SELECT s.IDStreet, s.StrretName, MIN(si.CreateDate) as OldestSightDate
FROM Street s
JOIN Addres a ON s.IDStreet = a.IDStreet
JOIN Sight si ON a.IDAdress = si.IDAdress
GROUP BY s.IDStreet, s.StrretName
ORDER BY OldestSightDate
LIMIT 1;
--улица с самыми старыми достопримечательностями 
SELECT Street.StrretName
FROM Street 
JOIN Addres ON Addres.IDStreet = Street.IDStreet 
LEFT JOIN Sight ON Sight.IDAdress = Addres.IDAdress
GROUP BY Street.StrretName
HAVING MIN(Sight.CreateDate) <= ALL (SELECT Sight.CreateDate FROM Sight WHERE Sight.CreateDate IS NOT NULL)
ORDER BY MAX(Sight.CreateDate) ASC;


--тип достопримечательностей, который есть во всех городах, где есть достопримечательности
SELECT TypeSight.TypeSightName
FROM TypeSight
WHERE EXISTS (
    SELECT DISTINCT City.IDCity
    FROM City
    WHERE EXISTS (
        SELECT Addres.IDAdress
        FROM Addres
        JOIN Sight ON Sight.IDAdress = Addres.IDAdress
        WHERE Sight.IDTypeSight = TypeSight.IDTypeSight
    )
    AND NOT EXISTS (
        SELECT Addres.IDAdress
        FROM Addres
        JOIN City AS OtherCity ON OtherCity.IDCity = City.IDCity
        LEFT JOIN Sight ON Sight.IDAdress = Addres.IDAdress
        WHERE Sight.IDTypeSight = TypeSight.IDTypeSight
        AND OtherCity.IDCity <> City.IDCity
    )
);


-- тип достопримечательностей, который есть во всех городах, где есть достопримечательности
SELECT TypeSight.TypeSightName
FROM TypeSight
WHERE NOT EXISTS (
    SELECT DISTINCT City.IDCity
    FROM City
    WHERE NOT EXISTS (
        SELECT Addres.IDAdress
        FROM Addres
        JOIN Sight ON Sight.IDAdress = Addres.IDAdress
        WHERE Sight.IDTypeSight = TypeSight.IDTypeSight
    )
    AND EXISTS (
        SELECT Addres.IDAdress
        FROM Addres
        JOIN City AS OtherCity ON OtherCity.IDCity = City.IDCity
        LEFT JOIN Sight ON Sight.IDAdress = Addres.IDAdress
        WHERE Sight.IDTypeSight = TypeSight.IDTypeSight
        AND OtherCity.IDCity <> City.IDCity
    )
);

--тип достопримечательностей, который есть во всех городах, где есть достопримечательности
SELECT TypeSight.TypeSightName
FROM TypeSight
WHERE (
    SELECT COUNT(DISTINCT City.IDCity)
    FROM City
    WHERE EXISTS (
        SELECT Addres.IDAdress
        FROM Addres
        JOIN Sight ON Sight.IDAdress = Addres.IDAdress
        WHERE Sight.IDTypeSight = TypeSight.IDTypeSight
    )
) = (
    SELECT COUNT(DISTINCT City.IDCity)
    FROM City
);
