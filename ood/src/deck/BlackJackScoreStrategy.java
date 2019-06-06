package deck;

public class BlackJackScoreStrategy extends ScoreStrategy<BlackJackCard> {

	@Override
	int score(BlackJackCard card) {
		return card.getVal().getVal();
	}
	
}
