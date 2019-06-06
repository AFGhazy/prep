package deck;

import java.util.ArrayList;
import java.util.List;

public class Hand<T extends Card> {
	protected List<T> cards;
	private ScoreStrategy<T> scoreStrategy;
	
	Hand(ScoreStrategy<T> scoreStrategy) {
		cards = new ArrayList<T>();
		this.scoreStrategy = scoreStrategy;
	}
	
	void addCards(List<T> l) {
		cards.addAll(l);
	}
	
	int score() {
		return cards.stream().reduce(0, 
				(accum, card) -> accum += scoreStrategy.score(card),
				(val1, val2) -> val1 + val2);
	}
}
