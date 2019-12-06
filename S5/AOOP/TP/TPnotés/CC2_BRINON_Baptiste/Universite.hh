#include "Enseignement.hh"
#include "Personnes.hh"
#include <memory>

class Universite{
public:
	Universite()=default;
private:
	std::vector<std::shared_ptr<Enseignement>>listEnseign;
	std::vector<std::shared_ptr<Personne>> listPerso;
};
