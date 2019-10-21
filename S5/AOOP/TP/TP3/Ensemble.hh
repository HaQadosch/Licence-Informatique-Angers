#include <stdio.h>
#include <stdlib.h>

class Parcours{
  public:
    Parcours()
      :pos(0) ();
    std:size_t position() const{
      return pos;
    }
    void suivant(){
      pos++;
    }
  private:
    std::size_t pos;

};

class Ensemble{
  public:
    /*constructeurs*/
    Ensemble()=default;
    Ensemble(Ensemble const & copied)=default;
    ~Ensemble()=default;

    /*méthodes*/
    virtual bool appartient (int e) const =0;
    virtual bool estVide() const =0;
    void ajouter(int e);
    virtual void afficher1() const =0;
    void afficher() const;
    virtual void enlever(int e) =0;

    virtual parcours commencer() const;
    virtual bool estFini(parcours const & p) const;
    virtual void suivant(parcours & p) const;
    virtual int acces(parcours const & p) const;

  protected:
    /*méthodes*/
    virtual void ajouterSansVerif(int e) =0;

  private:
    /*variables*/
};
