#include "Ensemble.hh"
#include <vector>

class EnsembleVector: public Ensemble{
  public:
    /*fonctions*/
    bool appartient(int e) const override;
    bool estVide() const override;
    /*constructeurs*/
    EnsembleVector()=default;
    EnsembleVector(EnsembleVector const & copied)=default;
    ~EnsembleVector()=default;
  private:
    /*variables*/
    std::vector<int> elem;
};
