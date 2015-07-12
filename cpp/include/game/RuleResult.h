#ifndef H8A31701E_B0E4_4B58_A897_976C680C21A3
#define H8A31701E_B0E4_4B58_A897_976C680C21A3

#include <string>

struct RuleResult
{
    RuleResult(const std::string& = "");

    bool collect(bool matched, const RuleResult&);
    bool collect(bool matched, const std::string&);

    bool operator==(const RuleResult& rhs) const;
    bool operator!=(const RuleResult& rhs) const;

private:
    std::string result;
};

#endif
