public class Rectangle extends Polygone{

  public Rectangle(String nom){
    super(nom);
  }

  public String toString(){
    String result="Rectangle "+nom+"[";
      for(int i=0;i<listePoints.size();i++){
        result=result+listePoints.get(i);
      }
    result=result+"Perimetre="+this.perimetre()+"]";
    return result;
  }
}
