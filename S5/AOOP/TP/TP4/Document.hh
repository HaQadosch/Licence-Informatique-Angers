#include <string>
#include <iostream>

class Document{
	public:
		Document(std::string const &t, std::string const &a):
		titre(t),auteur(a){}
		virtual ~Document() =default;
		virtual bool empruntable() const =0;
		virtual float prix() const =0;
		virtual void sortieFlux(std::ostream & os) const;
		virtual std::string typeDoc() const;
		virtual Document * clone() const =0:
		
	private:
		std::string titre;
		std::string auteur;
};
std::ostream & operator<<(std::ostream & os, Document const & d);

enum class TypeVideo{
	DVD,BR,BR3D
};

class Video:public Empruntable{
	public:
		video(std::string const & t,st::string const & a , TypeVideo v);
			Document(t,a), Type(v){}
		bool empruntable() const override;
		float prix() const override;
		std::string typeDoc() const override {return "video";}
		void sortieFlux(std::ostream & os) const;
		Document * clone() const override;
	private:
		TypeVideo type;
};


class DocEcrit{
	public:
		DocEcrit(std::string const &t,std::string const &a, unsigned int p):
			Document(t,a),pages(p){}
		float prix() const override;
		void sortieFlux(std::ostream & os) const;
	private:
		unsigned int pages;

};

class Periodique:public DocEcrit{
public:
	Livre(std::string const &t,std::string const &a, unsigned int p, unsigned int n):
		:DocEcrit(t,a,p),numero(n){}
	bool empruntable() const override;
	std::string typeDoc() const override {return "periodique";}
	void sortieFlux(std::ostream & os) const;
	Document * clone() const override;
	private:
		unsigned int numero;
};

class Livre:public DocEcrit{
	public:
		Livre(std::string const &t,std::string const &a, unsigned int p, bool e):
			:DocEcrit(t,a,p),empruntable(e){}
		bool empruntable() const override;
		std::string typeDoc() const override {return "livre";}
		Document * clone() const override;
	private:
		bool empruntable;
};
