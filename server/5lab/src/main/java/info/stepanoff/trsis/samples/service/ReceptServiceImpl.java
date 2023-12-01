package info.stepanoff.trsis.samples.service;


import info.stepanoff.trsis.samples.db.dao.ReceptRepository;
import info.stepanoff.trsis.samples.db.model.Recept;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import lombok.extern.slf4j.Slf4j;


@Slf4j
@Service
public class ReceptServiceImpl implements ReceptService {

    @Autowired
    private ReceptRepository receptRepository;

    @Override
    public Iterable<Recept> listAll() {
        return receptRepository.findAll();
    }

    @Override
    public void delete(Integer id) {
        receptRepository.deleteById(id);
    }

    @Override
    public Recept add(int _quantity, String name, String _recept) {
        return receptRepository.save(new Recept(_quantity, name, _recept));
    }

    @Override
    public Recept findBy_name(String name) {
        return receptRepository.findByname(name);
    }

}
