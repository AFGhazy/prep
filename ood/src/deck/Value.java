package deck;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public enum Value {
	ACE(1), TWO(2), THREE(3), FOUR(4), FIVE(5), SIX(6), SEVEN(7), EIGHT(8), NINE(9), TEN(10),
	JACK(11), QUEEN(12), KING(13);
	
	private int val;
	
	private Value(int val) {
		this.val = val;
	}
	
	public int getVal() {
		return val;
	}
	
	public Value getValueFromVal(int val) {
		Value v = null;
		List<Value> l = Arrays.asList(values()).stream().filter(p -> p.val == val).collect(Collectors.toList());
		
		if(!l.isEmpty()) {
			v = l.get(0);
		}
		return v;
	}
}
