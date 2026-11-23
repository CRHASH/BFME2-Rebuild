// The respawn animations and effects, with cost and timing rules ordered by level.
#pragma once
#ifndef BFME2_RESPAWN_UPDATE_MODULE_DATA_H
#define BFME2_RESPAWN_UPDATE_MODULE_DATA_H

#include <stddef.h>
#include "Common/GameType.h"
#include "GameLogic/Module/ModuleData.h"
#include "GameLogic/ObjectFilter.h"
#include "Common/ModelConditionFlags.h"
#include "Common/AsciiString.h"

class INI;
class MultiIniFieldParse;
class FXList;

#include <set>

// One respawn rule, the 20-byte record of the rule tree (stored in the set): the rules are ordered by
// level (the tree's less<> compares the first dword) and the tree is looked up with a key whose other
// fields are 0, 0, 1.0f and false (calcCostToBuild 0x004AF531, calcTimeToBuild 0x004AF5AC).
struct RespawnRule
{
	Int m_level;				// +0x00 the rule's level (the ordering key)
	Int m_cost;					// +0x04 read by calcCostToBuild
	Int m_time;					// +0x08 read by calcTimeToBuild (milliseconds, divided by 1000)
	Real m_healthFraction;		// Applied to the body when the object respawns.
	Bool m_autoSpawn;			// The AutoSpawn entry in both the default and level-specific rules.
	bool operator<(const RespawnRule &other) const { return m_level < other.m_level; }
};

class RespawnUpdateModuleData : public ModuleData
{
public:
	RespawnUpdateModuleData();
	virtual ~RespawnUpdateModuleData();
	static void buildFieldParse(MultiIniFieldParse &parse);
	static ModuleData *friend_newModuleData(INI *ini);
	virtual const RespawnUpdateModuleData *slot28() const { return this; }
	virtual Bool slot13() const { return true; }
	Int calcCostToBuild(Int level);
	Int calcTimeToBuild(UnsignedInt level);

	ObjectFilter m_autoRespawnAtObjectFilter;              // +0x8 AutoRespawnAtObjectFilter
	ModelConditionFlags m_deathAnim;                             // +0xC DeathAnim
	ModelConditionFlags m_respawnAnim;                           // +0x58 RespawnAnim
	ModelConditionFlags m_initialSpawnAnim;                      // +0xA4 InitialSpawnAnim
	const FXList * m_deathFX;                              // +0xF0 DeathFX
	const FXList * m_respawnFX;                            // +0xF4 RespawnFX
	const FXList * m_initialSpawnFX;                       // +0xF8 InitialSpawnFX
	UnsignedInt m_deathAnimationTime;                      // +0xFC DeathAnimationTime; duration, frames
	UnsignedInt m_respawnAnimationTime;                    // +0x100 RespawnAnimationTime; duration, frames
	UnsignedInt m_initialSpawnAnimationTime;               // +0x104 InitialSpawnAnimationTime; duration, frames
	UnsignedByte m_unk0x108[0x4];
	std::set<RespawnRule> m_respawnRules;	// Rules sorted by veterancy level.
	AsciiString m_buttonImage;                             // +0x118 ButtonImage
	AsciiString m_respawnAsTemplate;                       // +0x11C RespawnAsTemplate
};
// SIZE 0x120
typedef char RespawnUpdateModuleData_size[(sizeof(RespawnUpdateModuleData) == 0x120) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_autoRespawnAtObjectFilter[(offsetof(RespawnUpdateModuleData, m_autoRespawnAtObjectFilter) == 0x8) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_deathAnim[(offsetof(RespawnUpdateModuleData, m_deathAnim) == 0xC) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_respawnAnim[(offsetof(RespawnUpdateModuleData, m_respawnAnim) == 0x58) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_initialSpawnAnim[(offsetof(RespawnUpdateModuleData, m_initialSpawnAnim) == 0xA4) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_deathFX[(offsetof(RespawnUpdateModuleData, m_deathFX) == 0xF0) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_respawnFX[(offsetof(RespawnUpdateModuleData, m_respawnFX) == 0xF4) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_initialSpawnFX[(offsetof(RespawnUpdateModuleData, m_initialSpawnFX) == 0xF8) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_deathAnimationTime[(offsetof(RespawnUpdateModuleData, m_deathAnimationTime) == 0xFC) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_respawnAnimationTime[(offsetof(RespawnUpdateModuleData, m_respawnAnimationTime) == 0x100) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_initialSpawnAnimationTime[(offsetof(RespawnUpdateModuleData, m_initialSpawnAnimationTime) == 0x104) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_respawnRules[(offsetof(RespawnUpdateModuleData, m_respawnRules) == 0x10C) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_buttonImage[(offsetof(RespawnUpdateModuleData, m_buttonImage) == 0x118) ? 1 : -1];
typedef char RespawnUpdateModuleData_off_m_respawnAsTemplate[(offsetof(RespawnUpdateModuleData, m_respawnAsTemplate) == 0x11C) ? 1 : -1];

#endif
