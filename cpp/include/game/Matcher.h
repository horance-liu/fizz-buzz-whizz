#ifndef HF240298E_E31E_45DE_8221_A218DEA3D685
#define HF240298E_E31E_45DE_8221_A218DEA3D685

#include "l0-infra/dci/Role.h"
#include <memory>

DEFINE_ROLE(Matcher)
{
    ABSTRACT(bool matches(int n) const);
};

typedef std::shared_ptr<Matcher> SharedMatcher;

SharedMatcher times(int times);
SharedMatcher contains(int num);
SharedMatcher always(bool);

#endif
