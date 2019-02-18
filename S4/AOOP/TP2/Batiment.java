/**
* la classe Batiment correspond aux batiments,
* elle est hérité de Immeuble et Maison, contient une adresse et une surface habitable
* @author Brinon Baptiste
*/
public class Batiment {
	/**
	* l'adresse designe la localisation du batiment
	*/
	String adresse;
	/**
	* la surfaceHabitable designe la surface utilisable par les utilisateur
	*/
	int surfaceHabitable;

	/**
	* constructeur de la classe  Batiment
	* @param adresse adresse à attribuer à l'Objet
	* @param surfaceHabitable surface à attribuer à l'Objet
	*/
	public Batiment(String adresse, int surfaceHabitable) {
		this.adresse = adresse;
		this.surfaceHabitable = surfaceHabitable;
	}
	/**
 	* méthode correspondant à l'affichage de l'objet quand il est appellé
	* @return retourne la chaine de caractère affichée
	*/
	public String toString() {
		return "Batiment [adresse=" + adresse + ", surfaceHabitable=" + surfaceHabitable + "] ";
	}

	/**
	* permet de connaitre la catégorie du batiment en fonction de sa surfaceHabitable
	*@return retourne l'entier correspondant à la categorie
	*/
	public int categorie(){
		if(surfaceHabitable<30) return 1;
		else if(surfaceHabitable<=70) return 2;
		else return 3;
	}

	/**
	* determine, entre deux batiments, celui avec le plus de surfaceHabitable
	* @param batim batiment comparé à l'Objet
	* @return retourne le batiment le plus spacieux
	*/
	public Batiment comparer(Batiment batim){
		if(this.surfaceHabitable>batim.surfaceHabitable) return(this);
		else return(batim);
	}

}
