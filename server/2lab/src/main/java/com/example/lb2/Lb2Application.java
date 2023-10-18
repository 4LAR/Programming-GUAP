package com.example.lb2;

import com.example.lb2.dto.Fridge;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.io.*;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

@SpringBootApplication
public class Lb2Application {

  public static void main(String[] args) {
    SpringApplication.run(Lb2Application.class, args);
  }

  public static void add(String name, String recept) {
    if (name != null && !name.isEmpty() && recept != null && !recept.isEmpty()) {
      try {
        name = name + "\n";
        recept = recept + "\n";
        Files.write(Paths.get("base.txt"), name.getBytes(),StandardOpenOption.APPEND);
        Files.write(Paths.get("base.txt"), recept.getBytes(), StandardOpenOption.APPEND);
      }
      catch (IOException e) {
        System.out.println(e);
      }
    }
  }

  public static Map<String, String> get() {
    int id = 0;
    Map<String, String> result = new HashMap<String, String>();

    try {
      File file = new File("base.txt");
      FileReader fr = new FileReader(file);
      BufferedReader reader = new BufferedReader(fr);
      String line = reader.readLine();
      String recept;
      while (line != null) {
        recept = reader.readLine();
        result.put(line, recept);

        line = reader.readLine();
        id++;
      }
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }

    return result;
  }

  public static Boolean remove(String find_name) throws Exception {
    System.out.println(find_name);
    File sourceFile = new File("base.txt");
    File outputFile = new File("base_buff.txt");
    boolean result = false;
    BufferedReader reader = new BufferedReader(new FileReader(sourceFile));
    BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
    String line = "";
    boolean find = false;
    while ((line = reader.readLine()) != null) {
      if (find) {
        find = false;
      } else {
        if (!line.contains(find_name)) {
          writer.write(line);
          writer.newLine();
        } else {
          find = true;
          result = true;
        }
      }

    }

    reader.close();
    writer.close();
    sourceFile.delete();
    outputFile.renameTo(sourceFile);

    return result;
  }

}
