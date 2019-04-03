import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class Test{
  public static void main(String[] args){
    JFrame window=new JFrame(); // definition du JFrame
    window.setSize(400,200);
    window.setLayout(new FlowLayout()); // ajout du Layout au JFrame
    //ajout de l'espace texte
    JLabel name =new JLabel();
    name.setText("What is your name?");
    window.add(name);
    //ajout du champ texte
    window.add(new TextField(30));
    //ajout du bouton
    JButton ok=new JButton("ok");
    ok.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent evenement) {
        System.out.println(name.getText());
      }
    });
    window.add(ok);
    //affichage de la fenetre
    window.setVisible(true);
  }

}
