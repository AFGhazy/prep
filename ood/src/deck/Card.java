package deck;

import java.util.List;

public abstract class Card {
	private Value val;
	private Suit suit;
	
	public Value getVal() {
		return val;
	}
	
	public Suit getSuit() {
		return suit;
	}
	
	Card(Value val, Suit suit) {
		this.val = val;
		this.suit = suit;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "[" + val + " of " + suit + "]";
	}
}
