// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HpComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHpChange, float, MaxHp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHpChange, float, CurrentHp);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MVVM_API UHpComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHpComponent();

	FORCEINLINE void AddMaxHp(float InAddMaxAmount)
	{
		MaxHp += InAddMaxAmount;
		OnMaxHpChange.Broadcast(MaxHp);
	}
	FORCEINLINE void SetMaxHp(float InMaxHp)
	{
		MaxHp = InMaxHp;
		OnMaxHpChange.Broadcast(MaxHp);
	}
	FORCEINLINE float GetMaxHp() const
	{
		return MaxHp;
	}
	FORCEINLINE void AddHp(float InAddHpAmount)
	{
		CurrentHp += InAddHpAmount;
		OnHpChange.Broadcast(CurrentHp);
	}
	FORCEINLINE void SetHp(float InHp)
	{
		CurrentHp = InHp;
		OnHpChange.Broadcast(CurrentHp);
	}
	FORCEINLINE float GetHp() const
	{
		return CurrentHp;
	}
	
	FORCEINLINE float GetHpPercentage() const
	{
		return CurrentHp / MaxHp;	
	}
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FOnMaxHpChange OnMaxHpChange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FOnHpChange OnHpChange;
	
protected:
	UPROPERTY(EditAnywhere)
	float MaxHp;
	UPROPERTY(EditAnywhere, Transient)
	float CurrentHp;
};
