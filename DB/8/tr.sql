-- счетчик улиц в городах
ALTER TABLE city
add count_street int default 0;

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
