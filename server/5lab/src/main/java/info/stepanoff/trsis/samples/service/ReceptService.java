package info.stepanoff.trsis.samples.service;

import info.stepanoff.trsis.samples.db.model.Recept;

public interface ReceptService {

    Iterable<Recept> listAll();

    void delete(Integer id);

    //void delete(String id);

    Recept add(int _quantity, String name, String _recept);

    Recept findBy_name(String _name);

}
