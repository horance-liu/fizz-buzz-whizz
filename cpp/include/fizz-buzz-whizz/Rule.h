#ifndef HAFB02649_F7FE_4C8D_BF52_F3B241A9B753
#define HAFB02649_F7FE_4C8D_BF52_F3B241A9B753

#include "fizz-buzz-whizz/Action.h"
#include "fizz-buzz-whizz/Matcher.h"
#include <vector>

using Rule = std::function<std::string(int)>;

Rule atom(const Matcher&, const Action&);
Rule anyof(const std::vector<Rule>&);
Rule allof(const std::vector<Rule>&);

#endif
