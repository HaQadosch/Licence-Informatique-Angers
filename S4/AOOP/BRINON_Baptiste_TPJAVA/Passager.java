public class Passager{
  int age;
  String nom;
  Bagage bag;

  public Passager(String nom, int age, Bagage bag){
    this.nom=nom;
    this.age=age;
    this.bag=bag;
  }

  public String toString(){
    return(nom+" a "+age+"ans et transporte "+bag);
  }
}
