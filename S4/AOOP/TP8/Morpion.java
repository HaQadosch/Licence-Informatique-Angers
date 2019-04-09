import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Morpion{

  public static void main(String[] args){
    Game mor=new Game();
    //configuration de l'affichage
    JFrame window=new JFrame();
    window.setSize(400,200);
    window.setLayout(new GridLayout(3,3));
    CaseMorpion case00=new CaseMorpion(0,0,mor);
    CaseMorpion case01=new CaseMorpion(0,1,mor);
    CaseMorpion case02=new CaseMorpion(0,2,mor);
    CaseMorpion case10=new CaseMorpion(1,0,mor);
    CaseMorpion case11=new CaseMorpion(1,1,mor);
    CaseMorpion case12=new CaseMorpion(1,2,mor);
    CaseMorpion case20=new CaseMorpion(2,0,mor);
    CaseMorpion case21=new CaseMorpion(2,1,mor);
    CaseMorpion case22=new CaseMorpion(2,2,mor);

    window.add(case00.bouton);
    window.add(case01.bouton);
    window.add(case02.bouton);
    window.add(case10.bouton);
    window.add(case11.bouton);
    window.add(case12.bouton);
    window.add(case20.bouton);
    window.add(case21.bouton);
    window.add(case22.bouton);

    window.setVisible(true);
    while(mor.fin!=1);
    case22.bouton.setEnabled(false);
    /*while(mor.fin!=1){
      mor.jouer();
      System.out.println(mor);
    }*/
  }
}
