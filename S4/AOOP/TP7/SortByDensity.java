import java.util.Comparator;

public class SortByDensity implements Comparator<Region>{

  public int compare(Region reg1,Region reg2){
    int num1=reg1.POP/reg1.Superficie;
    int num2=reg2.POP/reg2.Superficie;
    return(num1-num2);
  }

}
