package deck;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public enum Suit {
	CLUB(0), DIAMOND(1), HEART(2), SPADE(3);
	
	private int val;
	private Suit(int val) {
		this.val = val;
	}
	
	public int getVal() {
		return val;
	}
	
	public static Suit getSuitFromVal(int val) {
		Suit s = null;
		List<Suit> l = Arrays.asList(values()).stream().filter(p -> p.val == val).collect(Collectors.toList());
		
		if(!l.isEmpty()) {
			s = l.get(0);
		}
		return s;
	}
}
