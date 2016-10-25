#ifndef H4FCC10FD_D41B_40E8_AC5A_3542C4FB23D7
#define H4FCC10FD_D41B_40E8_AC5A_3542C4FB23D7

#include <string>
#include <functional>

using Action = std::function<std::string(int)>;

Action to(std::string&&);
Action nop();

#endif
