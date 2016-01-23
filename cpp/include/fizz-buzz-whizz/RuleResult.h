#ifndef H8A31701E_B0E4_4B58_A897_976C680C21A3
#define H8A31701E_B0E4_4B58_A897_976C680C21A3

#include <string>

struct RuleResult
{
    explicit RuleResult(const std::string& = "");

    bool collect(bool matched, const RuleResult&);
    bool collect(bool matched, const std::string&);

    const std::string& toString() const;

private:
    std::string result;
};

#endif
