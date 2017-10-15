#include "fizz-buzz-whizz/Rule.h"

Rule atom(Matcher&& matcher, Action&& action) {
  return [matcher = std::move(matcher), action = std::move(action)](int m) {
    return matcher(m) ? action(m) : "";
  };
}

Rule allof(std::vector<Rule>&& rules) {
  return [rules = std::move(rules)](int m) {
    std::string result;
    for (auto& rule : rules)
      result += rule(m);
    return result;
  };
}

Rule anyof(std::vector<Rule>&& rules) {
  return [rules = std::move(rules)](int m) {
    for (auto& rule : rules) {
      auto result = rule(m);
      if (!result.empty())
        return result;
    }
    return std::string("");
  };
}
