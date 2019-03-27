public class Cercle extends Forme{
  public int rayon;

  public Cercle(int x, int y, int rayon){
    this.x=x;
    this.y=y;
    this.rayon=rayon;
  }

  public String toString(){
    return("Cercle,"+x+","+y+","+rayon);
  }

  ////////////////// getters & setters //////////////////
  public void setRay(int rayon){
    this.rayon=rayon;
  }
  public int getRayon(){
    return(this.rayon);
  }


}
