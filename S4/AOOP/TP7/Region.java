public class Region implements Comparable<Region>{
  public String Nom;
  public int POP;
  public int PIB;
  public int NbrCommunes;
  public int Superficie;

  //
  public Region(String nom, int POP, int PIB, int NbrCommunes, int Superficie){
    this.Nom=nom;
    this.POP=POP;
    this.PIB=PIB;
    this.NbrCommunes=NbrCommunes;
    this.Superficie=Superficie;
  }

  public int compareTo(Region reg2){
    //comparaison sur l'ordre alphabétique
    return(this.Nom.compareTo(reg2.Nom));
  }

  public String toString(){
    return("Region,"+Nom+","+POP+","+PIB+","+NbrCommunes+","+Superficie);
  }
}
