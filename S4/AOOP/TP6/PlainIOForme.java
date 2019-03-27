import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.io.PrintWriter;
import java.io.BufferedReader;

public class PlainIOForme implements IOForme{

  public Collection<Forme> lire(String fileName)throws IOException{
      BufferedReader in = null;
      Collection<Forme> formes = new ArrayList<Forme>();
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
          int x=Integer.parseInt(temp[1]);
          int y=Integer.parseInt(temp[2]);
          //cas rectangle
          if(type.equals("Rectangle")){
            int longueur=Integer.parseInt(temp[3]);
            int largeur=Integer.parseInt(temp[4]);
            //creation de l'objet
            formes.add(new Rectangle(x,y,longueur,largeur));
          //cas cercle
        }else if(type.equals("Cercle")){
            int rayon=Integer.parseInt(temp[3]);
            //creation de l'objet
            formes.add(new Cercle(x,y,rayon));
          }
        }
      } finally {
      // fermeture du fichier
      if (in != null)
      in.close();
    }
      return formes;
  }

  public void sauver(Collection<Forme> formes, String fileName)throws IOException{
    PrintWriter out = null;
    try {
      // ouverture du fichier
      out = new PrintWriter(new FileWriter(fileName));
      int Tc=formes.size();
      Object[] tabFormes=formes.toArray();
      //parcours de la liste de formes
      for(int i=0;i<Tc;i++){
        out.println(tabFormes[i]);
      }//fin for
    } finally {
      // fermeture du flux
      if (out != null)
      out.close();
    }//fin try
  }//fin sauver
}//fin class
