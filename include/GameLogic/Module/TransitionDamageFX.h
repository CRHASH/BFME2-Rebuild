// TransitionDamageFX.h: the damage module that plays effects when an object's body changes damage state. SIZE 0xE0
// (ModuleFactory operator new). Target facts: the constructor 0x004BA3EA calls DamageModule first, then
// stores the tables 0x00859AEC at +0x0, 0x00859A30 at +0xC and 0x00859A20 at +0x10, builds the neighbour list at +0xD4
// (fill 0x00211E58) and zeroes the 48 particle-system IDs at +0x14 that xfer 0x004B98C6 transfers (four groups of twelve).
#pragma once
#ifndef BFME2_TRANSITION_DAMAGE_F_X_H
#define BFME2_TRANSITION_DAMAGE_F_X_H

#include <stddef.h>
#include <vector>
#include "Common/GameType.h"
#include "GameLogic/Module/DamageModule.h"
#include "GameLogic/Module/TransitionDamageFXModuleData.h"

class Thing;
class ModuleData;
class Xfer;
class DamageInfo;
class Dict;

class TransitionDamageFX : public DamageModule
{
public:
	TransitionDamageFX(Thing *thing, const ModuleData *moduleData);
	static Module *friend_newModuleInstance(Thing *thing, const ModuleData *moduleData);
	virtual NameKeyType getModuleNameKey() const;
	virtual void onDamage(DamageInfo *damageInfo) {}	// DamageModuleInterface slot 0, retail word 0x0047A69C (the shared fold)
	virtual void onHealing(DamageInfo *damageInfo) {}	// DamageModuleInterface slot 1, retail word 0x0047A69C (the shared fold)
	virtual void onBodyDamageStateChange(const DamageInfo *damageInfo, BodyDamageType oldState, BodyDamageType newState);
	void bfmeUseFDE(void *damageState);									// (the ledger's name and signature): hide and show the module data's sub-objects for the BodyDamageType passed
	virtual void onDrawableBoundToObject();									// slot 6, 0x004B9D86 (the ledger's name bfmeGoFDE): the same hide and show for the object's current damage state
	void rva004B9DA9(Bool recurse);										// The neighbours' share of a state change
	virtual void mapLoadPostProcess(const Dict *properties);			// slot 45, 0x004BA9E4

protected:
	virtual const char *GetSnapshotName() const;
	virtual void xfer(Xfer *xfer);
	virtual ~TransitionDamageFX();
	virtual void loadPostProcess() { DamageModule::loadPostProcess(); }	// retail slot 1 0x00497805: a jmp to DamageModule's

public:
	Int m_particleSystemIDs[4][12];				// +0x14; xfer loop 0x004B98C6 (4 groups of 12 ParticleSystemIDs)
	_STL::vector<TransitionNeighborInfo> m_neighbors;	// +0xD4
};
// SIZE 0xE0
typedef char TransitionDamageFX_size[(sizeof(TransitionDamageFX) == 0xE0) ? 1 : -1];

#endif
