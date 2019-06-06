package deck;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class SuitTest {

	@Test
	void checkCorrectValue() {
		Suit s = Suit.getSuitFromVal(0);
		assertEquals(Suit.CLUB, s);
	}
	
	@Test
	void checkInCorrectValue() {
		Suit s = Suit.getSuitFromVal(5);
		assertEquals(null, s);
	}

}
