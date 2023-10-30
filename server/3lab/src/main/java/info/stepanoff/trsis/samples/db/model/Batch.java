package info.stepanoff.trsis.samples.db.model;

import java.io.Serializable;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;
import lombok.Data;

/**
 *
 * @author Pavel
 */
@Entity
@Table(name = "Batch")
@Data
public class Batch implements Serializable {

    public Batch() {
    }

    public Batch(Integer id, String name) {
        this.id = id;
        this.name = name;
    }

    @Id
    @Column(name = "batch_id")
    private Integer id;

    @Column(name = "batch_name")
    private String name;

    @Column(name = "batch_school_id")
    private Integer Fridge;
}
