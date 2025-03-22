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

	UFUNCTION(BlueprintCallable)
	void AddMaxHp(float InAddMaxAmount)
	{
		MaxHp += InAddMaxAmount;
		OnMaxHpChange.Broadcast(MaxHp);
	}
	UFUNCTION(BlueprintCallable)
	void SetMaxHp(float InMaxHp)
	{
		MaxHp = InMaxHp;
		OnMaxHpChange.Broadcast(MaxHp);
	}
	UFUNCTION(BlueprintCallable)
	float GetMaxHp() const
	{
		return MaxHp;
	}
	UFUNCTION(BlueprintCallable)
	void AddHp(float InAddHpAmount)
	{
		CurrentHp += InAddHpAmount;
		OnHpChange.Broadcast(CurrentHp);
	}
	UFUNCTION(BlueprintCallable)
	void SetHp(float InHp)
	{
		CurrentHp = InHp;
		OnHpChange.Broadcast(CurrentHp);
	}
	UFUNCTION(BlueprintCallable)
	float GetHp() const
	{
		return CurrentHp;
	}
	UFUNCTION(BlueprintCallable)
	float GetHpPercentage() const
	{
		return CurrentHp / MaxHp;	
	}
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FOnMaxHpChange OnMaxHpChange;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FOnHpChange OnHpChange;
	
protected:
	UPROPERTY(EditAnywhere)
	float MaxHp;
	UPROPERTY(EditAnywhere, Transient)
	float CurrentHp;
};
