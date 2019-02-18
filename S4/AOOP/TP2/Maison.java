
public class Maison extends Batiment {

	int nbPieces;
	int surfaceJardin;
	
	public Maison(String adresse, int surfaceHabitable, int nbPieces, int surfaceJardin) {
		super(adresse, surfaceHabitable);
		this.nbPieces=nbPieces;
		this.surfaceJardin=surfaceJardin;
	}

	public String toString() {
		return "Maison [" + super.toString() + "nbPieces=" + nbPieces + ", surfaceJardin=" + surfaceJardin + "] ";
	}
	
	

}
