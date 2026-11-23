// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G0001B010 name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
#include <float.h>
// FUNCTION: BFME2 0x0001B010 size=25 name=?_Stl_is_nan_or_inf@_STL@@YA_NN@Z evidence=L:vendored=stlport-4.6.2 tier=B hypothesis:mm1-gap-unit
namespace _STL {
bool _Stl_is_nan_or_inf(double x) { return !_finite(x); }
}
// FUNCTION: BFME2 0x0001B030 size=40 name=?_Stl_is_inf@_STL@@YA_NN@Z evidence=L:vendored=stlport-4.6.2 tier=B hypothesis:mm1-gap-unit
namespace _STL {
bool _Stl_is_inf(double x)
{
	int fclass = _fpclass(x);
	return fclass == _FPCLASS_NINF || fclass == _FPCLASS_PINF;
}
}
// FUNCTION: BFME2 0x0001B060 size=28 name=?_Stl_is_neg_inf@_STL@@YA_NN@Z evidence=L:vendored=stlport-4.6.2 tier=B hypothesis:mm1-gap-unit
namespace _STL {
bool _Stl_is_neg_inf(double x) { return _fpclass(x) == _FPCLASS_NINF; }
}
