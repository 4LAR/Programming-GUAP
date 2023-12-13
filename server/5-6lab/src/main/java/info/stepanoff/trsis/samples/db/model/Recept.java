package info.stepanoff.trsis.samples.db.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.*;
import java.io.Serializable;
import java.util.List;
import java.util.Map;

@Entity
@Table(name = "RECEPT")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class Recept implements Serializable {
    private static final long serialVersionUID = 1L;

    @Id
    @Column(name = "RECEPT_ID")
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;


    @OneToMany(targetEntity = Batch.class, mappedBy = "Recept", fetch = FetchType.LAZY)
    private List<Batch> batchesList;
    @Column(name = "RECEPT_QUANTITY")
    private int quantity;

    @Column(name = "RECEPT_NAME", unique = true)
    private String name;

    @Column(name = "RECEPT_RECEPT")
    private String recept;

    public Recept(int _quantity, String name, String _recept){
        quantity =_quantity;
        this.name = name;
        recept = _recept;
    }


//    public Recept(int _quantity, String name){
//        quantity =_quantity;
//        this.name = name;
//    }

}
