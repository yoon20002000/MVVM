// Fill out your copyright notice in the Description page of Project Settings.


#include "HpComponent.h"

// Sets default values for this component's properties
UHpComponent::UHpComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	MaxHp = 100;
	CurrentHp = MaxHp;
}


// Called when the game starts
void UHpComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}