package battleship;

public abstract class Ship {
	private Layout layout;
	private ShipType shipType;
	private Coordinates coordinates;
	
	public Ship(Coordinates coordinates, Layout layout, ShipType shipType) {
		// TODO Auto-generated constructor stub
		this.coordinates = coordinates;
		this.layout = layout;
		this.shipType = shipType;
	}
	
	public Layout getLayout() {
		return layout;
	}
	
	
	public ShipType getShipType() {
		return shipType;
	}
	
	public Coordinates getCoordinates() {
		return coordinates;
	}
}
