// BaseHeightMapRenderObjClass.h: the terrain render object that W3DTerrainLogic forwards its height, cliff and
// line-of-sight queries to (TheTerrainRenderObject, VA 0x00DE1EAC). Only the members W3DTerrainLogic calls are
// declared; the layout is not recovered (a generated vtable draft lives in Draft/BaseHeightMapRenderObjClass.h and
// is not included anywhere). Target facts: each W3DTerrainLogic wrapper loads the pointer and calls or tail-jumps to
// the member named in its comment.
#pragma once
#ifndef BFME2_BASEHEIGHTMAPRENDEROBJCLASS_H
#define BFME2_BASEHEIGHTMAPRENDEROBJCLASS_H

#include "Common/GameType.h"

class Coord3D;
class AsciiString;
class W3DTerrainLogic;

class BaseHeightMapRenderObjClass
{
public:
	Bool isClearLineOfSight(const Coord3D &start, const Coord3D &end) const;	// 0x00066AD1
	Bool isCliffCell(Real x, Real y);											// 0x000671B2
	UnsignedByte rva0006B187(Real x, Real y);									// 0x0006B187
	UnsignedByte rva00067225(Real x, Real y);									// 0x00067225
	Bool rva00067298(Real x, Real y);											// 0x00067298
	UnsignedByte rva0006730B(Real x, Real y);									// 0x0006730B
	void addProp(Int id, Coord3D location, Real angle, Real scale, const AsciiString &modelName, Bool flag);	// 0x0006831C
	void loadRoadsAndBridges(W3DTerrainLogic *terrain, Bool saveGame);			// 0x00067800
};

extern BaseHeightMapRenderObjClass *TheTerrainRenderObject;	// 0x00DE1EAC

#endif
