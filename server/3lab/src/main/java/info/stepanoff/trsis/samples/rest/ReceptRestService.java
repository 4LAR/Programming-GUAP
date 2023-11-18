package info.stepanoff.trsis.samples.rest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import info.stepanoff.trsis.samples.service.ReceptService;
import lombok.extern.slf4j.Slf4j;

@Slf4j
@RestController
@RequestMapping("/public/rest/Recept")
public class ReceptRestService {

    @Autowired
    private ReceptService receptService;

    @RequestMapping(value = "", method = RequestMethod.GET)
    public ResponseEntity<Object> browse() {
        return ResponseEntity.ok(receptService.listAll());
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public void delete(@PathVariable("id") Integer id) {
        receptService.delete(id);
    }

    @RequestMapping(value = "/{dificulty}/{name}/{_body}", method = RequestMethod.POST)
    public ResponseEntity<Object> add(
            @PathVariable("dificulty") int _dificulty,
            @PathVariable("name") String name,
            @PathVariable("_body") String _body) {
        return ResponseEntity.ok(receptService.add(_dificulty, name, _body));
    }
    //int _quantity, String _name, String _expiration_date
    @RequestMapping(value = "/{name}", method = RequestMethod.GET)
    public ResponseEntity<Object> findBy_name(@PathVariable("name") String name) {
        return ResponseEntity.ok(receptService.findBy_name(name));
    }
}
