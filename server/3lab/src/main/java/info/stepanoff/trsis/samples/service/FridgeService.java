package info.stepanoff.trsis.samples.service;

import info.stepanoff.trsis.samples.db.model.Fridge;

public interface FridgeService {

    Iterable<Fridge> listAll();

    void delete(Integer id);

    //void delete(String id);

    Fridge add(int _quantity, String name, String _expiration_date);

    Fridge findBy_name(String _name);

}
