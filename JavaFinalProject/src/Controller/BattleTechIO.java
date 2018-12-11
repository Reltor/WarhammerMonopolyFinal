/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
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
        ArrayList<BattleMech> bmList = new ArrayList<BattleMech>();
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
        for (int i = 0;i < list.size()-1; i++)
        {
            String r = list.get(i);
            String mech[] = (r.split(","));
            String name = mech[0];
            int ton = Integer.parseInt(mech[1]);
            String type = mech[2];
            int era = Integer.parseInt(mech[3]);
            BattleMech bm = new BattleMech(name,ton,type,era);
            bmList.add(bm);
        }
        return bmList;
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

            for (int i = 0;i < list.size()-1; i++)
            {
                String r = list.get(i);
                String mech[] = (r.split(","));
                if (mech[0].equals(mechName))
                {
                    String name = mech[0];
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
    
    public static void deleteLine(String dName)
    {
        Path fp = Paths.get("MechDB.txt");
        File readFile = fp.toFile();
        ArrayList<String> list = new ArrayList<String>();
        ArrayList<BattleMech> bmList = new ArrayList<BattleMech>();
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
        for (int i = 0;i < list.size()-1; i++)
        {
            String r = list.get(i);
            String mech[] = (r.split(","));
            String name = mech[0];
            int ton = Integer.parseInt(mech[1]);
            String type = mech[2];
            int era = Integer.parseInt(mech[3]);
            BattleMech bm = new BattleMech(name,ton,type,era);
            if (bm.getName().equals(dName))
            {
                
            }
            else
            {
                bmList.add(bm);
            }
        }
        Path fPath = Paths.get("MechDB.txt");
        File outFile = fPath.toFile();
        try 
        {
            PrintWriter w = new PrintWriter(
                            new BufferedWriter(
                            new FileWriter(outFile)));
            
            for (int i = 0; i < bmList.size();i++)
            {
                String line = (bmList.get(i).getName() + "," + bmList.get(i).getTonnage()+ "," + bmList.get(i).getClassName() + "," + bmList.get(i).getEra());
                w.println(line);
            }
            w.close();
            
        }
        catch (FileNotFoundException ex) 
        {
            Logger.getLogger(BattleTechIO.class.getName()).log(Level.SEVERE, null, ex);
        }   
        catch (IOException ex) 
        {
            Logger.getLogger(BattleTechIO.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void wipeFile()
    {
        
    }
    
    public static void editLine(BattleMech b)
    {
        Path fp = Paths.get("MechDB.txt");
        File readFile = fp.toFile();
        ArrayList<String> list = new ArrayList<String>();
        ArrayList<BattleMech> bmList = new ArrayList<BattleMech>();
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
        for (int i = 0;i < list.size()-1; i++)
        {
            String r = list.get(i);
            String mech[] = (r.split(","));
            String name = mech[0];
            int ton = Integer.parseInt(mech[1]);
            String type = mech[2];
            int era = Integer.parseInt(mech[3]);
            BattleMech bm = new BattleMech(name,ton,type,era);
            if (bm.getName().equals(b.getName()))
            {
                bmList.add(b);
            }
            else
            {
                bmList.add(bm);
            }
        }
        Path fPath = Paths.get("MechDB.txt");
        File outFile = fPath.toFile();
        try 
        {
            PrintWriter w = new PrintWriter(
                            new BufferedWriter(
                            new FileWriter(outFile)));
            
            for (int i = 0; i < bmList.size();i++)
            {
                String line = (bmList.get(i).getName() + "," + bmList.get(i).getTonnage()+ "," + bmList.get(i).getClassName() + "," + bmList.get(i).getEra());
                w.println(line);
            }
            w.close();
            
        }
        catch (FileNotFoundException ex) 
        {
            Logger.getLogger(BattleTechIO.class.getName()).log(Level.SEVERE, null, ex);
        }   
        catch (IOException ex) 
        {
            Logger.getLogger(BattleTechIO.class.getName()).log(Level.SEVERE, null, ex);
        }
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
      public static void add(BattleMech bm)
    {
        Path fp = Paths.get("MechDB.txt");
        File readFile = fp.toFile();
        ArrayList<String> list = new ArrayList<String>();
        ArrayList<BattleMech> bmList = new ArrayList<BattleMech>();
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
        for (int i = 0;i < list.size()-1; i++)
        {
            String r = list.get(i);
            String mech[] = (r.split(","));
            String name = mech[0];
            int ton = Integer.parseInt(mech[1]);
            String type = mech[2];
            int era = Integer.parseInt(mech[3]);
            BattleMech bml = new BattleMech(name,ton,type,era);
            bmList.add(bml);
        }
        bmList.add(bm);
        Path fPath = Paths.get("MechDB.txt");
        File outFile = fPath.toFile();
        try 
        {
            PrintWriter w = new PrintWriter(
                            new BufferedWriter(
                            new FileWriter(outFile)));
            
            for (int i = 0; i < bmList.size();i++)
            {
                String line = (bmList.get(i).getName() + "," + bmList.get(i).getTonnage()+ "," + bmList.get(i).getClassName() + "," + bmList.get(i).getEra());
                w.println(line);
            }
            w.close();
            
        }
        catch (FileNotFoundException ex) 
        {
            Logger.getLogger(BattleTechIO.class.getName()).log(Level.SEVERE, null, ex);
        }   
        catch (IOException ex) 
        {
            Logger.getLogger(BattleTechIO.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}