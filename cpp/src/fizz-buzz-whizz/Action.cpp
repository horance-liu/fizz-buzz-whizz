#include "fizz-buzz-whizz/Action.h"
#include <l0-infra/std/String.h>

namespace
{
    struct ToString : Action
    {
        ToString(const std::string& str) : str(str)
        {}

    private:
        OVERRIDE(std::string to(int) const)
        { return str; }

    private:
        std::string str;
    };
}

SharedAction to(const std::string& str)
{
    return std::make_shared<ToString>(str);
}

namespace
{
    class Nop : public Action
    {
        OVERRIDE(std::string to(int n) const)
        { return stdext::toString(n); }
    };
}

SharedAction nop()
{
    return std::make_shared<Nop>();
}
