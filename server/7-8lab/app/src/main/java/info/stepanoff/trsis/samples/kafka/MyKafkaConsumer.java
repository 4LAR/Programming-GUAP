package info.stepanoff.trsis.samples.kafka;

import com.fasterxml.jackson.databind.ObjectMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Profile;
import org.springframework.kafka.annotation.KafkaListener;
import org.springframework.stereotype.Service;
import info.stepanoff.trsis.samples.db.dao.ReceptRepository;
import info.stepanoff.trsis.samples.db.model.Recept;

@Service
// @Profile("consumer")
public class MyKafkaConsumer {
    private final ReceptRepository repository;
    private final ObjectMapper objectMapper = new ObjectMapper();

    @Autowired
    public MyKafkaConsumer(ReceptRepository repository) {
        this.repository = repository;
        System.out.println("MyKafkaConsumer");
    }
    @KafkaListener(topics = "myTopic")
    public void listen(String message) {
        System.out.println(message);
        Recept itemObj = convertMessageToItemObj(message);
        repository.save(itemObj);
    }
    private Recept convertMessageToItemObj(String message) {
        try {
            return objectMapper.readValue(message, Recept.class);
        } catch (Exception e) {
            throw new RuntimeException("Ошибка при преобразовании сообщения", e);
        }
    }
}
