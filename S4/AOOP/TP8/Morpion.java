import java.util.Scanner;

public class Morpion{

  public static void main(String[] args){
    int victory=0;
    Game mor=new Game();
    Scanner sc=new Scanner(System.in);
    while(victory!=1){
      victory=mor.jouer(Integer.parseInt(sc.next()),Integer.parseInt(sc.next()));
      System.out.println(mor);
    }
  }
}
