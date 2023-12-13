package info.stepanoff.trsis.samples.service;

import com.fasterxml.jackson.databind.ObjectMapper;
import info.stepanoff.trsis.samples.db.dao.ReceptRepository;
import info.stepanoff.trsis.samples.kafka.MyKafkaProducer;
import info.stepanoff.trsis.samples.kafka.MyKafkaConsumer;
import info.stepanoff.trsis.samples.db.model.Recept;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import lombok.extern.slf4j.Slf4j;


@Slf4j
@Service
public class ReceptServiceImpl implements ReceptService {

    private final MyKafkaProducer myKafkaProducer;
    private final MyKafkaConsumer myKafkaConsumer;
    private final ObjectMapper objectMapper = new ObjectMapper();

    @Autowired
    private ReceptRepository receptRepository;

    @Autowired(required = false)
    public ReceptServiceImpl(MyKafkaProducer myKafkaProducer, MyKafkaConsumer myKafkaConsumer) {
        this.myKafkaProducer = myKafkaProducer;
        this.myKafkaConsumer = myKafkaConsumer;
    }

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
        Recept recept_buf = new Recept(_quantity, name, _recept);
        if (myKafkaProducer != null) {
            String message = convertPatientToMessage(recept_buf);
            myKafkaProducer.sendMessage("myTopic", String.valueOf(recept_buf.getId()), message);
        }
        return receptRepository.save(recept_buf);
    }

    @Override
    public Recept findBy_name(String name) {
        return receptRepository.findByname(name);
    }

    private String convertPatientToMessage(Recept recept) {
        try {
            return objectMapper.writeValueAsString(recept);
        } catch (Exception e) {
            throw new RuntimeException("Ошибка при преобразовании пациента в сообщение", e);
        }
    }

}
