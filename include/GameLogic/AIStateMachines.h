#pragma once

#include "Common/StateMachine.h"


// These AI state machines add no storage to StateMachine. Each allocation
// call cited below passes sizeof(StateMachine), 0x3C.

// Allocation at 0x0034B236.
class AttackMeleeStateMachine : public StateMachine
{
public:
	AttackMeleeStateMachine(Object *owner, Int, UnsignedInt);	// 0x0034316A
	virtual ~AttackMeleeStateMachine();
	const char *name() const;

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x0033FB05
	virtual void xfer(Xfer *xfer);	// slot 3, 0x0033FB0B
};

// Allocation at 0x0034B37D.
class AttackStateMachine : public StateMachine
{
public:
	virtual ~AttackStateMachine() {}		// 0x0033FAE9 (COMDAT)

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x0033FAF4
	virtual void xfer(Xfer *xfer);					// slot 3, the fold 0x0033FB0B
};

// Allocation at 0x0034B26A.
class AttackHordeStateMachine : public StateMachine
{
public:
	virtual ~AttackHordeStateMachine() {}		// 0x0033FB20 (COMDAT)

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x0033FB6D
	virtual void xfer(Xfer *xfer);					// slot 3, the fold 0x0033FB0B
};

// Allocation at 0x0034B201.
class AttackFireWhileMovingMachine : public StateMachine
{
public:
	virtual ~AttackFireWhileMovingMachine() {}		// 0x0033FB73 (COMDAT)

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x0033FB7E
	virtual void xfer(Xfer *xfer);					// slot 3, the fold 0x0033FB0B
};

// Allocation at 0x00343D15.
class MoveOntoWallStateMachine : public StateMachine
{
public:
	MoveOntoWallStateMachine(Object *owner, UnsignedInt name);	// 0x00343BC9
	virtual ~MoveOntoWallStateMachine() {}		// 0x0033FC0A (COMDAT)

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x0033FC15
	virtual void xfer(Xfer *xfer);					// slot 3, the fold 0x0033FB0B
};

// Allocation at 0x0034E35E.
class AIAttackMoveStateMachine : public StateMachine
{
public:
	virtual ~AIAttackMoveStateMachine() {}		// 0x0034004C (COMDAT)

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x00340057
	virtual void xfer(Xfer *xfer);					// slot 3, the fold 0x0033FB0B
};

// Allocation at 0x0034B2A8.
class AttackContesterStateMachine : public StateMachine
{
public:
	AttackContesterStateMachine(Object *owner, Int, UnsignedInt);	// 0x00343756
	virtual ~AttackContesterStateMachine();
	const char *name() const;

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x0033FB8F
	virtual void xfer(Xfer *xfer);	// slot 3, 0x0033FB0B
};

// Allocation at 0x0034B2DC.
class AttackFireWhileChargingMachine : public StateMachine
{
public:
	AttackFireWhileChargingMachine(Object *owner, Int, UnsignedInt, Bool);	// 0x00343838
	virtual ~AttackFireWhileChargingMachine();
	const char *name() const;

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x0033FBA0
	virtual void xfer(Xfer *xfer);	// slot 3, 0x0033FB0B
};

// Allocation at 0x0034B32C.
class AttackPositionStateMachine : public StateMachine
{
public:
	virtual ~AttackPositionStateMachine();
	const char *name() const;

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x0033FBB1
	virtual void xfer(Xfer *xfer);	// slot 3, 0x0033FB0B
};

// Allocation at 0x0034B357.
// 0x00343A86 calls StateMachine's constructor before storing table 0x00811CF0.
// Its only changed slots are the deleting destructor, snapshot name and xfer.
class AttackPositionHordeStateMachine : public StateMachine
{
public:
	virtual ~AttackPositionHordeStateMachine();
	const char *name() const;	// Current symbol for slot 2

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x0033FC04
	virtual void xfer(Xfer *xfer);	// slot 3, 0x0033FB0B
};

// Allocation at 0x00347C4E.
class BackAwayAndCowerStateMachine : public StateMachine
{
public:
	BackAwayAndCowerStateMachine(Object *owner, Object *, UnsignedInt);	// 0x003444CE
	virtual ~BackAwayAndCowerStateMachine();
	const char *name() const;

protected:
	virtual const char *GetSnapshotName() const;	// slot 2, 0x003402DB
	virtual void xfer(Xfer *xfer);	// slot 3, 0x003402E1
};
