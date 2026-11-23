// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G0002F5F4 name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
#include "Common/INI.h"
// FUNCTION: BFME2 0x0002F5F4 size=78 name=?parsePitchShift@@YAXPAVINI@@PAX1PBX@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
void parsePitchShift(INI *ini, void *instance, void *store, const void *userData)
{
	Real *range = static_cast<Real *>(store);
	range[0] = ini->scanReal(ini->getNextToken());
	range[1] = ini->scanReal(ini->getNextToken());
	if (range[0] > range[1]) {
		Real swap = range[0];
		range[0] = range[1];
		range[1] = swap;
	}
}

// FUNCTION: BFME2 0x0002F642 size=63 name=?parseDelay@@YAXPAVINI@@PAX1PBX@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
void parseDelay(INI *ini, void *instance, void *store, const void *userData)
{
	Int *range = static_cast<Int *>(store);
	range[0] = ini->scanInt(ini->getNextToken());
	range[1] = ini->scanInt(ini->getNextToken());
	if (range[0] > range[1]) {
		Int swap = range[0];
		range[0] = range[1];
		range[1] = swap;
	}
}
