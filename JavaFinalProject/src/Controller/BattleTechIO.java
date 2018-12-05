/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import java.util.*;
import javax.swing.JTextField;

/**
 *
 * @author jlelacheur338
 */
public class BattleTechIO {
    public static Vector readAll()
    {
        Vector v = new Vector();
        v.addElement(new BattleMech());
        v.addElement(new BattleMech());
        v.addElement(new BattleMech());
        v.addElement(new BattleMech());
        return v;
        
    }
    
    public static BattleMech readLine()
    {
        return new BattleMech();
    }
    
    public static void deleteLine(int index)
    {
        
    }
    
    public static void wipeFile()
    {
        
    }
    
    public static void editLine(BattleMech b)
    {
        
    }
    
    public static void writeAll(Vector v)
    {
        
    }
    
    public static boolean checkInt(JTextField x)
    {
        String input  = x.getText();
        try 
        {
            Integer.parseInt(input);
            return true;
        } 
        catch (NumberFormatException e)
        {
            return false;
        }
    }
}
