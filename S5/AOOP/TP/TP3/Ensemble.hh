#include <stdio.h>
#include <stdlib.h>

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


  protected:
    /*méthodes*/
    virtual void ajoutersansverif(int e) =0;

  private:
    /*variables*/
};
