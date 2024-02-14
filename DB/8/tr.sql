-- счетчик улиц в городах
ALTER TABLE city
add count_street int default 0;

-- прибавляет
CREATE OR REPLACE FUNCTION after_insert_street()
RETURNS TRIGGER AS $$
BEGIN
    UPDATE city
    SET count_street = count_street + 1
    where idcity = new.idcity;
    RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER after_insert_street
after insert ON street
FOR EACH ROW
EXECUTE FUNCTION after_insert_street();

insert into street(idstreet,idcity,strretname) VALUES (503,1,'test');
select count_street from city;

-- уменьшает
CREATE OR REPLACE FUNCTION after_del_street()
RETURNS TRIGGER AS $$
BEGIN
    UPDATE city
    SET count_street = count_street - 1
    where idcity = old.idcity;
    RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER after_del_street
after delete ON street
FOR EACH ROW
EXECUTE FUNCTION after_del_street();

--
CREATE OR REPLACE FUNCTION befor_del_typesight()
RETURNS TRIGGER AS $$
BEGIN
    delete frome sight
  where idtypesight = old.idtypesight;
    RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER befor_del_typesight
before delete ON typesight
FOR EACH ROW
EXECUTE FUNCTION befor_del_typesight();

-- бэкап
CREATE TABLE City_backup (
  id_City_backup int SERIAL  primary key;
    IDCity INT,
    NameCity VARCHAR(50)
);

-- логирование
CREATE OR REPLACE FUNCTION befor_update_City()
RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO City_backup (IDCity,NameCity)
    values (old.IDCity,old.NameCity);
    RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER befor_update_City
before update ON City
FOR EACH ROW
EXECUTE FUNCTION befor_update_City();

--
CREATE OR REPLACE FUNCTION befor_insert_City()
RETURNS TRIGGER AS $$
BEGIN
    if not exists ( select * from invited where new.id_event = id_event and new.id_union = id_union)
  then begin

    RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER befor_insert_City
before insert ON City
FOR EACH ROW
EXECUTE FUNCTION befor_update_City();

-- обновляет счётсчик (если улица перемистится в лругой город)
CREATE OR REPLACE FUNCTION after_update_street()
RETURNS TRIGGER AS $$
BEGIN
    UPDATE city
    SET count_street = count_street + 1
    where idcity = new.idcity;

  UPDATE city
    SET count_street = count_street - 1
    where idcity = old.idcity;
    RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER after_update_street
after update ON street
FOR EACH ROW
EXECUTE FUNCTION after_update_street();

-- проверка на дату
CREATE OR REPLACE FUNCTION befor_insert_sight()
RETURNS TRIGGER AS $$
BEGIN
     if new.createdate > current_date
  then RAISE EXCEPTION 'Условие не удовлетворено. Операция отменена.';
  end if;
    RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER befor_insert_sight
before insert ON sight
FOR EACH ROW
EXECUTE FUNCTION befor_insert_sight();

INSERT INTO Sight (IDSight, NameSight, CreateDate, IDAdress, IDTypeSight) VALUES (100, 'Памятник уныния', '2000-01-01', 8, 1);
