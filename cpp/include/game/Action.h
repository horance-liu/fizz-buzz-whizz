#ifndef H4FCC10FD_D41B_40E8_AC5A_3542C4FB23D7
#define H4FCC10FD_D41B_40E8_AC5A_3542C4FB23D7

#include <l0-infra/std/String.h>

typedef std::string(*Action)(int);

inline std::string to_fizz(int)  { return "Fizz";  }
inline std::string to_buzz(int)  { return "Buzz";  }
inline std::string to_whizz(int) { return "Whizz"; }
inline std::string nop(int n)    { return stdext::toString(n); }

#endif
