#include "game/Rule.h"
#include "game/RuleResult.h"

namespace
{
    struct Atom : Rule
    {
        Atom(const SharedMatcher& matcher, const SharedAction& action)
          : matcher(matcher), action(action)
        {}

    private:
        OVERRIDE(bool apply(int n, RuleResult& rr) const)
        {
            return rr.collect(matcher->matches(n), action->to(n));
        }

    private:
        SharedMatcher matcher;
        SharedAction  action;
    };

    struct CombinableRule : Rule
    {
        CombinableRule(bool shortcut, const std::vector<SharedRule>& rules)
          : shortcut(shortcut), rules(rules)
        {}

    protected:
        OVERRIDE(bool apply(int n, RuleResult& rr) const)
        {
            for(auto rule : rules)
            {
                if(rule->apply(n, rr) == shortcut)
                    return shortcut;
            }
            return !shortcut;
        }

    private:
        bool shortcut;
        std::vector<SharedRule> rules;
    };

    struct Anyof : CombinableRule
    {
        Anyof(const std::vector<SharedRule>& rules)
          : CombinableRule(true, rules)
        {}
    };

    struct Allof : CombinableRule
    {
        Allof(const std::vector<SharedRule>& rules)
          : CombinableRule(false, rules)
        {}

    private:
        OVERRIDE(bool apply(int n, RuleResult& rr) const)
        {
            RuleResult result;
            return rr.collect(CombinableRule::apply(n, result), result);
        }
    };
}

SharedRule atom(const SharedMatcher& matcher, const SharedAction& action)
{ return std::make_shared<Atom>(matcher, action); }

SharedRule anyof(const std::vector<SharedRule>& rules)
{ return std::make_shared<Anyof>(rules); }

SharedRule allof(const std::vector<SharedRule>& rules)
{ return std::make_shared<Allof>(rules); }
