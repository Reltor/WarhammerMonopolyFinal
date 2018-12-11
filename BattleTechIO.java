/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JTextField;

/**
 *
 * @author jlelacheur338
 */
public class BattleTechIO {
    public static ArrayList readAll()
    {
        Path fp = Paths.get("MechDB.txt");
        File readFile = fp.toFile();
        ArrayList<String> list = new ArrayList<String>();
        try 
        {

            BufferedReader in = new BufferedReader(
                                new FileReader(readFile));
            String line = "";
            while (line != null)
                {
                    int i = 0;
                    String[] result = (line.split("\n"));
                    list.add(i, result[i]);
                    line = in.readLine();
                    i++;
                }
            in.close();
            

        }   
        catch (IOException ex) 
        {
            Logger.getLogger(BattleTechIO.class.getName()).log(Level.SEVERE, null, ex);
        }
        return list;
    }
        
    public static BattleMech readLine(String mechName) throws LineNotFoundException
    {
        Path fp = Paths.get("MechDB.txt");
        File readFile = fp.toFile();
        ArrayList<String> list = new ArrayList<String>();
        try 
        {

            BufferedReader in = new BufferedReader(
                                new FileReader(readFile));
            String line = "";
            while (line != null)
                {
                    int i = 0;
                    String[] result = (line.split("\n"));
                    list.add(i, result[i]);
                    line = in.readLine();
                    i++;
                }
            in.close();

            for (int i = 0;i < list.size(); i++)
            {
                String r = list.get(i);
                String mech[] = (r.split(","));
                if (mech[0].equals(mechName))
                {
                    String name = mech[0];
                    System.out.println(mech[1]);
                    int ton = Integer.parseInt(mech[1]);
                    String type = mech[2];
                    int era = Integer.parseInt(mech[3]);
                    BattleMech bm = new BattleMech(name,ton,type,era);
                    return bm;
                }
            }
        throw new LineNotFoundException();
        }
        catch (IOException ex)
        {
            throw new LineNotFoundException();
        }
        catch (LineNotFoundException ex)
        {
            throw new LineNotFoundException();
        }
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
