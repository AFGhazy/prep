package deck;

import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String[] args) {
		List<BlackJackCard> l = new ArrayList<BlackJackCard>();
		for(Value val: Value.values()) {
			for(Suit suit: Suit.values()) {
				l.add(new BlackJackCard(val, suit));
			}
		}
		
		Deck d = new Deck(l);
		d.shuffle();
		
		List<BlackJackCard> hl = d.dealHand(3);
		System.out.println(hl);
		
		
		hl.forEach(c -> {
			System.out.println(c);
		});
		
		Hand h = new Hand<BlackJackCard>(new BlackJackScoreStrategy());
		h.addCards(hl);
		System.out.println(h.score());
		
		System.out.println(d.dealHand(10));
	}

}
