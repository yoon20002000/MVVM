// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MVVMDefaultPawn.generated.h"

class UNicknameComponent;
class UHpComponent;

UCLASS()
class MVVM_API AMVVMDefaultPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMVVMDefaultPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	UPROPERTY()
	TObjectPtr<UHpComponent> HpComponent;
	UPROPERTY()
	TObjectPtr<UNicknameComponent> NicknameComponent;
};
