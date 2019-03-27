import java.util.Comparator;

public class SortByPIBHbt implements Comparator<Region>{

  public int compare(Region reg1,Region reg2){
    return((reg1.PIB/reg1.POP)-(reg2.PIB/reg2.POP));
  }

}
