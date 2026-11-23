// Portions derived from Command & Conquer Generals Zero Hour, (c) Electronic Arts Inc., GPL-3.0-or-later; see LICENSE and NOTICE.
#include "WWMath/Vector3.h"
// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G000930D9 name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
// FUNCTION: BFME2 0x000930D9 size=7 name=?get@Rva000930D9ByteField@@QBEEXZ evidence=?:placeholder tier=B hypothesis:mm1-gap-unit
// FUNCTION: BFME2 0x000930E0 size=106 name=?Float_To_Int_Floor@WWMath@@SAHABM@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
int WWMath::Float_To_Int_Floor(const float &f)
{
	int a = (const int &)f;
	int sign = (a >> 31);
	a &= 0x7fffffff;

	int exponent = (a >> 23) - 127;
	int expsign = ~(exponent >> 31);
	int imask = ((1 << (31 - exponent))) - 1;
	int mantissa = (a & ((1 << 23) - 1));
	int r = ((unsigned int)(mantissa | (1 << 23)) << 8) >> (31 - exponent);

	r = ((r & expsign) ^ (sign)) + ((!((mantissa << 8) & imask) & (expsign ^ ((a - 1) >> 31))) & sign);
	return r;
}
// FUNCTION: BFME2 0x0009314A size=24 name=?GetTranslationVector@Matrix4D@@QBEAAVCoord3D@@AAU2@@Z evidence=X:retail PE exports class Coord3D: ??0Matrix4D@@QAE@ABVCoord3D@@@Z tier=B hypothesis:mm1-gap-unit
