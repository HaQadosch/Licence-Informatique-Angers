public class Test {

	public static void main(String[] args) {
		//test Cercle
		Point p9=new Point(8.0,8.0);
		Cercle circus=new Cercle("Circus",p9,4.0);
		System.out.println(circus);

		//test Polygones
		Point p1=new Point(2.0,7.0);
		Point p2=new Point(4.0,7.0);
		Point p3=new Point(4.0,0.0);
		Point p4=new Point(2.0,0.0);


		Rectangle carre= new Rectangle("rect");
		carre.listePoints.add(p1);
		carre.listePoints.add(p2);
		carre.listePoints.add(p3);
		carre.listePoints.add(p4);

		System.out.println("Perimetre d'un Rectangle quelconque");
		System.out.println(" valeur attendue:18.0 \n valeur obtenue:"+carre.perimetre());

		System.out.println(carre);

		Triangle tritri=new Triangle("tritri");
		Point p5=new Point(2.0,7.0);
		Point p6=new Point(4.0,14.0);
		Point p7=new Point(6.0,7.0);
		tritri.listePoints.add(p5);
		tritri.listePoints.add(p6);
		tritri.listePoints.add(p7);
		System.out.println(tritri);

		//test translation Point
		Point p8=new Point(1.0,1.0);
		System.out.println("translation de "+p8+" par un vecteur 4.0,1.0. résultat:");
		p8.translation(4.0,8.0);
		System.out.println(p8);
		//test translation Cercle

		System.out.println("translation du cercle"+circus+"par un vecteur 4.0,1.0. résultat:");
		circus.translation(4.0,1.0);
		System.out.println(circus);

		//test translation Polygone
		System.out.println("translation du triangle"+tritri+"par un vecteur 4.0,1.0. résultat:");
		tritri.translation(4.0,1.0);
		System.out.println(tritri);
  }
}
