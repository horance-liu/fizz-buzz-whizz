#include "game/RuleResult.h"

RuleResult::RuleResult(const std::string& result) : result(result)
{}

bool RuleResult::collect(bool matched, const std::string& str)
{
    if (matched) result += str;
    return matched;
}

bool RuleResult::collect(bool matched, const RuleResult& rr)
{
    return collect(matched, rr.result);
}

bool RuleResult::operator==(const RuleResult& rhs) const
{
    return result == rhs.result;
}

bool RuleResult::operator!=(const RuleResult& rhs) const
{
    return !(*this == rhs);
}
