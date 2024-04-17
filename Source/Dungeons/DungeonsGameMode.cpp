// Copyright Epic Games, Inc. All Rights Reserved.

#include "DungeonsGameMode.h"
#include "DungeonsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADungeonsGameMode::ADungeonsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
