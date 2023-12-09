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
