#include "game/Matcher.h"

namespace
{
    struct Times : public Matcher
    {
        Times(int times) : times(times)
        {}

    private:
        OVERRIDE(bool matches(int n) const)
        { return n % times == 0; }

    private:
        int times;
    };
}

SharedMatcher times(int times)
{
    return std::make_shared<Times>(times);
}

namespace
{
    struct Contains : public Matcher
    {
        Contains(int num) : num(num)
        {}

    private:
        OVERRIDE(bool matches(int n) const)
        {
            auto m = 0;
            while (n>0)
            {
                m = n%10;
                n = n/10;
                if (m == num) return true;
            }
            return false;
        }

    private:
        int num;
    };
}

SharedMatcher contains(int num)
{
    return std::make_shared<Contains>(num);
}

namespace
{
    struct Always : Matcher
    {
        Always(bool logic) : logic(logic)
        {}

    private:
        OVERRIDE(bool matches(int n) const)
        { return logic; }

    private:
        bool logic;
    };
}

SharedMatcher always(bool logic)
{
    return std::make_shared<Always>(logic);
}
