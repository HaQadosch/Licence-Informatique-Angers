public class Triangle extends Polygone{

  public Triangle(String nom){
    super(nom);
  }

  public String toString(){
    String result="Triangle "+nom+"[";
      for(int i=0;i<listePoints.size();i++){
        result=result+listePoints.get(i);
      }
    result=result+"Perimetre="+this.perimetre()+"]";
    return result;
  }
}
