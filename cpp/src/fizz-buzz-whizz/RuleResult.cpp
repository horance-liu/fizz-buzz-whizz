#include "fizz-buzz-whizz/RuleResult.h"

RuleResult::RuleResult(const std::string& result) : result(result) {
}

bool RuleResult::collect(bool matched, const std::string& str) {
  if (matched) result += str;
  return matched;
}

bool RuleResult::collect(bool matched, const RuleResult& rr) {
  return collect(matched, rr.result);
}

const std::string& RuleResult::toString() const {
  return result;
}
