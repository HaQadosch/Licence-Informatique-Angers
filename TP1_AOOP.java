// Vehicule.java

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

//Voiture.java


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

//Camion.java


public class Camion extends Vehicule {

	private double volumeStockage;
	
	public Camion(String nModele, int nAnneeAchat, double nPrixAchat, String nImmat, char nPermis,double nVolumeStockage) {
		super(nModele, nAnneeAchat, nPrixAchat, nImmat, nPermis);
		this.volumeStockage=nVolumeStockage;
	}

	public boolean peutTransporterVolume(double volumeTest){
		return (volumeStockage>volumeTest);
	}

	public void afficherCamion(){
		super.afficherVehicule();
		System.out.println("Je dispose en plus d'un volume de stockage de "+this.volumeStockage+"kg");
	}
	
}

//Autocar.java


public class Autocar extends Camion {
	
	private int nbPassager;
	
	public Autocar(String nModele, int nAnneeAchat, double nPrixAchat, String nImmat, char nPermis, double nVolumeStockage, int nNbPassager) {
		super(nModele, nAnneeAchat, nPrixAchat, nImmat, nPermis, nVolumeStockage);
		this.nbPassager=nNbPassager;
	}

	public boolean peutTransporterPassager(int nbNouvPassager, double volumepPassager){
		return((nbNouvPassager<nbPassager) && (this.peutTransporterVolume(nbNouvPassager*volumepPassager)));
	}

	public void afficherAutocar(){
		super.afficherCamion();
		System.out.println("Je peux transporter "+this.nbPassager+" personnes");
	}
}

//Main.java

public class Main {

	public static void main(String[] args){
	
		Voiture cars=new Voiture("Twingo", 2008 ,10000.00,"AB-123-CD",'B',true);
		cars.afficherVoiture();
		
		Camion Kamthaar=new Camion("J9", 2008 , 20000.00,"1234-AB-56",'B',25.00);
		Kamthaar.afficherCamion();
		System.out.println("Voyons s'il peut transporter 7kg");
		System.out.println(Kamthaar.peutTransporterVolume(7));
		
		Autocar BusMagique=new Autocar("FRI",2005,90000.00,"123-AB-45",'D',3.00,53);
		BusMagique.afficherAutocar();
		System.out.println("voyons s'il peut transporter 40 passagers avec 0,1kg de bagages chacun");
		System.out.println(BusMagique.peutTransporterPassager(40,00.10));
		
		
	}
	
}
