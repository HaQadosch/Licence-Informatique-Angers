#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

void matrixDisplay(std::vector< std::vector<int> > M, std::vector<int> C){
	std::cout << "###### Affichage de la matrice ######" << std::endl;
	auto it2 = C.begin();
	for (auto it = M.begin(); it < M.end(); it++){
		std::cout << "[ ";
		for (auto itt = it->begin(); itt < it->end(); itt++){
			std::cout << *itt << " ";
		}
		std::cout << "] "; 
		if (*it2 != 0) std::cout << "P" << *it2;
		else std::cout << "-";
		std::cout << std::endl;
		it2++;
	}
}

void secondeChanceDisplay(std::deque<bool> reference, std::deque<int> file,  int nbcadres){
	std::cout << "###### Affichage du tableau ######" << std::endl;
  int cpt=0;
  std::cout << "|";
	while (!reference.empty()){
      cpt++;
			std::cout << reference.front() << "|";
      reference.pop_front();
  }
  for (int i=cpt;i<nbcadres;i++)
    			std::cout << " |";
  std::cout  << std::endl;
  cpt=0;
  std::cout << "|";
	while (!file.empty()){
      cpt++;
			std::cout << file.front() << "|";
      file.pop_front();
  }
  for (int i=cpt;i<nbcadres;i++)
    			std::cout << " |";
  std::cout  << std::endl;
}

void LRU(std::vector<int> cadres, std::vector<int> pagesList, int nbcadres){
	std::vector< std::vector <int> > matrix;
  int defauts=0;
	for (int i = 0; i<nbcadres; i++){
		std::vector<int> tmp;
		for (int j=0; j<nbcadres; j++){
			tmp.push_back(0);
		}
		matrix.push_back(tmp);
		cadres.push_back(0);
	}

  	matrixDisplay(matrix,cadres);
	for (auto currentP = pagesList.begin(); currentP<pagesList.end(); currentP++){
		std::cout << std::endl << "Demande de P" << *currentP << std::endl;
		bool cadreDispo = false;
		int indexTmp=0;
		for (auto currentC = cadres.begin(); ((currentC < cadres.end()) && (!cadreDispo)); currentC++){
			if ((*currentC == *currentP) || (*currentC == 0)) {cadreDispo=true; *currentC=*currentP;
				for (auto it = matrix[indexTmp].begin(); it < matrix[indexTmp].end(); it++) *it = 1;
				for (auto it = matrix.begin(); it < matrix.end(); it++) (*it)[indexTmp] = 0;
			} 
			indexTmp++;
		}
		if (!cadreDispo){
			int min = pow(2,nbcadres);
			int minIndex = 0;
      defauts++;
			for (int i = 0; i < matrix.size(); i++){
				int somme=0;
				for (int j = 0; j < matrix[i].size(); j++){
					if (matrix[i][j]) somme += pow(2,matrix[i].size()-(j+1));
				}
				if (somme < min) {min=somme; minIndex=i;}
			}
			cadres[minIndex]=*currentP;
			for (auto it = matrix[minIndex].begin(); it < matrix[minIndex].end(); it++) *it = 1;
			for (auto it = matrix.begin(); it < matrix.end(); it++) (*it)[minIndex] = 0;
		}
		matrixDisplay(matrix,cadres);
  }
  std::cout << "Nombre de défauts : " << defauts << std::endl;
}

int positionInQueue(std::deque<int> file, int value){
  int i=0;
  while(!file.empty()){ 
    if (file.front() == value) return i;
    else {i++; file.pop_front();}
  }
  return -1;
}

