package deck;

public abstract class ScoreStrategy <T extends Card> {
	abstract int score(T card);
}
