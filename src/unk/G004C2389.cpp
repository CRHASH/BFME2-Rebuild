// cl: /O1
// stlport46
#include "Common/INI.h"
#include "GameLogic/Module/InvisibilitySpecialPower.h"
#include "GameLogic/Module/InvisibilitySpecialPowerModuleData.h"
#include "GameLogic/Module/SpecialPowerModule.h"
void Rva00438176Parse(INI *ini, void *instance, void *store, const void *userData);
void iniParseObjectFilter(INI *ini, void *instance, void *store, const void *userData);
// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G004C2389 name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
// Field parse table for InvisibilitySpecialPowerModuleData (decoded from retail image).
static const FieldParse s_invisibilitySpecialPowerModuleDataFieldParse[] =
{
	{ "InvisibilityNugget", Rva00438176Parse, 0, 0x7C },
	{ "BroadcastRadius", INI::parseReal, 0, 0x134 },
	{ "ObjectFilter", iniParseObjectFilter, 0, 0x138 },
	{ "Duration", INI::parseDurationUnsignedInt, 0, 0x13C },
	{ 0, 0, 0, 0 }
};

// FUNCTION: BFME2 0x004C2389 size=27 name=?buildFieldParse@InvisibilitySpecialPowerModuleData@@SAXAAVMultiIniFieldParse@@@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
void InvisibilitySpecialPowerModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	SpecialPowerModuleData::buildFieldParse(parse);
	parse.add(s_invisibilitySpecialPowerModuleDataFieldParse, 0);
}

// FUNCTION: BFME2 0x004C23A4 size=42 name=??0InvisibilitySpecialPower@@QAE@PAVThing@@PBVModuleData@@@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
InvisibilitySpecialPower::InvisibilitySpecialPower(Thing *thing, const ModuleData *moduleData)
	: SpecialPowerModule(thing, moduleData)
{
}
