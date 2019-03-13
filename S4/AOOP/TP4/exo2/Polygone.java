import java.util.ArrayList;

public class Polygone extends FormeGeometrique{
  ArrayList<Point> listePoints=new ArrayList<Point>();

  public Polygone(String nom){
    this.nom=nom;
    //this.listePoints=null;
  }

  double perimetre(){
      double perim=0;
      for(int i=0;i<listePoints.size();i++){
        if(i<listePoints.size()-1){
			     perim=perim+listePoints.get(i).distance(listePoints.get(i+1));
         }  else perim=perim+listePoints.get(i).distance(listePoints.get(0));
       }
       return perim;
  }

  public void translation(double vx,double vy){
    for(int i=0;i<listePoints.size();i++){
      listePoints.get(i).translation(vx,vy);
    }
  }

}
