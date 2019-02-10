public class Vehicule {
	String modele;
	int anneeAchat;
	double prixAchat;
	String immat;
	char permis;
	
	public Vehicule(String nModele, int nAnneeAchat, double nPrixAchat, String nImmat,char nPermis){
		this.modele=nModele;
		this.anneeAchat=nAnneeAchat;
		this.prixAchat=nPrixAchat;
		this.immat=nImmat;
		this.permis=nPermis;
	}
	
	public int age(){
		return(2019-this.anneeAchat);
	}
	
	public void afficherVehicule(){
		System.out.println("Je suis le véhicule "+this.modele+this.immat+" j'ai été acheté en "+this.anneeAchat+" à "+this.prixAchat+" $");
		System.out.println("Si tu veux me louer, il te faut le permis "+this.permis+" et je vais te couter "+this.coutLocation()+" $ par mois");
	}
	
	public double coutLocation(){
		if(this.age()<1) return (prixAchat/200.00);
		else return(prixAchat/250.00);
	}
	
}