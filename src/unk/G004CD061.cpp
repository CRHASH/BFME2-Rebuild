// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G004CD061 name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
#include "Common/INI.h"
#include "Common/INI/FieldParse.h"
#include "GameLogic/Module/GiveOrRestoreUpgradeSpecialPowerModuleData.h"
static const FieldParse s_giveOrRestoreUpgradeSpecialPowerModuleDataFieldParse[] =
{
	{ "CommandButton", INI::parseAsciiString, 0, 0xC8 },
	{ "UpgradeToGive", INI::parseAsciiString, 0, 0xCC },
	{ "FlagsUsedForToggle", BitFlags<104>::parseFromINI, 0, 0xD0 },
	{ 0, 0, 0, 0 }
};

// FUNCTION: BFME2 0x004CD061 size=27 name=?buildFieldParse@GiveOrRestoreUpgradeSpecialPowerModuleData@@SAXAAVMultiIniFieldParse@@@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
void GiveOrRestoreUpgradeSpecialPowerModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	SpecialAbilityUpdateModuleData::buildFieldParse(parse);
	parse.add(s_giveOrRestoreUpgradeSpecialPowerModuleDataFieldParse, 0);
}

// FUNCTION: BFME2 0x004CD07C size=53 name=?Rva004CD07C@@YAPAXPAURva004CD07CObject@@@Z evidence=?:placeholder tier=B hypothesis:mm1-gap-unit
// FUNCTION: BFME2 0x004CD0B1 size=43 name=??0GiveOrRestoreUpgradeSpecialPowerModuleData@@QAE@XZ evidence=N:ledger tier=B hypothesis:mm1-gap-unit
GiveOrRestoreUpgradeSpecialPowerModuleData::GiveOrRestoreUpgradeSpecialPowerModuleData()
{
}
