public class Cabine{
  int nbCol;
  int nbRang;
  int nbPassag;
  Passager[][] passag;

  public Cabine(int nbRang, int rbCol){
    this.nbCol=nbCol;
    this.nbRang=nbRang;
    passag=new Passager[nbRang][nbCol];
    nbPassag=0;
  }

  public void ajouterPassager(Passager ajout){
    int placed=0;
    for(int i=0;(i<nbRang && placed!=1);i++){
      for(int j=0;(j<nbCol && placed!=1);j++){
        if(passag[i][j]==null){
         passag[i][j]=ajout ;
         placed=1;
         this.nbPassag++;
       }
      }
    }
    if(placed==0) System.out.println("aucune place n'a été trouvée pour le passager"+ajout);
  }

  public void retirerPassager(Passager iWannaLeave){
    int removed=0;
    for(int i=0;(i<nbRang && removed!=1);i++){
      for(int j=0;(j<nbCol && removed!=1);j++){
        if(passag[i][j]==iWannaLeave){
         passag[i][j]=null;
         removed=1;
         this.nbPassag--;
       }
      }
    }
    if(removed==0) System.out.println("le passager"+iWannaLeave+" n'était pas présent");
  }

  public boolean estRemplie(){
    if(nbPassag==nbRang*nbCol)return true;
    else return false;
  }

}
