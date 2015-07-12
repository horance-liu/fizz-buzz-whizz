package fizz.buzz;

public interface Action {
    String to(int n);
    
    static Action to(String str) {
        return new Action() {
            @Override
            public String to(int n) {
                return str;
            }            
        };
    }
        
    static Action nop() {
        return new Action() {
            @Override
            public String to(int n) {
                return Integer.toString(n);
            }
        };
    }
}
