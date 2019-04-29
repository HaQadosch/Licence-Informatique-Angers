#include <iostream>
#include <vector>
#include <string>

void displayVecteur(std::vector<int> V, std::string S){
  std::cout << "Affichage du vecteur "<< S << " : " << std::endl;
  std::cout << "[ ";
  for (auto it = V.begin(); it!=V.end(); it++){
    std::cout << *it << " ";  
  }
  std::cout << "]" << std::endl;
}

void displayMatrice(std::vector<std::vector <int> > M, std::string S){
  std::cout << "Affichage de la matrice "<< S << " : " << std::endl;
  for (auto it = M.begin(); it!=M.end(); it++){
    std::cout << "[ ";
    for (auto itt = it->begin(); itt!=it->end(); itt++){
      std::cout << *itt << " ";  
    }
    std::cout << "]" << std::endl;
  }
}

void displayEtat(std::vector<int> DispoTest, std::vector<bool> Termine){
  std::cout << "Etat courant : ";  
  std::cout << "Termine = ";
  std::cout << "[ ";
  for (auto it = Termine.begin(); it!=Termine.end(); it++){
    std::cout << *it << " ";  
  }
  std::cout << "]";
  std::cout << "  DispoTest = ";
  std::cout << "[ ";
  for (auto it = DispoTest.begin(); it!=DispoTest.end(); it++){
    std::cout << *it << " ";  
  }
  std::cout << "]" << std::endl; 
}

bool TestSur(std::vector< std::vector <int> > Besoin, std::vector< std::vector <int> > Allocation, std::vector<int> DispoTest, std::vector<bool> Termine){
  bool termine = false;
  bool erreur = false;
  while(!termine && !erreur){
    displayEtat(DispoTest,Termine);
    std::cout << "Recherche d'un processus i non terminé tel que Besoin(i) <= DispoTest" << std::endl;
    bool term = true;
    erreur = false;
    for (int i = 0; i < Termine.size(); i++){
      if (!Termine[i]){
        term=false;
        bool err=false;
        for (int j = 0; j < DispoTest.size(); j++){
          if (DispoTest[j] < Besoin[i][j]) {err = true; break;}
        }
        if (err) erreur = true;
        else {erreur = false; 
          for (int j = 0; j < DispoTest.size(); j++){
            DispoTest[j] = Allocation[i][j]+DispoTest[j];
            Termine[i] = true;
          }
          break; 
        }
      }
    }
    if (term) termine=true;
  }
  if (erreur) return false;
  else return true;
}

int main(){
  int n, m;
  std::vector<int> Disponible;
  std::vector<std::vector<int> > Max;
  std::vector<std::vector<int> > Allocation;
  std::vector<std::vector<int> > Besoin;
  std::vector<bool> Termine;

  std::cout << "Entrez le nombre de processus souhaité : ";
  std::cin >> n;
  std::cout << "Nombre de types de ressources dans le système : "; 
  std::cin >> m;
  std::cout << "Entrez le vecteur disponible (" << m << " valeurs) : ";
  for (int i = 0; i < m; i++){
    int v;
    std::cin >> v;
    Disponible.push_back(v);
  }

  for (int i = 0; i < n; i++){
    std::cout << "Entrez les valeurs maximales de ressources pour le processus " << i << " (" << m << " valeurs) : ";
    std::vector<int> V;
    for (int j = 0; j < m; j++){
      int v;
      std::cin >> v;
      V.push_back(v);
    }
      Max.push_back(V);
  }

  for (int i = 0; i < n; i++){
    std::cout << "Entrez les valeurs allouées de ressources pour le processus " << i << " (" << m << " valeurs) : ";
    std::vector<int> V;
    for (int j = 0; j < m; j++){
      int v;
      std::cin >> v;
      V.push_back(v);
    }
    Allocation.push_back(V);
  }

//Calcul de la matrice Besoin
  for (int i = 0; i < n; i++){
    std::vector<int> V;
    for (int j = 0; j < m; j++){
      V.push_back(Max[i][j]-Allocation[i][j]);
    }
    Besoin.push_back(V);
  }

  displayVecteur(Disponible,"Disponible");
  displayMatrice(Max,"Maximum");
  displayMatrice(Allocation,"Allocation");
  displayMatrice(Besoin,"Besoin");

//Calcul des ressources disponibles
  for (int i = 0; i < m; i++){
    int sommeRessources=0;
    for (int j = 0; j < n; j++){
      sommeRessources += Allocation[j][i];
    }
    Disponible[i]=Disponible[i]-sommeRessources;
  } 
  std::cout << "Calcul des ressources disponibles..." << std::endl; 
  displayVecteur(Disponible,"Disponible"); 

  for (int i=0; i < n; i++){
    Termine.push_back(false);
  } 

  std::cout << "Début de l'algorithme du banquier..." << std::endl;

  if (TestSur(Besoin, Allocation, Disponible, Termine)) std::cout << "L'état initial est sûr" << std::endl;
  else std::cout << "L'état initial n'est pas sûr" << std::endl;
  

  return 0;

}
