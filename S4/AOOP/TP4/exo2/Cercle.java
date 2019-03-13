public class Cercle extends FormeGeometrique{
  Point centre;
  double rayon;

  public Cercle(String nom,Point centre, double rayon){
    this.centre=centre;
    this.rayon=rayon;
    this.nom=nom;
  }

  double perimetre(){
    return (2*Math.PI*this.rayon);
  }

  public String toString(){
    return "Cercle["+nom+" centre="+centre+",rayon="+rayon+",perimetre="+perimetre()+"]";
  }

  public void translation(double vx,double vy){
    this.centre.translation(vx,vy);
  }

}
