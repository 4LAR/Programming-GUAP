package info.stepanoff.trsis.samples.service;

import info.stepanoff.trsis.samples.db.model.Recept;

public interface ReceptService {

    Iterable<Recept> listAll();

    void delete(Integer id);

    //void delete(String id);

    Recept add(int _dificulty, String name, String _body);

    Recept findBy_name(String _name);

}
