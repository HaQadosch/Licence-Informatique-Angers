import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DateFormat;
import java.util.Date;

public class Calculatrice extends Exception{
  private double nb1=0;
  private double nb2=0;
  private String oper="";
  private double result=0;

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

      this.nb1=this.saisieNombre();
      this.oper=saisieOperation();
      this.nb2=this.saisieNombre();
      switch(this.oper){
        case "+":  this.result=(nb1+nb2);break;
        case "-":  this.result=(nb1-nb2);break;
        case "*":  this.result=(nb1*nb2);break;
        case "/":  this.result=(nb1/nb2);break;
        default: this.result=(-1);break;
      }
      try{
        this.sauvegarder();
      } catch(IOException e){
        System.out.println("erreur lors de l'enregistrement de l'operation");
      }
      return this.result;
  }

  public void sauvegarder() throws IOException {
    try{
      FileWriter w = new FileWriter("log.txt",true);
      DateFormat fullDateFormat = DateFormat.getDateTimeInstance(DateFormat.FULL,DateFormat.FULL);
      w.write("||" + nb1 + oper + nb2 + "=" + result + " ||--> le " + fullDateFormat.format(new Date()) + "\n");
      w.close();
    } catch(IOException e){
      throw e;
    }
  }

}
