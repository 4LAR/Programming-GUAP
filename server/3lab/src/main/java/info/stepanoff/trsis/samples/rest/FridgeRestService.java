package info.stepanoff.trsis.samples.rest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import info.stepanoff.trsis.samples.service.FridgeService;
import lombok.extern.slf4j.Slf4j;

@Slf4j
@RestController
@RequestMapping("/public/rest/Fridge")
public class FridgeRestService {

    @Autowired
    private FridgeService fridgeService;

    @RequestMapping(value = "", method = RequestMethod.GET)
    public ResponseEntity<Object> browse() {
        return ResponseEntity.ok(fridgeService.listAll());
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public void delete(@PathVariable("id") Integer id) {
        fridgeService.delete(id);
    }

    @RequestMapping(value = "/{_quantity}/{name}/{_expiration_date}", method = RequestMethod.POST)
    public ResponseEntity<Object> add(
            @PathVariable("_quantity") int _quantity,
            @PathVariable("name") String name,
            @PathVariable("_expiration_date") String _expiration_date) {
        return ResponseEntity.ok(fridgeService.add(_quantity, name, _expiration_date));
    }
    //int _quantity, String _name, String _expiration_date
    @RequestMapping(value = "/{name}", method = RequestMethod.GET)
    public ResponseEntity<Object> findBy_name(@PathVariable("name") String name) {
        return ResponseEntity.ok(fridgeService.findBy_name(name));
    }
}
