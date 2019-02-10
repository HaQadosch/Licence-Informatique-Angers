
public class Voiture extends Vehicule {

	private boolean autoRadio;
	
	public Voiture(String nModele, int nAnneeAchat, double nPrixAchat,String nImmat, char nPermis, boolean nAutoRadio) {
		super(nModele, nAnneeAchat, nPrixAchat, nImmat, nPermis);
		this.autoRadio=nAutoRadio;
	}

	public void ajouterAutoradio(){
		this.autoRadio=true;
	}
	
	public void enleverAutoradio(){
		this.autoRadio=false;
	}
	
	public void afficherVoiture(){
		super.afficherVehicule();
		if(this.autoRadio==true){
			System.out.println("Je dispose même d'une autoradio ! \n");
		}else{
			System.out.println("Mais malheureusement, je n'ai pas d'autoradio \n");
		}
	}
	
}
