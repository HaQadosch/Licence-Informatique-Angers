#include "Document.hh"
#include <vector>
class Bibliotheque{
	public:
		Bibliotheque() =default;
		~Bibliotheque();
		void ajout(Document const & d);
		std::size_t taille() const {return contenu.size();}
		Document const & acces(std::size_t i) {return *(contenu.at(i));}

	private:
		std::vector<Document *> contenu;
};
