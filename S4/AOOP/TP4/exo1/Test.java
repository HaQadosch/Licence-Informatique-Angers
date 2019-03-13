import java.util.*;

public class Test {
	
	public static void main(String[] args) {
		Oiseau oisal=new Oiseau(5,4);
		Poisson poisseSon=new Poisson(3,5);
		Oiseau oiezo=new Oiseau(20,4);
		
		Animal[] zoo=new Animal[3];
		zoo[0]=oisal;
		zoo[1]=poisseSon;
		zoo[2]=oiezo;
		
		for(int i=0;i<3;i++){
			System.out.println("animal["+i+"] ");
			zoo[i].manger();
		}
		
		ArrayList<Volant> listeVolants = new ArrayList<Volant>();
	}
}
