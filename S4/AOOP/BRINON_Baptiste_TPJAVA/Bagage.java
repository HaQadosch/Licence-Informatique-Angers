public class Bagage implements Comparable<Bagage>{
  int poids;
  int id;

  public Bagage(int poids, int id){
    this.poids=poids;
    this.id=id;
  }

  public String toString(){
    return("l'id est"+id+" et son poids"+poids);
  }

  public int compareTo(Bagage bag2){
    //comparaison sur le poids
    return(this.poids-bag2.poids);
  }
}
