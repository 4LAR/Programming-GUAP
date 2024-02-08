
-- вставка улицы по городу если нет города вставка города
CREATE OR REPLACE FUNCTION ins_street (_NameCity varchar(50),_StrretName varchar(225))
RETURNS VOID AS $$
declare
new_id_city int;
new_id_street int;
BEGIN
if not exists(select * from city where NameCity = _NameCity)
	then begin
		select COALESCE(max(IDCity) + 1,0) into new_id_city from city;
		insert into city (IDCity,NameCity) values (new_id_city,_NameCity);
	end;
		else select IDCity into new_id_city from city where NameCity = _NameCity;
	end if;
		select COALESCE(max(IDStreet) + 1,0) into new_id_street from street;
insert into street (IDStreet,IDCity,StrretName) values (new_id_street,new_id_city,_StrretName);
END;
$$ LANGUAGE plpgsql;

DROP FUNCTION ins_street;

select ins_street('123','StrretName');
-- удаление sight и type sight если на него больше не чего не указывает

CREATE OR REPLACE FUNCTION del_sight_clear_typesight(IDSight_del  int)
RETURNS VOID AS $$
declare
IDTypeSight_del int;
begin
select IDTypeSight into IDTypeSight_del from Sight where IDSight = IDSight_del;
delete from Sight where IDSight = IDSight_del;
if not exists(select * from Sight where IDTypeSight = IDTypeSight_del)
	then delete from TypeSight where IDTypeSight = IDTypeSight_del;
end if;
END;
$$ LANGUAGE plpgsql;

call del_sight_clear_typesight(8);
call del_sight_clear_typesight(11);

-- каскадное удаление
-- удаление адреса и всех sight которые на него указывют
CREATE OR REPLACE FUNCTION del_addres_cascade(IDAdress_del int)
RETURNS VOID AS $$
begin
delete from Sight where IDAdress = IDAdress_del;
delete from addres where IDAdress = IDAdress_del;
end;
$$ LANGUAGE plpgsql;

call del_addres_cascade(8);

-- возврат количество городов
CREATE OR REPLACE FUNCTION count_city_fun()
RETURNS INT AS $$
declare
	val int default 0;
begin
	select COALESCE(count(IDCity),0) into val from city;
	return val;
end;
$$ LANGUAGE plpgsql;

select count_city_fun();

-- формирование статистики во временной таблице


CREATE OR REPLACE FUNCTION city_statistics ()
RETURNS TABLE (
	id_stat int,
	IDCity  int,
	count_street int,
	count_addres int
) as $$
begin
create temporary table if not exists city_stat
(
	id_stat serial primary key,
	IDCity  int,
	count_street int,
	count_addres int
);
insert into city_stat(IDCity,count_addres,count_street)
select City.IDCity, count(IDAdress) as  count_addres,count(street.IDStreet) as count_street from City
left join street on street.IDCity = City.IDCity
left join addres on addres.IDStreet = street.IDStreet
group by City.IDCity;
RETURN QUERY SELECT * FROM city_stat;
drop table city_stat;
end;
$$ LANGUAGE plpgsql;

DROP FUNCTION city_statistics;

select * from city_statistics();
