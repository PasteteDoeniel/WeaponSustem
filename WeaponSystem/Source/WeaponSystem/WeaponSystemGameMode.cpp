// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "WeaponSystemGameMode.h"
#include "WeaponSystemHUD.h"
#include "WeaponSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWeaponSystemGameMode::AWeaponSystemGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AWeaponSystemHUD::StaticClass();
}
