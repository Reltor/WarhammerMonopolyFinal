/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

/**
 *
 * @author jlelacheur338
 */
public class BattleMech {
    
    public BattleMech()
    {
        this.name = "bob";
        this.tonnage = 1000;
        this.className = "bob";
        this.era = 20102;
    }
    public BattleMech(String name, int tonnage, String className, int era)
    {
        this.name = name;
        this.tonnage = tonnage;
        this.className = className;
        this.era = era;
    }
    
    private String name; 
    private int tonnage;
    private String className;
    private int era;
}
