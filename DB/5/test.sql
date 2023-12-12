-- достопримечательности, в которых есть слово «Дворец», но с него название не начинается
select sight.namesight from sight
where sight.namesight like '%_дворец%';

-- город без улиц
select city.IDCity from city
left join Street on city.IDCity = Street.IDCity
where IDStreet is null;

-- улица, на которой есть и памятники, и музеи
SELECT s.StrretName
FROM Street s
JOIN Addres a ON s.IDStreet = a.IDStreet
JOIN Sight l ON a.IDAdress = l.IDAdress
JOIN TypeSight lt ON l.IDTypeSight = lt.IDTypeSight
WHERE lt.TypeSightName IN ('Памятник', 'Музей')
GROUP BY s.StrretName
HAVING COUNT(DISTINCT lt.TypeSightName) = 2;
-----
SELECT DISTINCT s.StrretName
FROM Street s
JOIN Addres a ON s.IDStreet = a.IDStreet
JOIN Sight l1 ON a.IDAdress = l1.IDAdress
JOIN TypeSight lt1 ON l1.IDTypeSight = lt1.IDTypeSight
JOIN Sight l2 ON a.IDAdress = l2.IDAdress
JOIN TypeSight lt2 ON l2.IDTypeSight = lt2.IDTypeSight
WHERE lt1.TypeSightName = 'Памятник'
AND lt2.TypeSightName = 'Музей';





























-- город без улиц (right join)
select city.IDCity from Street
right join city on city.IDCity = Street.IDCity
where IDStreet is null;
