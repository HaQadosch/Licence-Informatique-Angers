/**
* la classe Immeuble correspond aux immeubles,
* elle herite de Batiment, et contient des appartements
* @author Brinon Baptiste
*/
public class Immeuble extends Batiment {
	/**
	* nbAppart désigne le nombre d'appartements dans l'immeuble
	*/
	int nbAppart;

	/**
	* constructeur de la classe immeuble
	* @param adresse adresse à attribuer à l'Objet
	* @param surfaceHabitable surface à attribuer à l'objet
	* @param nbAppart noombre d'appartements à attribuer à l'Objet
	*/
	public Immeuble(String adresse, int surfaceHabitable, int nbAppart) {
		super(adresse, surfaceHabitable);
		this.nbAppart=nbAppart;
	}
	/**
 	* méthode correspondant à l'affichage de l'objet quand il est appellé
	* @return retourne la chaine de caractère affichée
	*/
	public String toString() {
		return "Immeuble [" + super.toString() + "nbAppart=" + nbAppart + "] ";
	}


}
