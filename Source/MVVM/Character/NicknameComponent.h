// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NicknameComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNicknameChanged, const FString&, InNickname);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MVVM_API UNicknameComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNicknameComponent();
	UFUNCTION(BlueprintCallable)
	void SetNickname(const FString& InNickname)
	{
		Nickname = InNickname;
		OnNicknameChanged.Broadcast(Nickname);
	}
	UFUNCTION(BlueprintCallable)
	const FString& GetNickname() const
	{
		return Nickname;
	}
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:
	UPROPERTY(BlueprintAssignable)
	FOnNicknameChanged OnNicknameChanged;
protected:
	UPROPERTY(EditAnywhere)
	FString Nickname;
};
