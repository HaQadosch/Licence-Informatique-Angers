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
