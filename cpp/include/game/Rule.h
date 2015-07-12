#ifndef HAFB02649_F7FE_4C8D_BF52_F3B241A9B753
#define HAFB02649_F7FE_4C8D_BF52_F3B241A9B753

#include "game/Action.h"
#include "game/Matcher.h"
#include <vector>

struct RuleResult;

DEFINE_ROLE(Rule)
{
    ABSTRACT(bool apply(int n, RuleResult& rr) const);
};

typedef std::shared_ptr<Rule> SharedRule;

SharedRule atom(const SharedMatcher&, const SharedAction&);
SharedRule anyof(const std::vector<SharedRule>&);
SharedRule allof(const std::vector<SharedRule>&);

#endif
