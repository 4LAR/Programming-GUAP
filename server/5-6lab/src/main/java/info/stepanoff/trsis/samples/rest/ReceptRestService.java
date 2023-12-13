package info.stepanoff.trsis.samples.rest;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiResponse;
import io.swagger.annotations.ApiResponses;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import info.stepanoff.trsis.samples.service.ReceptService;
import lombok.extern.slf4j.Slf4j;

import java.security.Principal;

@Slf4j
@RestController
@RequestMapping("/public/rest/Recept")
@Api(value = "ReceptAPI", description = "API for accessing Recept")
public class ReceptRestService {

    @Autowired
    private ReceptService receptService;

    @RequestMapping(value = "", method = RequestMethod.GET)
    @ApiOperation(value = "View a list of all available recept", response = Iterable.class)
    @ApiResponses(value = {
            @ApiResponse(code = 200, message = "Successfully retrieved list"),
            @ApiResponse(code = 401, message = "You are not authorized to view the resource"),
            @ApiResponse(code = 403, message = "Accessing the resource you were trying to reach is forbidden"),
            @ApiResponse(code = 404, message = "The resource you were trying to reach is not found")
    }
    )
    public ResponseEntity<Object> browse() {
        return ResponseEntity.ok(receptService.listAll());
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    @ApiOperation(value = "Remove a recept by ID", response = Iterable.class)
    @ApiResponses(value = {
            @ApiResponse(code = 200, message = "Successfully removed"),
            @ApiResponse(code = 401, message = "You are not authorized to view the resource"),
            @ApiResponse(code = 403, message = "Accessing the resource you were trying to reach is forbidden"),
            @ApiResponse(code = 404, message = "The resource you were trying to reach is not found")
    }
    )
    public void delete(@PathVariable("id") Integer id, Principal principal) {
        receptService.delete(id);
    }

    @RequestMapping(value = "/{_quantity}/{name}/{_recept}", method = RequestMethod.POST)
    public ResponseEntity<Object> add(
            @PathVariable("_quantity") int _quantity,
            @PathVariable("name") String name,
            @PathVariable("_recept") String _recept) {
        return ResponseEntity.ok(receptService.add(_quantity, name, _recept));
    }
    //int _quantity, String _name, String _recept
    @ApiOperation(value = "Find a recept by name", response = Iterable.class)
    @ApiResponses(value = {
            @ApiResponse(code = 200, message = "Successfully found"),
            @ApiResponse(code = 401, message = "You are not authorized to view the resource"),
            @ApiResponse(code = 403, message = "Accessing the resource you were trying to reach is forbidden"),
            @ApiResponse(code = 404, message = "The resource you were trying to reach is not found")
    }
    )
    @RequestMapping(value = "/{name}", method = RequestMethod.GET)
    public ResponseEntity<Object> findBy_name(@PathVariable("name") String name) {
        return ResponseEntity.ok(receptService.findBy_name(name));
    }
}
