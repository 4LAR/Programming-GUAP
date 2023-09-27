package com.mycompany.lab1.servlets;

import com.mycompany.lab1.base.base;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.io.*;

@WebServlet(name = "DeleteCreateServlet", urlPatterns = {"/manage"})
public class DeleteCreateServlet extends HttpServlet {

  protected void processRequest(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {

    String find_name = request.getParameter("name");

    response.setContentType("text/html;charset=UTF-8");
    try (PrintWriter out = response.getWriter()) {
      out.println("<!DOCTYPE html>");
      out.println("<html>");
      out.println("<head>");
      out.println("<style>");
      out.println("tr, th {border: 1px solid #000000}");
      out.println("</style>");
      out.println("</head>");
      out.println("<body>");
      out.println("<h1>Результаты поиска</h1>");
      out.println("<table>");
      out.println("<tr>");
      out.println("<th><p>Блюдо</p></th>");
      out.println("<th><p>Рецепт</p></th>");
      out.println("</tr>");

      if (find_name != null && !find_name.isEmpty()) {
        File file = new File("base.txt");
        FileReader fr = new FileReader(file);
        BufferedReader reader = new BufferedReader(fr);
        String line = reader.readLine();
        String recept = "";
        while (line != null) {
          recept = reader.readLine();

          if (line.contains(find_name)) {
            out.println("<tr>");
            out.println("<th><p>");
            out.println(line);
            out.println("</p></th>");
            out.println("<th><p>");
            out.println(recept);
            out.println("</p></th>");
            out.println("</tr>");
          }
          line = reader.readLine();
        }

      } else {
        out.println("<h1>Пустой запрос</h1>");
      }
      out.println("</table>");
      out.println("</body>");
      out.println("</html>");
    }
  }

  @Override
  protected void doGet(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {
    processRequest(request, response);
  }

  @Override
  protected void doPost(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {

    File sourceFile = new File("base.txt");
    File outputFile = new File("base_buff.txt");

    String find_name = request.getParameter("name");

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
        }
      }

    }

    reader.close();
    writer.close();
    sourceFile.delete();
    outputFile.renameTo(sourceFile);

    response.sendRedirect(request.getContextPath() + "/list");

  }

}
