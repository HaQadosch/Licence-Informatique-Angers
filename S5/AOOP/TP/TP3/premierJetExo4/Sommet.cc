#include "Sommet.hh"

identifiant Sommet::compteur(0);

Sommet::Sommet(std::string const & et)
    :id(++compteur),etiquette(et){
}

void Sommet::ajouterArc(identifiant etc, std::string const & etiq){
  std::list<arcSortant>::iterator it=arcs.begin();
  while(it!=arcs.end() && ((*it).extremite != ext))
    ++it;
  if(it==arcs.end()){
    arcs.push_back(arcSortant{ext, etiq});
  }else{
    (*it).etiquette=etiq;
  }
}


void supprimerArc(identifiant ext){
  std::list<arcSortant>::iterator it=arcs.begin();
  while(it!=arcs.end() && ((*it).extremite != ext))
    ++it;
  if(it != arcs.end())
    arcs.erase(it);
  /*
  for(auto i=arc.begin() ... ){
    if((*i).ext == ext)
      arcs.erase(i); // faux car erase invalide les iterateurs
  }*/
}
