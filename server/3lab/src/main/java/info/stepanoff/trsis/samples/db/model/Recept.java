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
    @Column(name = "RECEPT_DIFICULTY", unique = true)
    private int dificulty;

    @Column(name = "RECEPT_NAME")
    private String name;

    @Column(name = "RECEPT_BODY")
    private String body;

    public Recept(int _dificulty, String name, String _body){
        dificulty =_dificulty;
        this.name = name;
        body = _body;
    }

}
