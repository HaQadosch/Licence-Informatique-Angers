//.hh
class element.cc{
  public:
    /*fonctions*/

    /*constructeurs*/
    void Name();

    /*setters & getters*/
    type get_var() const {return this._var;}
    void set_var(type var){this._var=var};

  private:
    /*variables*/
    type _var
}

class obstacle : public element{
  public:
    /*constructeurs*/
    obstacle(position const & pos, taille const & tai):element(post, tai){};
}

class ObjetRamassable{
  public:
    /*constructeurs*/
    ObjetRamassable(position const & pos, taille const & tai, unsigned int nbpoints):element(pos, tai), _nbpoints(nbpoints){};

    /*setters & getters*/
    unsigned int nbpoints() const{return nbPoints; }

  private:
    /*variables*/
    unsigned int nbPoints;
}
