package battleship;

public class Coordinates {
	private int x;
	private int y;
	
	public Coordinates(int x, int y) {
		// TODO Auto-generated constructor stub
		this.x = x;
		this.y = y;
	}
	
	public int getX() {
		return x;
	}
	
	public int getY() {
		return y;
	}
	
	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		if(obj instanceof Coordinates) {
			return ((Coordinates) obj).getX() == x && ((Coordinates) obj).getY() == y;
		} else return false;
	}
	
	@Override
	public int hashCode() {
		// TODO Auto-generated method stub
		return 31 * x + y;
	}
}
