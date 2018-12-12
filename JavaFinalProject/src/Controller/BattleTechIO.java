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
 * @author Jared and Charles
 */
public class BattleTechIO {
    /**
     * This function takes everything from the file and returns it as a list of 
     * mechs to be displayed it in a text box.
     * @return 
     */
    public static ArrayList readAll()
    {
        Path fp = Paths.get("MechDB.txt");                          //get the path to the file
        File readFile = fp.toFile();
        ArrayList<String> list = new ArrayList<String>();           //The first array list to hold what was read
        ArrayList<BattleMech> bmList = new ArrayList<BattleMech>(); //The second array list to hold the mechs that will be sent to the front end
        try 
        {

            BufferedReader in = new BufferedReader(
                                new FileReader(readFile));
            String line = "";                                       //To make sure the first value isn't null
            while (line != null)
                {
                    int i = 0;
                    String[] result = (line.split("\n"));
                    list.add(i, result[i]);                         //Fill the first array list
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
            String r = list.get(i);                                 //Converts each element of the array list "list" into a string
            String mech[] = (r.split(","));                         //Puts the newly created string into a String[] split at the "," so each individual part of the mech is accessible
            String name = mech[0];                                  //The following just names each part of the String[]
            int ton = Integer.parseInt(mech[1]);
            String type = mech[2];
            int era = Integer.parseInt(mech[3]);
            BattleMech bm = new BattleMech(name,ton,type,era);      //Those names values are then used to build a mech
            bmList.add(bm);                                         //That mech is then added to the bm array list
        }
        return bmList;                                              //bm is then sent to the front end
    }
    
/**
 * This function takes a mech's name, reads the database, searches through the
 * database, and returns the mech that was searched for.
 * @param mechName
 * @return
 * @throws LineNotFoundException 
 */
    public static BattleMech readLine(String mechName) throws LineNotFoundException     //This is simmilar to the first function in how it is set up
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
                if (mech[0].equals(mechName))                           //The first value of this String[] should be the mechs name and so it is compared to the searched for mech
                {                                                       //If they are the same, it will build that mech and return it to the front end
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
    /**
     * This function searches for a mech's name similar to the search function 
     * however, this function deletes that mech then rebuilds the database so
     * that there are no empty spaces.
     * @param dName 
     */
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
        for (int i = 0;i < list.size()-1; i++)                          //This for loop looks through the array list build from the database
        {
            String r = list.get(i);
            String mech[] = (r.split(","));
            String name = mech[0];
            int ton = Integer.parseInt(mech[1]);
            String type = mech[2];
            int era = Integer.parseInt(mech[3]);
            BattleMech bm = new BattleMech(name,ton,type,era);
            if (bm.getName().equals(dName))                             //If it finds the designated mech, it simply skips adding it to the array list that will be writen to the database
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
            
            for (int i = 0; i < bmList.size();i++)                  //The new array list is then written to the database so that there are no empty spaces.
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
    /**
     * This function takes the mech that was built in the AddNewFrame and adds
     * it to the database.
     * @param bm 
     */
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
            BattleMech bml = new BattleMech(name,ton,type,era);         //Builds a mech from the new data from AddNewFrame
            bmList.add(bml);                                            //Adds that mech to the bml array list
        }
        bmList.add(bm);
        Path fPath = Paths.get("MechDB.txt");
        File outFile = fPath.toFile();
        try 
        {
            PrintWriter w = new PrintWriter(
                            new BufferedWriter(
                            new FileWriter(outFile)));
            
            for (int i = 0; i < bmList.size();i++)                      //Rewrites the database to include the new mech
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
    /**
     * This function allows for the editing of an existing mech, it rebuilds
     * the database and should put the edited mech back where it was.
     * @param b 
     */
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
            if (bm.getName().equals(b.getName()))                       //Checks for the name of the edited mech, then adds the edited mech to its spot
            {                                                           //This delets the old mech and gives the illusion that we aren't just rewriting the database
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
            
            for (int i = 0; i < bmList.size();i++)                      //Rewrites the database with the edited mech in the old mech's spot
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
    /**
     * This function checks data validation for integers
     * @param x
     * @return 
     */
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