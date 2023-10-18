package com.example.lb2.dto;

import java.util.Map;

public class Fridge {
    public Fridge(){
        quantity = 0;
        name = null;
        expiration_date = null;
    }
    public int getQuantity() {
        return quantity;
    }

    public String getName() {
        return name;
    }

    public String getExpiration_date() {
        return expiration_date;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setExpiration_date(String expiration_date) {
        this.expiration_date = expiration_date;
    }

    private int quantity;
    private String name;
    private String expiration_date;
    public Fridge(Map<String,String[]> map){
        quantity = Integer.parseInt(map.get("quantity")[0]);
        name = map.get("name")[0];
        expiration_date = map.get("expiration_date")[0];
    }
    public Fridge(int _quantity,String _name,String _expiration_date){
        quantity =_quantity;
        name = _name;
        expiration_date = _expiration_date;
    }
    static public String print_name(){
        return "<th>" + "name" + "</th>" +
                "<th>" + "quantity" + "</th>" +
                "<th>" + "expiration_date" + "</th>";
    }
}