
public class Batiment {
	String adresse;
	int surfaceHabitable;
	
	public Batiment(String adresse, int surfaceHabitable) {
		this.adresse = adresse;
		this.surfaceHabitable = surfaceHabitable;
	}

	public String toString() {
		return "Batiment [adresse=" + adresse + ", surfaceHabitable=" + surfaceHabitable + "] ";
	} 
	
	public int categorie(){
		if(surfaceHabitable<30) return 1;
		else if(surfaceHabitable<=70) return 2;
		else return 3;
	}
	
}
