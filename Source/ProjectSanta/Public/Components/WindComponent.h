// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollisionQueryParams.h"
#include "WindComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSANTA_API UWindComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWindComponent();

	UFUNCTION(BlueprintPure)
	bool GetCanWindBlast();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, Category="Wind")
	void AttemptWindBlast(const float& Strength, const FVector& Origin, const FVector& Direction);
	

	UFUNCTION(BlueprintNativeEvent, Category="Wind")
	void SetCanWindBlast(bool bCanWindBlast);


private:

	bool _bCanWindBlast = true;
	
};
