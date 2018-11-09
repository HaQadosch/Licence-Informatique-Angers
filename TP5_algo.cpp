#include <iostream>
#include <fstream>

// QA
#include <array>
const int MAX_SIZE = 10;
using matrice = std::array<std::array<bool,MAX_SIZE>,MAX_SIZE>;

//QB
void init_matrice(matrice &M, int n){
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      M[i][j]=FALSE;
      M[j][i]=FALSE;
}

Void ajout_arete(matrice &M, int l, int c){
  M[l][c]=TRUE;
  M[c][l]=TRUE;
}
//QC
unsing couleur=std::array<int,MAX_SIZE>;
couleur coloration(int n){
  couleur c[n];
  for (int i=0;i<n;i++){
    c[i]=0;
  }
  return c;
}
    
//QD
bool correct (Matrice M,couleur C, int n){
  for (int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      if(M[i][j]==TRUE && M[j][i]==TRUE){
        if(C[i]==C[j]) return FALSE;
      }
    }
  }
  return TRUE;
}
    
int main(){
  matrice M;
  init_matrice(M,9);
  ajout_arete(M,1,2);
  ajout_arete(M,2,5);
  ajout_arete(M,5,6);
  ajout_arete(M,6,3);
  ajout_arete(M,5,4);
  ajout_arete(M,4,7);
  ajout_arete(M,5,8);
  ajout_arete(M,8,9);
  return 1;+
}
