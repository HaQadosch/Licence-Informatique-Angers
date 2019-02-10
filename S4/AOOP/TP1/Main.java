
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
