#include "Position.hh"

enum class Couleur{
	noir,
	blanc
};

class Piece{
	public:
		Piece(Position const &p, Couleur c):
			pos(p),coul(c){};
		virtual ~Piece() =default;
		virtual char symbole() const =0;
		virtual int valeur() const=0;
		Couleur getCoul() const {return coul;}
		Position const & getPos() const {return pos;}
		std::string toString() const;
		bool accepterPosition(Position const & p)const;
	private:
		Position pos;
		Couleur coul;
};

class Pion:public Piece{
	public:
		Pion(Position const &p, Couleur c):
			Piece(p,c){};
		char symbole() const override;
		int valeur() const override;
};


class Cavalier:public Piece{
	public:
		Cavalier(Position const &p, Couleur c):
			Piece(p,c){};
		char symbole() const override;
		int valeur() const override;
};


class Dame:public Piece{
	public:
		Dame(Position const &p, Couleur c):
			Piece(p,c){};
		char symbole() const override;
		int valeur() const override;
};


class Roi:public Piece{
	public:
		Roi(Position const &p, Couleur c):
			Piece(p,c){};
		char symbole() const override;
		int valeur() const override;
};
