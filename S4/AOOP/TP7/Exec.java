import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.io.PrintWriter;
import java.io.BufferedReader;

public class Exec{
  public static void main(String[] args) throws IOException {
    // TEST DU FICHIER CSV
    String fileName = "regions.csv";
    IORegion io = new PlainIORegion();
    ArrayList<Region> regions = io.lire(fileName);
    //affichage de regions
    for (Region r : regions) {
      System.out.println(r);
    }

    System.out.println("\n TRI DU FICHIER PAR NOMS \n");
    Collections.sort(regions); // tri
    // affichage aprés tri
    for (Region r : regions) {
      System.out.println(r);
    }

    System.out.println("\n TRI DU FICHIER PAR PIBS \n");
    Collections.sort(regions,new SortByPIBHbt()); // tri
    // affichage aprés tri
    for (Region r : regions) {
      System.out.println(r);
    }
    io.sauver(regions,"regionsParPIB.csv");

    System.out.println("\n TRI DU FICHIER PAR DENSITE \n");
    Collections.sort(regions,new SortByDensity()); // tri
    // affichage aprés tri
    for (Region r : regions) {
      System.out.println(r);
    }
    io.sauver(regions,"regionsParDensite.csv");
  }
}
