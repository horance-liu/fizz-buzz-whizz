#include "game/Rule.h"
#include <memory>

namespace
{
    struct Atom : Rule
    {
        Atom(Predicate pred, Action action) : pred(pred), action(action)
        {}

    private:
        OVERRIDE(bool apply(int n, RuleResult& rr) const)
        {
            return rr.collect(pred(n), action(n));
        }

    private:
        Predicate pred;
        Action action;
    };
}

SharedRule atom(Predicate pred, Action action)
{
    return SharedRule(new Atom(pred, action));
}

namespace
{
    struct LogicRule : Rule
    {
        LogicRule(std::vector<SharedRule> rules) : rules(rules)
        {}

    protected:
        bool doApply(int n, RuleResult& rr, bool shortcut) const
        {
            for(auto rule : rules)
            {
                if(rule->apply(n, rr) == shortcut)
                {
                    return shortcut;
                }
            }

            return !shortcut;
        }

    private:
        std::vector<SharedRule> rules;
    };

    struct LogicOr : LogicRule
    {
        using LogicRule::LogicRule;

    private:
        OVERRIDE(bool apply(int n, RuleResult& rr) const)
        {
            return doApply(n, rr, true);
        }
    };

    struct LogicAnd : LogicRule
    {
        using LogicRule::LogicRule;

    private:
        OVERRIDE(bool apply(int n, RuleResult& rr) const)
        {
            RuleResult result;
            return rr.collect(doApply(n, result, false), result);
        }
    };
}

SharedRule orelse(std::vector<SharedRule> rules)
{
    return SharedRule(new LogicOr(rules));
}

SharedRule andalso(std::vector<SharedRule> rules)
{
    return SharedRule(new LogicAnd(rules));
}
