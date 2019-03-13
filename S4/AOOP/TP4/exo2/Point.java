public class Point{
  double x,y;

  public Point(double x,double y){
    this.x=x;
    this.y=y;
  }

  double distance(Point arriv){
    return(Math.sqrt(Math.pow(arriv.x-this.x,2.0)+Math.pow(arriv.y-this.y,2.0)));
  }

  public String toString(){
    return "Point[x="+x+",y="+y+"]";
  }

  public void translation(double vx,double vy){
    this.x=x+vx;
    this.y=y+vy;
  }

}
