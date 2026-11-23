// Portions derived from Command & Conquer Generals and Command & Conquer Generals Zero Hour, (c) Electronic Arts Inc., GPL-3.0-or-later; see LICENSE and NOTICE.
#include "WWMath/AABoxClass.h"
#include "WWMath/CollisionMath.h"
#include "WWMath/ObbCollisionStruct.h"
// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G0072B5E0 name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
// FUNCTION: BFME2 0x0072B5E0 size=206 name=?Collide@CollisionMath@@SA_NABVOBBoxClass@@ABVVector3@@ABVAABoxClass@@1PAUCastResultStruct@@@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
bool CollisionMath::Collide(const OBBoxClass &box0, const Vector3 &move0, const AABoxClass &box1, const Vector3 &move1, CastResultStruct *result)
{
	OBBoxClass obbox1;
	obbox1.Basis = Matrix3(true);
	obbox1.Center = box1.Center;
	obbox1.Extent = box1.Extent;
	ObbCollisionStruct context(box0, move0, obbox1, move1);
	return collide_obb_obb(context, result);
}

// FUNCTION: BFME2 0x0072B6B0 size=206 name=?Collide@CollisionMath@@SA_NABVAABoxClass@@ABVVector3@@ABVOBBoxClass@@1PAUCastResultStruct@@@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
bool CollisionMath::Collide(const AABoxClass &box0, const Vector3 &move0, const OBBoxClass &box1, const Vector3 &move1, CastResultStruct *result)
{
	OBBoxClass obbox0;
	obbox0.Basis = Matrix3(true);
	obbox0.Center = box0.Center;
	obbox0.Extent = box0.Extent;
	ObbCollisionStruct context(obbox0, move0, box1, move1);
	return collide_obb_obb(context, result);
}

