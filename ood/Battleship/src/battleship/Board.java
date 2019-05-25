package battleship;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class Board {
	String playerName;
	public final static int SIZE = 20;
	private Set<Coordinates> coordinates = new HashSet<Coordinates>();
	
	Map<ShipType, Integer> remaining = new HashMap<ShipType, Integer>() {{
		put(ShipType.DESTROYER, 2);
		put(ShipType.CRUISER, 2);
		put(ShipType.AIRCRAFTCARIER, 1);
	}};
	
	public Board(String playerName) {
		// TODO Auto-generated constructor stub
		this.playerName = playerName;
	}
	
	public boolean layShip(Ship ship) {
		Coordinates c = ship.getCoordinates();
		
		if(c.getX() < 0 || c.getX() > SIZE) return false;
		if(c.getY() < 0 || c.getY() > SIZE) return false;
		
		if(ship.getLayout() == Layout.HORIZONTAL && c.getX() + ship.getShipType().getSize() >= SIZE) return false;
		if(ship.getLayout() == Layout.VERTICAL && c.getY() + ship.getShipType().getSize() >= SIZE) return false;
		
		Set<Coordinates> tmp = new HashSet<Coordinates>();
		if(ship.getLayout() == Layout.HORIZONTAL) {
			for(int x = ship.getCoordinates().getX(); x < ship.getCoordinates().getX() + ship.getShipType().getSize(); ++x) {
				Coordinates tmpC = new Coordinates(x, ship.getCoordinates().getY());
				tmp.add(tmpC);
				if(coordinates.contains(tmpC)) return false;
			}
		} else {
			for(int y = ship.getCoordinates().getY(); y < ship.getCoordinates().getY() + ship.getShipType().getSize(); ++y) {
				Coordinates tmpC = new Coordinates(ship.getCoordinates().getX(), y);
				tmp.add(tmpC);
				if(coordinates.contains(tmpC)) return false;
			}
		}
		
		ShipType type = ship.getShipType();
		if(remaining.get(type) <= 0) return false;
		remaining.put(type, remaining.get(type) - 1);
		
		coordinates.addAll(tmp);
		
		return true;
	}
	
	public boolean destroy(Coordinates c) {
		if(!coordinates.contains(c)) return false;
		coordinates.remove(c);
		return true;
	}
	
	public int gameProgress() {
		return coordinates.size();
	}
}
