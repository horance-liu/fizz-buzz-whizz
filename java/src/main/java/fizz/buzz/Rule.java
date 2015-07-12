package fizz.buzz;

import java.util.List;
import java.util.Arrays;

public interface Rule {
    boolean apply(int n, RuleResult rr);
        
    static Rule atom(Matcher matcher, Action action) {
        return new Rule() {
            @Override
            public boolean apply(int n, RuleResult rr) {
                return rr.collect(matcher.matches(n), action.to(n));
            }
        };
    }
    
    static class CombinableRule implements Rule {
        CombinableRule(boolean shortcut, Rule...rules) {
            this.shortcut = shortcut;
            this.rules = Arrays.asList(rules);
        }
        
        @Override
        public boolean apply(int n, RuleResult rr) {
            for (Rule r : rules) {
                if (r.apply(n, rr) == shortcut) {
                    return shortcut;
                }
            }
            return !shortcut;
        }
        
        private boolean shortcut;
        private List<Rule> rules;
    }
        
    static Rule anyof(Rule...rules) {
        return new CombinableRule(true, rules);
    }
    
    static Rule allof(Rule...rules) {
        return new CombinableRule(false, rules) {
            @Override
            public boolean apply(int n, RuleResult rr) {
                RuleResult result = new RuleResult();
                return rr.collect(super.apply(n, result), result);
            }
        };
    }
}
