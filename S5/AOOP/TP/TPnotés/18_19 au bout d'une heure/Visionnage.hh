#include <string>
#include <cstdlib>

class Visionnage{
	public:
		//constructeur
		Visionnage()=default;
		//accesseur
		std::string getNom(){return nom;}
		unsigned int getDate(){return date;}
		virtual std::string typeVisionnage() const =0;

	private:
		unsigned int date;
		std::string nom;
};

class Film:public Visionnage{
	public:
		//constructeur
		Film(std::string name,unsigned int when,std::string who):
			date(when),nom(name),realis(who){};
		//accesseur
		std::string getNom();
		unsigned int getDate();
		std::string getRealis(){return realis;}
		std::string typeVisionnage() const override {return "Film";}

	private:
		unsigned int date;
		std::string nom,realis;

};
/*
class Serie::public Visionnage{

}
*/
