﻿//Name of class:	CCrouchingPlayerMovementState
//Main author:		Toyan Green
//Summary:			This class is responsible for the player crouching
//					in the game.
//Functions:		VEnter, VUpdate, VHandleInput

#ifndef	_CCROUCHINGPLAYERMOVEMENTSTATE_H_
#define	_CCROUCHINGPLAYERMOVEMENTSTATE_H_

#ifndef	_ISOUNDEFFECT_H_
#include "ImpossibleRescue/Audio/ISoundEffect.h"
#endif

#include "../CPlayerMovementState.h"

class CCrouchingPlayerMovementState
	: public CPlayerMovementState
{
public:
	CCrouchingPlayerMovementState();
	
	virtual ~CCrouchingPlayerMovementState() override;

	// Initialise the movement state.
	virtual void VInitialise() override;
	
	//State beginning transition. Called once when player movement state is set to this state.
	virtual void VEnter(CPlayer& player) override;

	//Update loop. Called from CPlayer VOnUpdate.
	virtual CPlayerMovementState* VUpdate(CPlayer& player) override;

	//Handle player input. Called from CPlayer VOnUpdate.
	virtual CPlayerMovementState* VHandleInput(CPlayer& player, TGCController< EPlayerActions >& input) override;

protected:

	virtual const char* VGetAnimationName() const override;
	virtual const char* VGetPhysicsShapeName() const override;

private:
	
	void CleanupSoundEffects();

	ISoundEffect* m_psfxCrouchSound;
	ISoundEffect* m_psfxStandUpSound;
	const char*   mk_pszAnim_DanielleCrouching = "Crouching";
	const char*   mk_pszPhys_DanielleCrouching = "Danielle_Crouching";
};

#endif