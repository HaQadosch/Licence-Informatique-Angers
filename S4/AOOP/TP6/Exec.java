import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.io.PrintWriter;
import java.io.BufferedReader;

public class Exec{
  public static void main(String[] args) throws IOException {
    // TEST AVEC FICHIER TEXTE
    String fileName = "nomFichier";
    IOForme io = new PlainIOForme(); // PlainIOForme, ObjectIOForme...
    Collection<Forme> formes1 = new ArrayList<Forme>();
    formes1.add(new Rectangle(2,3,4,5));
    formes1.add(new Cercle(6,7,8));
    io.sauver(formes1,fileName);
    Collection<Forme> formes2 = io.lire(fileName);
    System.out.println("\n test d'écriture et lecture dans un fichier texte \n ");
    System.out.println("on écrit dans un fichier :"+formes1);
    System.out.println("aprés fermeture et ouverture, on peut lire"+formes2);
    if(formes1.equals(formes2)){ System.out.println("réussite yay");}
    for (Forme f : formes2) { // on vérifie que formes1 = formes 2
      System.out.println(f);
    }

    // TEST AVEC FICHIER BINAIRE
    





  }
}
