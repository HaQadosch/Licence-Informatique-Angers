#include <iostream>
#include <vector>
#include <queue>

void displayFreeSpaces(std::vector<int> freeSpaces, char u){
  for (auto i = freeSpaces.begin(); i<freeSpaces.end();i++){
    std::cout << *i << u << " ";
  }
  std::cout << std::endl;
}

void firstFit(std::vector<int> freeSpaces, std::queue<int> nextAllocations, char u){
  bool erreur=false; 
  while(!nextAllocations.empty() && !erreur){
    erreur=true;
    for (unsigned int i = 0; i<freeSpaces.size(); i++){
      if (freeSpaces[i] >= nextAllocations.front()) {
        erreur=false;
        freeSpaces[i] -= nextAllocations.front();
        if (freeSpaces[i] == 0) freeSpaces.erase(freeSpaces.begin()+i);
        std::cout << "Allocation mémoire à l'emplacement " << i+1 << std::endl;
        break;
      }
    }
    if (!erreur) {
      nextAllocations.pop();
    }
  }
  if (erreur) std::cout << "Erreur !! aucun espace assez grand disponible pour accueillir : " << nextAllocations.front() << u << std::endl; 
  displayFreeSpaces(freeSpaces,u);
}

void bestFit(std::vector<int> freeSpaces, std::queue<int> nextAllocations, char u){
  while(!nextAllocations.empty()){
    int distance=-1;
    int indiceMin = -1;
    for (unsigned int i = 0; i<freeSpaces.size(); i++){
      if (freeSpaces[i] >= nextAllocations.front()) {
        if (distance == -1) {
          indiceMin = i;
          distance = freeSpaces[i] - nextAllocations.front();
        }
        else{
          if (distance > freeSpaces[i] - nextAllocations.front()) {
            indiceMin = i;
            distance = freeSpaces[i] - nextAllocations.front();
          }
        }
      }
    }
    if (indiceMin != -1) {
      std::cout << "Allocation mémoire à l'emplacement " << indiceMin+1 << std::endl;
      freeSpaces[indiceMin] = freeSpaces[indiceMin] - nextAllocations.front();
      if (freeSpaces[indiceMin] == 0) freeSpaces.erase(freeSpaces.begin()+indiceMin);
      nextAllocations.pop();
      indiceMin=-1;
      distance=-1;
    }
    else {   
      std::cout << "Erreur !! aucun espace assez grand disponible pour accueillir : " << nextAllocations.front() << u << std::endl; 
      break;
    }
  }
  displayFreeSpaces(freeSpaces,u);
}

void nextFit(std::vector<int> freeSpaces, std::queue<int> nextAllocations, char u){
  int erreur=0; 
  int i = 0;
  while(!nextAllocations.empty() && (erreur<freeSpaces.size())){
    erreur=true;
    if (i<freeSpaces.size()) {
      if (freeSpaces[i] >= nextAllocations.front()) {
        erreur=false;
        freeSpaces[i] -= nextAllocations.front();
        if (freeSpaces[i] == 0) freeSpaces.erase(freeSpaces.begin()+i);
        std::cout << "Allocation mémoire à l'emplacement " << i+1 << std::endl;
        nextAllocations.pop();
      }
      else erreur++;      
      i++;
    }
    else{
      i=0;
    }
  }
  if (erreur==freeSpaces.size()) std::cout << "Erreur !! aucun espace assez grand disponible pour accueillir : " << nextAllocations.front() << u << std::endl; 
  displayFreeSpaces(freeSpaces,u);
}

int main(){
  int libre;
  char u;
  std::cout << "Entrez l'unité de taille utilisée (un seul caractère ex: K, M, G, T, ...) : ";
  std::cin >> u;
  std::vector<int> freeSpaces;
  do{
    std::cout << "Entrer la taille du prochain espace libre : ";
    std::cin >> libre;
    freeSpaces.push_back(libre);
  }while(libre > 0);
  freeSpaces.pop_back();
  
  int allocation;
  std::queue<int> nextAllocations;
  do{
    std::cout << "Entrer la taille de la prochaine demande d'allocation : ";
    std::cin >> allocation;
    if (allocation > 0)
      nextAllocations.push(allocation);
  }while(allocation > 0);
  std::cout << std::endl;
  std::cout << "État mémoire avant le début des algorithmes : " << std::endl;
  displayFreeSpaces(freeSpaces,u);
  std::cout << std::endl;
  std::cout << "Début de l'algorithme first fit : " << std::endl;
  firstFit(freeSpaces, nextAllocations, u);
  std::cout << std::endl;
  std::cout << "Début de l'algorithme best fit : " << std::endl;
  bestFit(freeSpaces, nextAllocations, u);
  std::cout << std::endl;
  std::cout << "Début de l'algorithme next fit : " << std::endl;
  nextFit(freeSpaces, nextAllocations, u);

  return 0; 
}
