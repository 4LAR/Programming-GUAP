package com.example.lb2.controller;

import com.example.lb2.Lb2Application;
import com.example.lb2.dto.Fridge;
import org.apache.coyote.Response;
import org.springframework.http.*;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.client.HttpStatusCodeException;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static java.lang.System.*;
import static org.springframework.http.MediaType.APPLICATION_JSON_VALUE;

@RestController
public class restcontroller {

  @GetMapping(path ="/list",produces = MediaType.APPLICATION_JSON_VALUE)
  public ResponseEntity<Map<String,String>> getMethod(){
      return ResponseEntity.ok(Lb2Application.get());
  }

  @DeleteMapping(path ="/list{name}",produces = MediaType.APPLICATION_JSON_VALUE)
  public ResponseEntity<Map<String,Boolean>> deleteMethod(@PathVariable("name") String name) throws Exception {
    boolean result = Lb2Application.remove(name);
    System.out.println(result);

    if(result){
      Map<String,Boolean> result_ok = new HashMap<String,Boolean>() {{
        put("status", true);
      }};
      return ResponseEntity.ok(result_ok);
    }else{
      Map<String,Boolean> result_fail = new HashMap<String,Boolean>() {{
        put("status", false);
      }};
      return ResponseEntity.ok(result_fail);
    }
  }

  @PostMapping(path ="/list",produces = MediaType.APPLICATION_JSON_VALUE)
  public ResponseEntity<Map<String,Boolean>> PostMethod(@RequestBody Map<String, String> map_data){
    Map<String,Boolean> result = new HashMap<String,Boolean>() {{
      put("status", true);
    }};

    Lb2Application.add(
      map_data.get("name"),
      map_data.get("recept")
    );
    return ResponseEntity.ok(result);
  }
}
