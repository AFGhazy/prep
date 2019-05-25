package battleship;

public enum ShipType {
	DESTROYER(1),
	CRUISER(3),
	AIRCRAFTCARIER(5);
	
	private int size;
	
	private ShipType(int size) {
		// TODO Auto-generated constructor stub
		this.size = size;
	}
	
	public int getSize() {
		return size;
	}
}
