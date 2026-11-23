// cl: /O1
// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G00566D83 name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
#include "GameLogic/Scripts.h"
#include "GameLogic/ScriptEngine.h"
#include "GameLogic/ObjectTypes.h"
#include "Common/AsciiString.h"
// FUNCTION: BFME2 0x00566D83 size=232 name=?ParseLivingWorldCampaignAct@@YAXPAVINI@@PAX1PBX@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
// FUNCTION: BFME2 0x00566E6C size=113 name=?Script_objectTypesFromParam@@YAXPAVParameter@@PAVObjectTypes@@@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
void Script_objectTypesFromParam(Parameter *pTypeParm, ObjectTypes *outObjectTypes)
{
	if (!outObjectTypes)
		return;

	AsciiString str = pTypeParm->getString();
	if (str.isEmpty())
		return;

	ObjectTypes *types = TheScriptEngine->getObjectTypes(str);
	if (!types)
		outObjectTypes->addObjectType(str);
	else
		*outObjectTypes = *types;
}
