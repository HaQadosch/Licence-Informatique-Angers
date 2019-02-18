/**
* la classe Maison correspond aux maisons,
* elle herite de Batiment et contient des pieces et un jardin
* @author Brinon Baptiste
*/
public class Maison extends Batiment {
	/**
	* nbPieces désigne le nombre de pieces que contient la maison
	*/
	int nbPieces;
	/**
	* surfaceJardin designe la surface du jardin de la maison ( peut être nulle )
	*/
	int surfaceJardin;

	/**
	* constructeur de la classe maison
	* @param adresse adresse à attribuer à l'Objet
	* @param surfaceHabitable surface à attribuer à l'Objet
	* @param nbPieces nombre de pieces attribué à l'Objet
	* @param surfaceJardin surface de jardin à attribuer à l'Objet
	*/
	public Maison(String adresse, int surfaceHabitable, int nbPieces, int surfaceJardin) {
		super(adresse, surfaceHabitable);
		this.nbPieces=nbPieces;
		this.surfaceJardin=surfaceJardin;
	}
	/**
 	* méthode correspondant à l'affichage de l'objet quand il est appellé
	* @return retourne la chaine de caractère affichée
	*/
	public String toString() {
		return "Maison [" + super.toString() + "nbPieces=" + nbPieces + ", surfaceJardin=" + surfaceJardin + "] ";
	}

}
