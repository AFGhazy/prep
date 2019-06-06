package deck;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Deck <T extends Card> {
	private List<T> dealtCards;
	private List<T> remainingCards;
	
	T dealCard() {
		T c = remainingCards.get(remainingCards.size() - 1);
		remainingCards.remove(remainingCards.size() - 1);
		dealtCards.add(c);
		return c;
	}
	
	List<T> dealHand(int size) {
		int maxSize = Math.min(size, remainingCards.size());
		
		List<T> l = new ArrayList<T>();
		for(int i = 0; i < maxSize; ++i) {
			l.add(dealCard());
		}
		return l;
	}
	
	void shuffle() {
		Collections.shuffle(remainingCards);
	}
	
	public Deck(List<T> initialCards) {
		dealtCards = new ArrayList<T>();
		remainingCards = initialCards;
	}
}
