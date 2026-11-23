// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G0073B4B0 name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
#include "Common/GameType.h"
// FUNCTION: BFME2 0x0073B4B0 size=42 name=?BFMEComputeCRC@@YAIPBEII@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit

UnsignedInt BFMEComputeCRC(const UnsignedByte *buf, UnsignedInt len, UnsignedInt crc)
{
	if (buf)
	{
		while (len--)
		{
			Int hibit = (crc & 0x80000000) ? 1 : 0;
			crc <<= 1;
			crc += *buf++;
			crc += hibit;
		}
	}
	return crc;
}
