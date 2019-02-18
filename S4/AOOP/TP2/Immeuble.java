
public class Immeuble extends Batiment {

	int nbAppart;
	
	public Immeuble(String adresse, int surfaceHabitable, int nbAppart) {
		super(adresse, surfaceHabitable);
		this.nbAppart=nbAppart;
	}

	public String toString() {
		return "Immeuble [" + super.toString() + "nbAppart=" + nbAppart + "] ";
	}

	
}
