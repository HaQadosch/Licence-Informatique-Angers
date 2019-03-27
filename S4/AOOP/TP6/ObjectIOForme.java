import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.*;

public class ObjectIOForme implements IOForme{

  public Collection<Forme> lire(String fileName)throws IOException{
     ObjectInputStream ois;
      ois = new ObjectInputStream(new FileInputStream("objets"));
      Collection<Forme> formes = new ArrayList<Forme>();
      try {
    /*    while(true){ //parcours du fichier
          String type=ois.readUTF();
          if(type.equals("Rectangle")){
            Cercle nouv=new Cercle()
          }else if(type.equals("Cercle")){

          }
          formes.add(obj);
        }
      } catch (ClassNotFoundException cnfe) {
          syste.out.println("erreur dans la lecture du fichier");// erreur de lecture
      } catch (EOFException eofe) {
          // fin de fichier
      */}finally {
      // fermeture du fichier
      if (ois != null) ois.close();
    }
      return formes; 
  }

  public void sauver(Collection<Forme> formes, String fileName)throws IOException{
    /*PrintWriter out = null;
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
    }//fin try */
  }//fin sauver
}//fin class
