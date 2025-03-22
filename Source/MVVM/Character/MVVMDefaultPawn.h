// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HpComponent.h"
#include "NicknameComponent.h"
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
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetHp()const
	{
		return HpComponent->GetHp(); 
	}
	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetMaxHp()const
	{
		return HpComponent->GetMaxHp();
	}
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetHp(float InHp)
	{
		HpComponent->SetHp(InHp);
	}
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetMaxHp(float InMaxHp)
	{
		HpComponent->SetMaxHp(InMaxHp);
	}
	FORCEINLINE const FString& GetNickname()
	{
		return NicknameComponent->GetNickname();
	}
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetNickName(const FString& InName)
	{
		NicknameComponent->SetNickname(InName);
	}
	UFUNCTION(BlueprintCallable)
	UHpComponent* GetHpComponent()
	{
		return HpComponent;
	}
	UFUNCTION(BlueprintCallable)
	UNicknameComponent* GetNicknameComponent()
	{
		return NicknameComponent;
	}
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UHpComponent> HpComponent;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UNicknameComponent> NicknameComponent;
};
