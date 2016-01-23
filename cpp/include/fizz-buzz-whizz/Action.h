#ifndef H4FCC10FD_D41B_40E8_AC5A_3542C4FB23D7
#define H4FCC10FD_D41B_40E8_AC5A_3542C4FB23D7

#include "l0-infra/dci/Role.h"
#include <string>
#include <memory>

DEFINE_ROLE(Action)
{
    ABSTRACT(std::string to(int) const);
};

using SharedAction = std::shared_ptr<Action>;

SharedAction to(const std::string&);
SharedAction nop();

#endif
