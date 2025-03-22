// Fill out your copyright notice in the Description page of Project Settings.


#include "NicknameComponent.h"

// Sets default values for this component's properties
UNicknameComponent::UNicknameComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	Nickname = TEXT("Dev Rookie");
}


// Called when the game starts
void UNicknameComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


