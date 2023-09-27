package com.mycompany.lab1.base;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class base {
  public static void main(String[] args) {
    try {
      File myObj = new File("base.txt");
      Scanner myReader = new Scanner(myObj);
      while (myReader.hasNextLine()) {
        String data = myReader.nextLine();
        System.out.println(data);
      }
      myReader.close();
    } catch (FileNotFoundException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
  }
}
