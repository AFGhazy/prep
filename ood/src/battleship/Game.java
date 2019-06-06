package battleship;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Game {
	List<Board> boards;
	int turn = 0;
	
	Layout getLayout() {
		return ( new Random().nextBoolean() ? Layout.HORIZONTAL : Layout.VERTICAL);
	}
	
	void fillInBoard(Board board) {
		while(board.remaining.get(ShipType.DESTROYER) > 0) {
			board.layShip(new Destroyer(new Coordinates(new Random().nextInt(Board.SIZE), new Random().nextInt(Board.SIZE)),  getLayout()));
		}
		while(board.remaining.get(ShipType.CRUISER) > 0) {
			board.layShip(new Cruiser(new Coordinates(new Random().nextInt(Board.SIZE), new Random().nextInt(Board.SIZE)),  getLayout()));
		}
		while(board.remaining.get(ShipType.AIRCRAFTCARIER) > 0) {
			board.layShip(new AircraftCarrier(new Coordinates(new Random().nextInt(Board.SIZE), new Random().nextInt(Board.SIZE)),  getLayout()));
		}
		
	}
	
	public Game(String player1, String player2) {
		// TODO Auto-generated constructor stub
		boards = new ArrayList<Board>();
		boards.add(new Board(player1));
		boards.add(new Board(player2));
		fillInBoard(boards.get(0));
		fillInBoard(boards.get(1));
	}
	
	boolean play() {
		Coordinates c = new Coordinates(new Random().nextInt(Board.SIZE), new Random().nextInt(Board.SIZE));
		System.out.println(turn + " " + c.getX() + " " + c.getY());
		boards.get(turn % 2).destroy(c);
		boolean ret = boards.get(turn % 2).gameProgress() > 0;
		turn ++;
		return ret;
	}
}
