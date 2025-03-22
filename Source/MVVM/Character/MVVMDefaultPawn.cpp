// Fill out your copyright notice in the Description page of Project Settings.


#include "MVVMDefaultPawn.h"

#include "HpComponent.h"
#include "NicknameComponent.h"

// Sets default values
AMVVMDefaultPawn::AMVVMDefaultPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	HpComponent = CreateDefaultSubobject<UHpComponent>(TEXT("Hp Component"));
	ensure(HpComponent);
	NicknameComponent = CreateDefaultSubobject<UNicknameComponent>(TEXT("Nickname Component"));
	ensure(NicknameComponent);
}

// Called when the game starts or when spawned
void AMVVMDefaultPawn::BeginPlay()
{
	Super::BeginPlay();
	
}