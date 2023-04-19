// Projet de Jules "Synnah" Ducuing

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API UGameManager : public UWorldSubsystem
{
	GENERATED_BODY()

public : 
	TArray<APawn*>Pawns;
	
};
