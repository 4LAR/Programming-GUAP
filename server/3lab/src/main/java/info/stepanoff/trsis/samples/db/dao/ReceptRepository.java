package info.stepanoff.trsis.samples.db.dao;

import info.stepanoff.trsis.samples.db.model.Recept;
import org.springframework.data.repository.CrudRepository;

/**
 *
 * @author Pavel
 */
public interface ReceptRepository extends CrudRepository<Recept, Integer> {

     public Recept findByname(String name);
}
