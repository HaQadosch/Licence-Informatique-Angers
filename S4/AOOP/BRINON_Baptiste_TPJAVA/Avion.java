import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.io.PrintWriter;
import java.io.BufferedReader;

abstract class Avion{
  Cabine cab;
  Soute soute;
  String modele;

  abstract void decoller();
  boolean ajouterPassager(Passager passager){
    if(soute.peutTransporter(passager.bag)&&cab.estRemplie()==false){
      cab.ajouterPassager(passager);
      soute.ajouterBagage(passager.bag);
      return true;
    }
    else return false;
  }
  public void enleverPassager(Passager passager){
    soute.enleverBagage(passager.bag);
    cab.retirerPassager(passager);
  }
  public void chargerAvion(String fileName) throws IOException{
      BufferedReader in = null;
      try {
        // ouverture du fichier
        in = new BufferedReader(new FileReader(fileName));
        // lecture des données
        String separateur=",";
        String line=in.readLine();
        String[] temp=line.split(separateur);
        String nom=temp[0];
        int age=Integer.parseInt(temp[1]);
        int poidsBagage=Integer.parseInt(temp[2]);
        int id=1;
        Bagage bagage=new Bagage(id,poidsBagage);
        Passager passager=new Passager(nom,age,bagage);

        while(ajouterPassager(passager) && (line=in.readLine())!=null){ //parcours du fichier aprés ajout du Passager précédant
          //attribution des valeurs de la ligne
          temp=line.split(separateur);
          nom=temp[0];
          age=Integer.parseInt(temp[1]);
          poidsBagage=Integer.parseInt(temp[2]);
          id++;
          //creation de l'objet
          bagage=new Bagage(id,poidsBagage);
          passager=new Passager(nom,age,bagage);
        }
      } finally {
        // fermeture du fichier
        if (in != null)  in.close();
      }
  }


}
