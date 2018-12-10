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
    
    
    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return the tonnage
     */
    public int getTonnage() {
        return tonnage;
    }

    /**
     * @param tonnage the tonnage to set
     */
    public void setTonnage(int tonnage) {
        this.tonnage = tonnage;
    }

    /**
     * @return the className
     */
    public String getClassName() {
        return className;
    }

    /**
     * @param className the className to set
     */
    public void setClassName(String className) {
        this.className = className;
    }

    /**
     * @return the era
     */
    public int getEra() {
        return era;
    }

    /**
     * @param era the era to set
     */
    public void setEra(int era) {
        this.era = era;
    }
    
   
    
    private String name; 
    private int tonnage;
    private String className;
    private int era;
}
