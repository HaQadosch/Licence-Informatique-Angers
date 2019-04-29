#include <iostream>
#include <vector>
#include <cstdlib> 

int main(){
  int min,max;
  int last,current;
  std::vector<int> nextPositions;
  std::cout << "Entrez la borne min et la borne max : ";
  std::cin >> min >> max;
  do{
    std::cout << "Entrez la dernière position visitée (entre " << min << " et " << max << ") : ";
    std::cin >> last;
  }while ((last < min)||(last > max));
  do{
    std::cout << "Entrez la position actuelle (entre " << min << " et " << max << ") : ";
    std::cin >> current;
  }while ((current < min)||(current > max));
  do{
    int i;
    std::cout << "Entrez la prochaine position à visiter : ";
    std::cin >> i;
    if ((i < min)||(i > max)) break;
    else nextPositions.push_back(i);    
  }while(1);
/* //Exemple du cours 
min = 0;
max = 199;
last = 125;
current = 143;
nextPositions.push_back(86); 
nextPositions.push_back(147); 
nextPositions.push_back(91); 
nextPositions.push_back(177); 
nextPositions.push_back(94); 
nextPositions.push_back(150); 
nextPositions.push_back(102); 
nextPositions.push_back(175); 
nextPositions.push_back(130);   
*/
  std::vector<int> copyNextPositions;
  int totalMoves;
  int lastCopy;
  int currentCopy;

  std::cout << std::endl;
  copyNextPositions = nextPositions;
  totalMoves=0;
  lastCopy=last;
  currentCopy=current;

  std::cout << "\033[32mDébut de l'algorithme FCFS (First Come First Served)... \033[0m" << std::endl;
  while(!copyNextPositions.empty()){
    lastCopy=currentCopy;
    currentCopy=copyNextPositions.front();
    std::cout << "Déplacement de la tête de " << lastCopy << " vers " << currentCopy << std::endl;
    totalMoves+=abs(currentCopy-lastCopy);
    copyNextPositions.erase(copyNextPositions.begin());
  }  
  std::cout << "\033[32mRésultat de l'algorithme FCFS (First Come First Served) : " << totalMoves << " mouvements \033[0m" << std::endl << std::endl;

  std::cout << std::endl;
  copyNextPositions = nextPositions;
  totalMoves=0;
  lastCopy=last;
  currentCopy=current;

  std::cout << "\033[32mDébut de l'algorithme SSF (Shortest Seek First)... \033[0m" << std::endl;
  while(!copyNextPositions.empty()){
    lastCopy=currentCopy;
    int minIndex=0;
    int min=abs(currentCopy-copyNextPositions.front());
    int index=0;
    for (auto it = copyNextPositions.begin(); it < copyNextPositions.end(); ++it, index++){
      if (min > abs(currentCopy-*it)) {min = abs(currentCopy-*it); minIndex = index;}
    }
    currentCopy=copyNextPositions[minIndex];
    std::cout << "Déplacement de la tête de " << lastCopy << " vers " << currentCopy << std::endl;
    totalMoves+=abs(min);
    copyNextPositions.erase(copyNextPositions.begin()+minIndex);
  }  
  std::cout << "\033[32mRésultat de l'algorithme SSF (Shortest Seek First) : " << totalMoves << " mouvements \033[0m" << std::endl << std::endl;


  std::cout << std::endl;
  copyNextPositions = nextPositions;
  totalMoves=0;
  lastCopy=last;
  currentCopy=current;

  std::cout << "\033[32mDébut de l'algorithme SCAN (algorithme de l’ascenseur)... \033[0m" << std::endl;
  bool montant;
  if (lastCopy < currentCopy) montant = true;
  else montant = false;
  while(!copyNextPositions.empty()){
    lastCopy = currentCopy;
    int minDistance=max;
    int minIndex=-1;
    int index=0;
    if (montant) {
      for (auto it = copyNextPositions.begin(); it < copyNextPositions.end(); ++it, index++){
        int distance = *it - currentCopy;  
        if ( (distance > 0) && (distance < minDistance)  ) {minDistance = distance; minIndex = index;}
      }
    }
    else{
      for (auto it = copyNextPositions.begin(); it < copyNextPositions.end(); ++it, index++){
        int distance = currentCopy - *it;  
        if ( (distance > 0) && (distance < minDistance)  ) {minDistance = distance; minIndex = index;}
      }
    }
    if (minIndex == -1) montant=!montant;
    else{
    currentCopy=copyNextPositions[minIndex];
    std::cout << "Déplacement de la tête de " << lastCopy << " vers " << currentCopy << std::endl;
    totalMoves+=abs(minDistance);
    copyNextPositions.erase(copyNextPositions.begin()+minIndex);
    }
  }  
  std::cout << "\033[32mRésultat de l'algorithme SCAN (algorithme de l’ascenseur) : " << totalMoves << " mouvements \033[0m" << std::endl << std::endl;

  std::cout << std::endl;
  copyNextPositions = nextPositions;
  totalMoves=0;
  lastCopy=last;
  currentCopy=current;

  std::cout << "\033[32mDébut de l'algorithme C-SCAN (algorithme de l’ascenseur circulaire)... \033[0m" << std::endl;
  while(!copyNextPositions.empty()){
    lastCopy = currentCopy;
    int minDistance=max;
    int minIndex=-1;
    int index=0;
    for (auto it = copyNextPositions.begin(); it < copyNextPositions.end(); ++it, index++){
      int distance = *it - currentCopy;  
      if ( (distance > 0) && (distance < minDistance)  ) {minDistance = distance; minIndex = index;}
    }
    if (minIndex == -1) {
       minDistance = currentCopy - copyNextPositions.front();
       minIndex=0;
    }
    currentCopy=copyNextPositions[minIndex];
    std::cout << "Déplacement de la tête de " << lastCopy << " vers " << currentCopy << std::endl;
    totalMoves+=abs(minDistance);
    copyNextPositions.erase(copyNextPositions.begin()+minIndex);
  }  
  std::cout << "\033[32mRésultat de l'algorithme C-SCAN (algorithme de l’ascenseur circulaire) : " << totalMoves << " mouvements \033[0m" << std::endl << std::endl;

  std::cout << std::endl;;
  

  return 0;
}
