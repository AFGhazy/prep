package battleship;

import java.util.Random;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Game game = new Game("P1", "P2");
		while(game.play());
	}

}
