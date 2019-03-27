import java.io.*;
import java.util.*;


public class Exercice1{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String path=sc.next();
    File fic=new File(path);
    if(fic.isDirectory()){
      System.out.println("il s'agit d'un dossiers contenant: \n");
      File[] f=fic.listFiles();
      for(int i=0;i<f.length;i++){
        System.out.println(f[i]+"\n");
      }
    } else if(fic.exists()){
      System.out.println("il s'agit d'un fichier de chemin absolu "+ fic.getAbsolutePath() +" contenant: \n" + fic.length());
    } else {
      System.out.println(" entrez un fichier valide");
    }// fin else
    sc.close();
  }// fin main
}// fin classe
