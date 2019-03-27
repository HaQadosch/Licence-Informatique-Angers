import java.io.IOException;
import java.util.Collection;

public interface IOForme {
  public Collection<Forme> lire(String fileName)throws IOException;
  public void sauver(Collection<Forme> formes, String fileName)throws IOException;
}
