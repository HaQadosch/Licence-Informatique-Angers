public class Tonneau extends Thread{
  String nom;
  double volume;
  double debit;
  Tonneau sortie;
  Tonneau entree;
  static double volumeMax=12;
  boolean bouchon;

  public Tonneau(String nom,double volume, double debitFuite, Tonneau sortie, boolean bouchon){
    this.nom=nom;
    this.volume=volume;
    this.debit=debitFuite;
    this.sortie=sortie;
    this.bouchon=bouchon;
    this.entree=null;
  }

  public void setEntree(Tonneau entree){
    this.entree=entree;
  }

  public synchronized void ajoutVolume(double ajout){
    if(this.volume+ajout<Tonneau.volumeMax) this.volume=this.volume+ajout;
    else{
      volume=Tonneau.volumeMax;
      System.out.println("---------- le tonneau ["+nom+"] déborde ! oskur ! ----------");
    }
  }

  public void enleveBouchon(){
    try{
      for(bouchon=false;bouchon!=true;sleep(1000)){
        if(sortie!=null){
          if(volume<debit){ // cas de tonneau presque vide
            retireVolume(volume);
            sortie.ajoutVolume(volume);
          }else{ // cas tonneau pas vide
            retireVolume(debit);
            sortie.ajoutVolume(debit);
          }
        }else{ // cas de tonneau sans sortie
          retireVolume(debit);
        }
        System.out.println("["+nom+"]:"+this.volume+"restant");
        boucher();
      }
    }catch(InterruptedException e){
      e.printStackTrace();
    }
  }

  public synchronized void boucher(){
    if(this.entree!=null){
      if(entree.bouchon==true && volume==0.0){
        this.bouchon=true;
      }
    }else if(volume==0.0){
      this.bouchon=true;
    }
  }

  public synchronized void retireVolume(double retrait){
    if(this.volume-retrait>0) this.volume=this.volume-retrait;
    else volume=0.0;
  }


  public void run(){
    enleveBouchon();
  }
}
