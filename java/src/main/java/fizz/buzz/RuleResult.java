package fizz.buzz;

public class RuleResult {
    public RuleResult() {
        this("");
    }
    
    public RuleResult(String str) {
        buff = new StringBuilder(str);
    }
    
    public boolean collect(boolean matched, String str) {
        if (matched) buff.append(str);
        return matched;
    }
    
    public boolean collect(boolean matched, RuleResult rr) {
        return collect(matched, rr.buff.toString());
    }
    
    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof RuleResult))
            return false;
        
        RuleResult other = (RuleResult)obj;        
        return buff.toString().equals(other.buff.toString());
    }
    
    private StringBuilder buff;
}
