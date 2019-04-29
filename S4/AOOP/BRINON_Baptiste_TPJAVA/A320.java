public class A320 extends Avion{
  Cabine cab;
  Soute soute;
  String modele;
  
  public A320(){
    cab=new Cabine(6,30);
    soute=new Soute(1000);
    modele="A320";
  }

  void decoller(){
    System.out.println("A320 décolle avec "+cab.nbPassag+" passagers");
  }
}
