#ifndef HF240298E_E31E_45DE_8221_A218DEA3D685
#define HF240298E_E31E_45DE_8221_A218DEA3D685

typedef bool(*Predicate)(int);

bool times(int n, int radix);
bool contains(int n, int radix);
bool always_true(int n);

inline bool times_3(int n)    { return times(n, 3);    }
inline bool times_5(int n)    { return times(n, 5);    }
inline bool times_7(int n)    { return times(n, 7);    }
inline bool contains_3(int n) { return contains(n, 3); }

#endif
