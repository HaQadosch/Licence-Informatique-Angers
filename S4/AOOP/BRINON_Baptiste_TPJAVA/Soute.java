import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
/**
* la classe Soute correspond aux soutes,
* elle contient une liste de bagages, un poids max et un poids courant
* @author Brinon Baptiste
*/
public class Soute{
  /**
  * il s'agit de la liste de bagages
  */
  ArrayList<Bagage> bagages=new ArrayList<Bagage>();

  /**
  * poids maximum que transporte la soute
  */
  int poidsMax;
  /**
  * poids courant de la soute
  */
  int poids;

  /**
  * constructeur de la classe Soute
  * @param poidsMax poids max de la soute
  */
  public Soute(int poidsMax){
    this.poidsMax=poidsMax;
  }


  /**
  * Ajouter le bagage à la soute
  * @param bagage bagage à ajouter à la soute
  */
  public void ajouterBagage(Bagage bagage){
    if(peutTransporter(bagage)==false) System.out.println("le bagage ne rentre pas dans la soute");
    else{
      this.poids+=bagage.poids;
      bagages.add(bagage);
    }
  }

  /**
  * Retire le bagage de la soute
  * @param bagage bagage à retirer de la soute
  */
  public void enleverBagage(Bagage bagage){
    boolean removed=bagages.remove(bagage);
    if(removed==false) System.out.println("le Bagage n'a pas pu être supprimé");
    else this.poids-=bagage.poids;
  }

  public boolean peutTransporter(Bagage bagage){
    return(bagage.poids+this.poids>poidsMax);
  }

  public void trierBagages(){
      Collections.sort(bagages);
  }
}
