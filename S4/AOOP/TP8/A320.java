public class A320 implements Avion{
  Cabine cab;
  Soute soute;
  String modele;

  public A320(){
    cab=new Cabine(6,30);
    soute=new Soute(1000);
    modele="A320";
  }

  void decoller(){
  
  }
}
