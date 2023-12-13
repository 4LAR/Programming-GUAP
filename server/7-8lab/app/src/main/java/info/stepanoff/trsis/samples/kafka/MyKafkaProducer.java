package info.stepanoff.trsis.samples.kafka;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.stereotype.Service;

@Service
public class MyKafkaProducer {
    private final KafkaTemplate<String, String> kafkaTemplate;
    @Autowired
    public MyKafkaProducer(KafkaTemplate<String, String> kafkaTemplate) {
        this.kafkaTemplate = kafkaTemplate;
        System.out.println("MyKafkaProducer");
    }
    public void sendMessage(String topic, String key, String message) {
        System.out.println("SEND KAL");
        System.out.println(message);
        kafkaTemplate.send(topic, key, message);
    }
}
