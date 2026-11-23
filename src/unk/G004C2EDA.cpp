// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G004C2EDA name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
#include "Common/INI.h"
#include "GameLogic/Module/ProductionSpeedBonusModuleData.h"

static const FieldParse s_productionSpeedFields[] =
{
	{ "NumberOfFrames", INI::parseInt, 0, offsetof(ProductionSpeedBonusModuleData, m_numberOfFrames) },
	{ "SpeedMulitplier", INI::parseReal, 0, offsetof(ProductionSpeedBonusModuleData, m_speedMultiplier) },
	{ "Type", INI::parseAsciiStringVector, 0, offsetof(ProductionSpeedBonusModuleData, m_types) },
	{ 0, 0, 0, 0 }
};

// FUNCTION: BFME2 0x004C2EDA size=27 name=?buildFieldParse@ProductionSpeedBonusModuleData@@SAXAAVMultiIniFieldParse@@@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
// FUNCTION: BFME2 0x004C2EF5 size=42 name=??0ProductionSpeedBonus@@QAE@PAVThing@@PBVModuleData@@@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
void ProductionSpeedBonusModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	SpecialPowerModuleData::buildFieldParse(parse);
	parse.add(s_productionSpeedFields, 0);
}
