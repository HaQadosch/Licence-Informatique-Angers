#include<stdio.h> 
#include <iostream>
#include <vector>

void displayGANT(std::vector<int> processus){
  for (auto it = processus.begin(); it< processus.end(); it++){
    std::cout << "|\033[3" << *it << "mP" << *it << "\033[0m";
  }
  std::cout << "|" << std::endl;
  for (unsigned int i = 0; i <= processus.size(); i++){
    if (i < 10) std::cout << i << "  ";
    else if (i < 100) std::cout << i << " ";
    else if (i < 1000) std::cout << i;
  }
  std::cout << std::endl;
  return;
}

void displayAttente(std::vector<int> attente, std::vector<int> fin){
  float moyenneAttente = 0;
  std::cout << std::endl << "--------------";
  for (auto it = fin.begin(); it < fin.end(); it++ ){
    std::cout << "----";
  }
  std::cout << std::endl;
  std::cout << "| Processus  |";
  for (unsigned int i = 1; i <= attente.size(); i++){
    std::cout << "P" << i << " |";
  }
  std::cout << std::endl << "--------------";
  for (auto it = fin.begin(); it < fin.end(); it++ ){
    std::cout << "----";
  }
  std::cout << std::endl;
  std::cout  << "|Date de fin |";
  for (auto it = fin.begin(); it < fin.end(); it++ ){
    if (*it < 10) std::cout << " " << *it << " |";
    else if (*it < 100) std::cout << " " << *it << "|";
    else if (*it < 1000) std::cout << *it << "|";
    else std::cout << "inf|";
  }
  std::cout << std::endl << "--------------";
  for (auto it = fin.begin(); it < fin.end(); it++ ){
    std::cout << "----";
  }
  std::cout << std::endl << "|  Attente   |";
  for (auto it = attente.begin(); it < attente.end(); it++ ){
    moyenneAttente += *it;
    if (*it < 10) std::cout << " " << *it << " |";
    else if (*it < 100) std::cout << " " << *it << "|";
    else if (*it < 1000) std::cout << *it << "|";
    else std::cout << "inf|";
  }
  std::cout << std::endl << "--------------";
  for (auto it = attente.begin(); it < attente.end(); it++ ){
    std::cout << "----";
  }
  std::cout << std::endl << "Le temps moyen d'attente des processus est de " << moyenneAttente/attente.size() << " unités de temps." << std::endl;
  std::cout << std::endl;
  return;
}

int FIFO(std::vector<int> tempsP){
  std::vector<int> processusGANT;
  std::vector<int> attente;
  std::vector<int> fin;
  int tempsEcoule = 0;
  attente.push_back(0);
  for (unsigned int i=0; i< tempsP.size();){

    if (tempsP[i] > 0){
      tempsEcoule++;
      processusGANT.push_back(i+1);
      tempsP[i]--;
    }
    else {i++; fin.push_back(tempsEcoule); attente.push_back(tempsEcoule);}
  }
  attente.pop_back();

  displayGANT(processusGANT);
  displayAttente(attente,fin);
}

int roundrobin(std::vector<int> tempsP, int quantum){
  std::vector<int> processusGANT;
  std::vector<int> attente;
  std::vector<int> fin;
  std::vector<int> lastTurn;
  for (unsigned int i = 0; i<tempsP.size(); i++) {attente.push_back(0); fin.push_back(0); lastTurn.push_back(0);}
  int tempsEcoule = 0;
  unsigned int compteur = 0;
  unsigned int cmptQuantum=0;
  for (unsigned int i=0; compteur != tempsP.size();){
    if (i >= tempsP.size()) i=0;
    else if (tempsP[i]==0) {i++; compteur++; cmptQuantum = 0;}    
    else {  
      processusGANT.push_back(i+1); 
      tempsP[i]--;
      attente[i] = attente[i] + (tempsEcoule - lastTurn[i]); 
      tempsEcoule++;  
      if (tempsP[i] == 0) fin[i] = tempsEcoule;
      lastTurn[i] = tempsEcoule; 
      compteur=0; 
      cmptQuantum++; 
      if (cmptQuantum >= quantum) {cmptQuantum=0; i++;}
    }
  }

  displayGANT(processusGANT);
  displayAttente(attente,fin);
}

