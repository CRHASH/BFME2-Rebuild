// The recharge modifiers indexed by the player upgrade count.
#pragma once
#ifndef BFME2_SPELL_RECHARGE_MODIFIER_UPGRADE_MODULE_DATA_H
#define BFME2_SPELL_RECHARGE_MODIFIER_UPGRADE_MODULE_DATA_H

#include <stddef.h>
#include "Common/GameType.h"
#include "GameLogic/Module/UpgradeModule.h"
#include "Common/AsciiString.h"
#include <vector>

class INI;
class MultiIniFieldParse;

class SpellRechargeModifierUpgradeModuleData : public UpgradeModuleData
{
public:
	SpellRechargeModifierUpgradeModuleData();
	virtual ~SpellRechargeModifierUpgradeModuleData();
	static void buildFieldParse(MultiIniFieldParse &parse);
	static ModuleData *friend_newModuleData(INI *ini);

	std::vector<Real> m_percentage;                       // +0x118 Percentage: the modifier table SpellRechargeModifierUpgrade indexes by the player's count (0x004B5F9F, clamped to its size)
	Bool m_startsActive;                                   // +0x124 StartsActive
	AsciiString m_labelForPalantirString;                  // +0x128 LabelForPalantirString
};
// SIZE 0x12C
typedef char SpellRechargeModifierUpgradeModuleData_size[(sizeof(SpellRechargeModifierUpgradeModuleData) == 0x12C) ? 1 : -1];
typedef char SpellRechargeModifierUpgradeModuleData_off_m_percentage[(offsetof(SpellRechargeModifierUpgradeModuleData, m_percentage) == 0x118) ? 1 : -1];
typedef char SpellRechargeModifierUpgradeModuleData_off_m_startsActive[(offsetof(SpellRechargeModifierUpgradeModuleData, m_startsActive) == 0x124) ? 1 : -1];
typedef char SpellRechargeModifierUpgradeModuleData_off_m_labelForPalantirString[(offsetof(SpellRechargeModifierUpgradeModuleData, m_labelForPalantirString) == 0x128) ? 1 : -1];

#endif
