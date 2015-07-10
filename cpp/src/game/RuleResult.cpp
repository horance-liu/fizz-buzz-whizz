#include "game/RuleResult.h"

RuleResult::RuleResult(const std::string& result) : result(result)
{}

bool RuleResult::collect(bool succ, const std::string& str)
{
    if (succ) result += str;
    return succ;
}

bool RuleResult::collect(bool succ, const RuleResult& rr)
{
    return collect(succ, rr.result);
}

bool RuleResult::operator==(const RuleResult& rhs) const
{
    return result == rhs.result;
}

bool RuleResult::operator!=(const RuleResult& rhs) const
{
    return !(*this == rhs);
}
