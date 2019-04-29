public class Jet extends Avion{
  Cabine cab;
  Soute soute;
  String modele;

  public Jet(Cabine cab,Soute soute){
    this.cab=cab;
    this.soute=soute;
    this.modele="Jet";
  }

  void decoller(){
    System.out.println("Jet décolle avec "+cab.nbPassag+" passagers");
  }
}
