public class Game{
  int[][] plateau=new int[3][3];
  int player;
  int fin;

  public Game(){
    this.fin=0;
    this.player=2;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        plateau[i][j]=0;
      }
    }
  }
/* la vérification s'éxécute sur le coup qu'on vient de jouer, d'ou l'ajout de X et Y en parametre
si quelqu'un gagne, c'est grace au coup qu'il vient de jouer, donc on ne teste que les lignes adjacentes.
Cette verification se déroule en 3 étapes:
  1) on verifie la ligne verticale et la ligne horizontale où est situé le coup joué
  2) s'il est au centre, alors on teste toutes les diagonales
  3) s'il n'est pas au centre, alors on teste la seule diagonale où il se trouve.
*/
  private int testVictory(int x,int y){
    // étape 1
    if((plateau[0][y]==player && plateau[1][y]==player && plateau[2][y]==player) || (plateau[x][0]==player && plateau[x][1]==player && plateau[x][2]==player)){
      return 1;
    }else if(x==1 && y==1){ // on verifie s'il est au centre
      //etape 2
      if((plateau[0][0]==player && plateau[2][2]==player) || (plateau[0][2]==player && plateau[2][0]==player)){
        return 1;
      }
    // etape 3
    }else if(plateau[2-x][2-y]==player && plateau[1][1]==player){
      return 1;
    }
    return 0 ; // si pas de victoire, alors on continue.
  }

  private boolean testNull(){
    // parcours du plateau
    for(int i=0;i<=2;i++){
      for(int j=0;j<=2;i++){
        if(plateau[i][j]==0) return false; // retourne faux si une case est vide
      }
    }
    return true;//sinon, retourne vrai
  }

  public void jouer(int x,int y){
    // on ne modifie le joueur que lorsqu'on peut continuer à jouer
    if(player==1){
      player=2;
    }else{
      player=1;
    }

    plateau[x][y]=player; // on place le coup
    this.fin=testVictory(x,y);// verification de la victoire
    if(this.fin==1) System.out.println("le joueur "+player+" à gagné");
    else if(testNull()){  // verification de match nul
      System.out.println("partie nulle");
      this.fin=1; // mets fin à la partie
    }
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
