public class Execute{

  public static void main(String[] args){
    Tonneau téofon= new Tonneau("téofon",5,1,null,true);
    Tonneau téodessus= new Tonneau("téodessus",12,4,téofon,true);
    téofon.setEntree(téodessus);

    téodessus.start();
    téofon.start();

  }
}
