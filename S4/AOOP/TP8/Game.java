public class Game{
  int[][] plateau=new int[3][3];
  int player;

  public Game(){
    player=1;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        plateau[i][j]=0;
      }
    }
  }

  private int testVictory(int x,int y){
    if((plateau[0][y]==player && plateau[1][y]==player && plateau[2][y]==player) || (plateau[x][0]==player && plateau[x][1]==player && plateau[x][2]==player)){
      return 1;
    } else return 0 ;
  }

  public int jouer(int x,int y){
    if(player==1){
      player=2;
    }else{
      player=1;
    }

    plateau[x][y]=player;
    int victory=testVictory(x,y);
    if(victory==1) System.out.println("le joueur "+player+" à gagné");
    if(victory==2) System.out.println(" partie nulle");
    return victory;
  }

  public String toString(){
    String retour="+-----+\n";
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        retour=retour+"|"+plateau[i][j];
      }
      retour=retour+"|\n+-----+\n";
    }
    return retour;
  }

}
