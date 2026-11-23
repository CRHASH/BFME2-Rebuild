// cl: /O1
#include "Common/Xfer.h"
#include "GameLogic/Module/StancesBehavior.h"
#include "Common/INI.h"
#include "Common/INI/FieldParse.h"
#include "GameLogic/Module/StancesBehaviorModuleData.h"
#include "Common/NameKeyGenerator.h"
// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G0045ED4B name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
// FUNCTION: BFME2 0x0045ED4B size=27 name=?rva0045ED4B@StancesBehavior@@QBEHXZ evidence=?:placeholder tier=B hypothesis:mm1-gap-unit
Int StancesBehavior::rva0045ED4B() const
{
	switch (m_unk0x30)
	{
		case 2:
			return 2;
		case 3:
		case 4:
		case 5:
			return 3;
		default:
			return 1;
	}
}
// FUNCTION: BFME2 0x0045ED66 size=24 name=?XferStancesEnum@@YAXPAVXfer@@PAH@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
void XferStancesEnum(Xfer *xfer, int *value)
{
	xfer->XferEnum("StancesEnum", value, 4);
}
// FUNCTION: BFME2 0x0045ED7E size=14 name=?invokeCallback@Rva0045ED7E@@QAEXPAVRva0045ED7ETarget@@@Z evidence=?:placeholder tier=B hypothesis:mm1-gap-unit
static const FieldParse s_stancesBehaviorModuleDataFieldParse[] =
{
	{ "StanceTemplate", NameKeyGenerator::parseStringAsNameKeyType, 0, 0x8 },
	{ 0, 0, 0, 0 }
};

// FUNCTION: BFME2 0x0045ED8C size=17 name=?buildFieldParse@StancesBehaviorModuleData@@SAXAAVMultiIniFieldParse@@@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
void StancesBehaviorModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	parse.add(s_stancesBehaviorModuleDataFieldParse, 0);
}

