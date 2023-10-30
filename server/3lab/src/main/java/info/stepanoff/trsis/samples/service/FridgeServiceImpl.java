package info.stepanoff.trsis.samples.service;


import info.stepanoff.trsis.samples.db.dao.FridgeRepository;
import info.stepanoff.trsis.samples.db.model.Fridge;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import lombok.extern.slf4j.Slf4j;


@Slf4j
@Service
public class FridgeServiceImpl implements FridgeService {

    @Autowired
    private FridgeRepository fridgeRepository;

    @Override
    public Iterable<Fridge> listAll() {
        return fridgeRepository.findAll();
    }

    @Override
    public void delete(Integer id) {
        fridgeRepository.deleteById(id);
    }

    @Override
    public Fridge add(int _quantity, String name, String _expiration_date) {
        return fridgeRepository.save(new Fridge(_quantity, name, _expiration_date));
    }

    @Override
    public Fridge findBy_name(String name) {
        return fridgeRepository.findByname(name);
    }

}
