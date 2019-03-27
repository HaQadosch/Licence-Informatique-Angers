public class Rectangle extends Forme{
  private int longueur;
  private int largeur;

  public Rectangle(int x, int y, int longueur, int largeur){
    this.x=x;
    this.y=y;
    this.longueur=longueur;
    this.largeur=largeur;
  }
  ////////////////// getters & setters //////////////////
  public void setLongueur(int longueur){
    this.longueur=longueur;
  }
  public void setLargeur(int largeur){
    this.largeur=largeur;
  }
  public int getLongueur(){
    return(this.longueur);
  }
  public int getLargeur(){
    return(this.largeur);
  }

  public String toString(){
    return("Rectangle,"+x+","+y+","+longueur+","+largeur);
  }
}
