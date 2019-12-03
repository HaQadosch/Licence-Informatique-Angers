#include<cstdlib>

class Proprietaire{
	public:
		enum class type{
				PersPhysique,
				Couple,
				Societe
		};
		virtual type typeProg() const =0;
		virtual std::string nom() const =0;
		virtual ~Proprietaire() =default;
		virtual std::string const & adresse() const=0;
		std::string etiquetteExpedition() const;
		virtual void sortieFlux(std::ostream & os) const;
	private:

};

std::ostream & operator<<(std::ostream &os, Proprietaire const &p);

class PersPhysique:public Proprietaire{
	public:
		virtual void sortieFlux(std::ostream & os) const override;
		std::string const & adresse() const override;
		type typeProg() const override;
		std::string nom() const override;
	private:
		std::string dateNaiss;
		std::string nom;
		std::string adresse;
};

class Couple:public Proprietaire{
	public:
		virtual void sortieFlux(std::ostream & os) const override;
		std::string const & adresse() const override;
		type typeProg() const override;
		std::string nom() const override;
		static std::shared_ptr<Couple> fabrique(std::shared_ptr<Couple>p1 ,std::shared_ptr<Couple> p2){
			if(p1->adresse()==p2->adresse())
				return std::shared_ptr<Couple>(new Couple(p1,p2));
			else
				return nullptr;
		}
		Proprietaire() =default;
		Proprietaire(Proprietaire const & p) =delete; // interdiction de la copie
		Proprietaire & operator=(Proprietaire const & p)=delete;
	private:
		Couple(std::shared_ptr<PersPhysique> p1,std::shared_ptr<PersPhysique> p2);
			Proprietaire(),p1(p1),p2(p2){}
		std::shared_ptr<PersPhysique> p1;
		std::shared_ptr<PersPhysique> p2;
};

class Societe:public proprietaire{
	public:
		virtual void sortieFlux(std::ostream & os) const override;
		std::string const & adresse() const override;
		type typeProg() const override;
		std::string nom() const override;
	private:
		std::string nom;
		std::string adresse;
		std::shared_ptr<Proprietaire *> proprio;

};
