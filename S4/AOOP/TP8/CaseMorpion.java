import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class CaseMorpion{
  public JButton bouton;
  private Game partie=new Game();
  private int x,y;

  public CaseMorpion(int x,int y,Game partie){
    this.x=x;
    this.y=y;
    this.partie=partie;
    this.bouton=new JButton();
    bouton.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent evenement) {
        if(partie.player==1)bouton.setText("X");
        else bouton.setText("O");
        partie.jouer(x,y);
        bouton.setEnabled(false);
      }
    });
  }

}
