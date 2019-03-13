import java.util.Scanner;

public class Calculatrice extends Exception{

  public double saisieNombre(){
    System.out.println("saisissez un nombre");
    int error=0;
    double i=0.0;
    Scanner sc = new Scanner(System.in);
    do{
      try{
        error=0;
        i = sc.nextDouble();
      } catch(Exception e){
        error=1;
        System.out.println("saisissez un nombre VALIDE");
      }
    } while (error==1);
    return i;
  }

  public String saisieOperation(){
    System.out.println("saisissez un operateur");
    int error=0;
    String op="";
    Scanner sc = new Scanner(System.in);
    do{
      try{
        error=0;
        op = sc.next();
      } catch(Exception e){
        error=1;
        System.out.println("saisissez un operateur VALIDE");
      }

      if(!op.equals("+") && !op.equals("-") && !op.equals("*") && !op.equals("/")){
        error=1;
        System.out.println("saisissez un operateur VALIDE");
      }
    } while (error==1);
    return op;
  }

  public double lancementCalcul(){

      double x=this.saisieNombre();
      String oper=saisieOperation();
      double y=this.saisieNombre();
      switch(oper){
        case "+":  return(x+y);
        case "-":  return(x-y);
        case "*":  return(x*y);
        case "/":  return(x/y);
        default: return(-1);
      }
  }
}
