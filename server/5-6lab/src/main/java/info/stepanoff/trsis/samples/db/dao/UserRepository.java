package info.stepanoff.trsis.samples.db.dao;

import info.stepanoff.trsis.samples.db.model.User;
import org.springframework.data.repository.CrudRepository;

public interface UserRepository
        extends CrudRepository<User, Integer> {
    User findByLogin(String login);
}
