import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.io.PrintWriter;
import java.io.BufferedReader;

public class PlainIORegion implements IORegion{

  public ArrayList<Region> lire(String fileName)throws IOException{
      BufferedReader in = null;
      ArrayList<Region> regions = new ArrayList<Region>();
      try {
        // ouverture du fichier
        in = new BufferedReader(new FileReader(fileName));
        // lecture des données
        String separateur=",";
        String line=null;
        while((line=in.readLine())!=null){ //parcours du fichier
          //attribution des valeurs de la ligne
          String[] temp=line.split(separateur);
          String type=temp[0];

          //cas region
          if(type.equals("Region")){
            String nom=temp[1];
            int POP=Integer.parseInt(temp[2]);
            int PIB=Integer.parseInt(temp[3]);
            int NbrCommunes=Integer.parseInt(temp[4]);
            int Superficie=Integer.parseInt(temp[5]);
            //creation de l'objet
            regions.add(new Region(nom,POP,PIB,NbrCommunes,Superficie));
        }
      }
    } finally {
      // fermeture du fichier
      if (in != null)  in.close();
    }
      return regions;
  }

  public void sauver(ArrayList<Region> regions, String fileName)throws IOException{
    PrintWriter out = null;
    try {
      // ouverture du fichier
      out = new PrintWriter(new FileWriter(fileName));
      int Tc=regions.size();
      Object[] tabRegions=regions.toArray();
      //parcours de la liste de formes
      for(int i=0;i<Tc;i++){
        out.println(tabRegions[i]);
      }//fin for
    } finally {
      // fermeture du flux
      if (out != null) out.close();
    }//fin try
  }//fin sauver
}//fin class
