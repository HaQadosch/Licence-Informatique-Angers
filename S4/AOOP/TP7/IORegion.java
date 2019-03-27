import java.io.IOException;
import java.util.Collection;
import java.util.ArrayList;

public interface IORegion {
  public ArrayList<Region> lire(String fileName)throws IOException;
  public void sauver(ArrayList<Region> regions, String fileName)throws IOException;
}
