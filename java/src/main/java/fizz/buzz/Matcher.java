package fizz.buzz;

public interface Matcher {
    boolean matches(int n);   
    
    static Matcher times(int times) {
        return new Matcher() {
            @Override
            public boolean matches(int n) {
                return n % times == 0;
            }
        };
    }
    
    static Matcher contains(int num) {
        return new Matcher() {
            @Override
            public boolean matches(int n) {
                int m = 0;
                while (n>0) {
                    m = n%10; 
                    n = n/10;
                    if (m == num) return true;
                }
                return false;
            }
        };
    }
    
    static Matcher always(boolean logic) {
        return new Matcher() {
            @Override
            public boolean matches(int n) {
                return logic;
            }
        };
    }
}
