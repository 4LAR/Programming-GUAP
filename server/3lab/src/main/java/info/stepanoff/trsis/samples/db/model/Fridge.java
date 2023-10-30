package info.stepanoff.trsis.samples.db.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.*;
import java.io.Serializable;
import java.util.List;
import java.util.Map;

@Entity
@Table(name = "FRIDGE")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class Fridge implements Serializable {
    private static final long serialVersionUID = 1L;

    @Id
    @Column(name = "FRIDGE_ID")
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;


    @OneToMany(targetEntity = Batch.class, mappedBy = "Fridge", fetch = FetchType.LAZY)
    private List<Batch> batchesList;
    @Column(name = "FRIDGE_QUANTITY", unique = true)
    private int quantity;

    @Column(name = "FRIDGE_NAME")
    private String name;

    @Column(name = "FRIDGE_EXPIRATION_DATE")
    private String expiration_date;

    public Fridge(int _quantity, String name, String _expiration_date){
        quantity =_quantity;
        this.name = name;
        expiration_date = _expiration_date;
    }

    // public Fridge(int _quantity, String name){
    //     quantity =_quantity;
    //     this.name = name;
    // }

}
