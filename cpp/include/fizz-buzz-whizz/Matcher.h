#ifndef HF240298E_E31E_45DE_8221_A218DEA3D685
#define HF240298E_E31E_45DE_8221_A218DEA3D685

#include <functional>

using Matcher = std::function<bool(int)>;

Matcher times(int);
Matcher contains(int);
Matcher always();

#endif
