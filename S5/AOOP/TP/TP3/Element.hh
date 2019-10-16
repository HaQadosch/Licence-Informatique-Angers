#include <string>

class Element{
  public:
    /*fonctions*/
      /////////////////////////
      /*std::string toString() const{
        return
      }*/
    /*constructeurs*/
    Element(position const & pos, taille const & tai);
    /*getters&setters*/
    position getPos(){return pos;}
    taille getTai(){return tai;}
    void setPos(position nouv){pos=nouv;}
    void setTai(taille nouv){tai=nouv;}

    /*variables*/
  private:
    position pos;
    unsigned int tai;
}

class Obstacle : public Element{
  public:
    /*constructeurs*/
    Obstacle(position const & pos, taille const & tai)
      :Element(post, tai){};
}

class ObjetRamassable{
  public:
    /*constructeurs*/
    ObjetRamassable(position const & pos, taille const & tai, unsigned int nbpoints)
      :Element(pos, tai), _nbpoints(nbpoints){};

    /*setters & getters*/
    unsigned int nbPoints() const{return nbPoints; }

  private:
    /*variables*/
    unsigned int nbPoints;
}

class Personnage:public Element{
  public:
    /*fonctions*/
    void ramasser(ObjetRamassable const & o){
      nbPoints += o.nbPoints();
    }
    std::string toString() const{
      return element::tostring()+"-"+nom+"-"+std::string(nbPoints);
    }

    /*constructeurs*/
    Personnage(position const & pos,taille const & taille,std::string const & nom)
      :Element(pos,taille), _nom(nom), _nbPoints(0){}

    /*setter&getters*/

    /*variables*/
  private:
    std::string nom;
    unsigned int nbPoints;
}
