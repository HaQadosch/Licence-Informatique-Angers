#include <stdio.h>
#include <stdlib.h>

class Ensemble{
  public:
    /*fonctions*/
    virtual bool appartient (int e) const =0;
    virtual bool estVide() const =0;
    /*constructeurs*/
    Ensemble()=default;
    Ensemble(Ensemble const & copied)=default;
    ~Ensemble()=default;


  private:
    /*variables*/
};
