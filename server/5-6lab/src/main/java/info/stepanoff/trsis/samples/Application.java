package info.stepanoff.trsis.samples;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;

@ComponentScan
@EnableAutoConfiguration
@EnableWebSecurity
public class Application {
    public static void main(String[] args) throws Exception {
        SpringApplication app = new SpringApplicationBuilder(Application.class).build();
        app.run(args);
    }
}
