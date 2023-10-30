package info.stepanoff.trsis.samples.db.dao;

import info.stepanoff.trsis.samples.db.model.Fridge;
import org.springframework.data.repository.CrudRepository;

/**
 *
 * @author Pavel
 */
public interface FridgeRepository extends CrudRepository<Fridge, Integer> {

     public Fridge findByname(String name);
}
