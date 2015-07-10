#ifndef HAFB02649_F7FE_4C8D_BF52_F3B241A9B753
#define HAFB02649_F7FE_4C8D_BF52_F3B241A9B753

#include "l0-infra/dci/Role.h"
#include "game/Predicate.h"
#include "game/Action.h"
#include "game/RuleResult.h"
#include <vector>
#include <memory>

DEFINE_ROLE(Rule)
{
    ABSTRACT(bool apply(int n, RuleResult& rr) const);
};

typedef std::shared_ptr<Rule> SharedRule;

SharedRule atom(Predicate pred, Action action);
SharedRule orelse(std::vector<SharedRule> rules);
SharedRule andalso(std::vector<SharedRule> rules);

#endif
