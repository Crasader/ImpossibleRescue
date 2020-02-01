﻿//Name of class:	CIdleCrouchingPlayerMovementState
//Main author:		Toyan Green
//Summary:			This class is responsible for the player idling whilst crouching
//					in the game.
//Functions:		VEnter, VUpdate, VHandleInput

#ifndef	_CIDLECROUCHINGPLAYERMOVEMENTSTATE_H_
#define	_CIDLECROUCHINGPLAYERMOVEMENTSTATE_H_

#ifndef	_ISOUNDEFFECT_H_
#include "ImpossibleRescue/Audio/ISoundEffect.h"
#endif

#include "../CPlayerMovementState.h"

class CIdleCrouchingPlayerMovementState
	: public CPlayerMovementState
{
public:
	CIdleCrouchingPlayerMovementState();

	virtual ~CIdleCrouchingPlayerMovementState() override;

	// Initialise the movement state.
	virtual void VInitialise() override;
	
	//State beginning transition. Called once when player movement state is set to this state.
	virtual void VEnter(CPlayer& player) override;

	//state exit
	virtual void VExit(CPlayer& player) override;

	//Update loop. Called from CPlayer VOnUpdate.
	virtual CPlayerMovementState* VUpdate(CPlayer& player) override;

	//Handle player input. Called from CPlayer VOnUpdate.
	virtual CPlayerMovementState* VHandleInput(CPlayer& player, TGCController< EPlayerActions >& input) override;

protected:

	virtual const char* VGetAnimationName() const override;
	virtual const char* VGetPhysicsShapeName() const override;

private:

	void CleanupSoundEffects();

	ISoundEffect* m_psfxIdleCrouching;
	const char*   mk_pszAnim_DanielleIdleCrouching = "IdleCrouching";
	const char*   mk_pszPhys_DanielleIdleCrouching = "Danielle_Crouching_Idle";
};

#endif