void secondeChance(std::queue<int> pagesList, int nbcadres){
  std::deque<int> file;
  std::deque<bool> reference;
  bool full=false;
  int defauts=0;

  while(!pagesList.empty()){
    std::cout << "Demande de P" << pagesList.front() << std::endl;
    if (full){
      int position = positionInQueue(file,pagesList.front());
      if (position == -1){
        defauts++;
        while (reference.front()){
          reference.pop_front();
          reference.push_back(false);
          file.push_back(file.front());
          file.pop_front();
        }
        file.pop_front();
        reference.pop_front();
        file.push_back(pagesList.front());
        reference.push_back(false);
      }
      else reference[position]=1;
      pagesList.pop();      
    }
    else{
      int position = positionInQueue(file,pagesList.front());
      if (position == -1){
        file.push_back(pagesList.front());
        reference.push_back(false);
      }
      else reference[position]=1;
      pagesList.pop();      
    }

    full=(file.size() == nbcadres);
    secondeChanceDisplay(reference,file,nbcadres);
    std::cout<<std::endl;
  }
  std::cout << "Nombre de défauts : " << defauts << std::endl;
}

int positionInVector(std::vector<int> tableau, int value){
  for (int i = 0; i < tableau.size(); i++)
    if (tableau[i] == value) return i;  
  return -1;
}

int positionInPagesList(std::queue<int> pagesList,int value){
  int i=0;
  while(!pagesList.empty()){
    if (pagesList.front()==value) return i;
    else{
      i++;
      pagesList.pop();
    }
  }
  return i;
}

int choixCadre(std::queue<int> pagesList, std::vector<int> tableau){
  int index=tableau.size();
  int max=-1;
  for (int i = 0; i<tableau.size(); i++){
    int position = positionInPagesList(pagesList, tableau[i]);
    if (position > max) {max = position; index=i;}
  }
  return index;
}

void optimalDisplay(std::vector<int> tableau,  int nbcadres){
	std::cout << "###### Affichage du tableau ######" << std::endl;
  int cpt=0;
  std::cout << "|";
	for (auto i = tableau.begin();i<tableau.end(); i++){
      cpt++;
			std::cout << *i << "|";
  }
  for (int i=cpt;i<nbcadres;i++)
    			std::cout << " |";
  std::cout  << std::endl;
  std::cout  << std::endl;
}

void optimal(std::queue<int> pagesList, int nbcadres){
  std::vector<int> tableau;
  int defauts=0;
  bool full=false;
  while(!pagesList.empty()){
    std::cout << "Demande de P" << pagesList.front() << std::endl;
    if (full){
      if (positionInVector(tableau,pagesList.front())==-1){
        defauts++;
        tableau[choixCadre(pagesList,tableau)]=pagesList.front();
      }
    }
    else{
      if (positionInVector(tableau,pagesList.front())==-1){
        tableau.push_back(pagesList.front());
      }
      if (tableau.size()==nbcadres) full=true;
    }
    pagesList.pop();
    optimalDisplay(tableau,nbcadres);
  } 
  std::cout << "Nombre de défauts " << defauts << std::endl;
}

int main(){

	std::vector<int> cadres;
	int nbcadres = 0;
	
	do{
	std::cout << "Entrez le nombre de cadres souhaités : ";
	std::cin >> nbcadres;
	}while (nbcadres < 1);

  std::vector<int> pagesList;
	std::queue<int> pagesListQ;
	int pageNb = 0;
	do{
		std::cout << "Entrez le numéro de la prochaine page : ";
		std::cin >> pageNb;
		if (pageNb > 0) {pagesList.push_back(pageNb); pagesListQ.push(pageNb);}
	}while (pageNb > 0);

  std::cout << std::endl;
  std::cout << "++++ Début de l'agorithme LRU ++++" <<std::endl;
  LRU(cadres, pagesList, nbcadres);
  std::cout << std::endl;
  std::cout << "++++ Début de l'agorithme seconde chance ++++" <<std::endl;
  secondeChance(pagesListQ, nbcadres);
  std::cout << "++++ Début de l'agorithme optimal ++++" <<std::endl;
  optimal(pagesListQ, nbcadres);  

	return 0;
}