int shortest(std::vector<int> tempsP){
   std::vector<int> processusGANT;
  std::vector<int> attente;
  std::vector<int> fin;
  std::vector<int> lastTurn;
  for (unsigned int i = 0; i<tempsP.size(); i++) {attente.push_back(0); fin.push_back(0); lastTurn.push_back(0);}
  int tempsEcoule = 0;
  int min;
  int indiceMin;
  do {
    min = 0;

    for (unsigned int i = 0; i < tempsP.size(); i++) {
      if ( (min==0) || ((tempsP[i]<min) && (tempsP[i]!=0))) {
        min=tempsP[i];
        indiceMin=i;    
      }
    }
    
    if (min!=0){
      attente[indiceMin]=tempsEcoule;
      while(tempsP[indiceMin]!=0){
        processusGANT.push_back(indiceMin+1);
        tempsEcoule++;
        tempsP[indiceMin]--;
      }
      fin[indiceMin]=tempsEcoule;
    }
  }while (min!=0);

  displayGANT(processusGANT);
  displayAttente(attente,fin);
}

int priority(std::vector<int> tempsP, std::vector<int> prioriteP){
   std::vector<int> processusGANT;
  std::vector<int> attente;
  std::vector<int> fin;
  std::vector<int> lastTurn;
  for (unsigned int i = 0; i<tempsP.size(); i++) {attente.push_back(0); fin.push_back(0); lastTurn.push_back(0);}
  int tempsEcoule = 0;
  int max;
  int indiceMax;
  do {
    max = 0;

    for (unsigned int i = 0; i < prioriteP.size(); i++) {
      if (prioriteP[i]>max) {
        max=prioriteP[i];
        indiceMax=i;    
      }
    }
    
    if (max!=0){
      prioriteP[indiceMax]=0;
      attente[indiceMax]=tempsEcoule;
      while(tempsP[indiceMax]!=0){
        processusGANT.push_back(indiceMax+1);
        tempsEcoule++;
        tempsP[indiceMax]--;
      }
      fin[indiceMax]=tempsEcoule;
    }
  }while (max!=0);

  displayGANT(processusGANT);
  displayAttente(attente,fin);
}

int main() 
{
  unsigned int nbProcessus;
  std::vector<int> tempsP;
  std::vector<int> prioriteP;

  do{
    std::cout << "Entrez un nombre de processus (1 <= nbP < 10) : ";
    std::cin >> nbProcessus;  
  } while ((nbProcessus >= 10) || (nbProcessus < 1));
  for (unsigned int i = 0; i < nbProcessus; i++){
    int temps;
    do{    
    std::cout << "Entrez le temps CPU du processus " << i+1 << " (>=0):";
    std::cin >> temps;
    }while (temps < 0);
    tempsP.push_back(temps);
  }
  for (unsigned int i = 0; i < nbProcessus; i++){
    int priorite;
    do{    
    std::cout << "Entrez la priorité du processus " << i+1 << " (>=0):";
    std::cin >> priorite;
    }while (priorite < 0);
    prioriteP.push_back(priorite);
  }
  int quantum;
  do{
  std::cout << "Entrez le quantum pour le round robin (1 <= quantum < 10): ";
  std::cin >> quantum;
  } while ((quantum < 1) || (quantum >= 10)) ;
  std::cout << std::endl << "##############################################" << std::endl << std::endl ;
  std::cout << "Résultats pour l'algorithme premier arrivé premier sorti : " << std::endl;
  std::cout << std::endl;
  FIFO(tempsP);
  std::cout << std::endl;
  std::cout << "Résultats pour l'algorithme round robin : " << std::endl;
  std::cout << std::endl;
  roundrobin(tempsP, quantum);
  std::cout << std::endl;
  std::cout << "Résultats pour l'algorithme plus court d'abord : " << std::endl;
  std::cout << std::endl;
  shortest(tempsP);
  std::cout << std::endl;
  std::cout << "Résultats pour l'algorithme plus haute priorité : " << std::endl;
  std::cout << std::endl;
  priority(tempsP,prioriteP);
  std::cout << std::endl;  
  return 0; 
}
