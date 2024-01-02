// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WindComponent.h"

#include "Interfaces/WindInterface.h"

// Sets default values for this component's properties
UWindComponent::UWindComponent()
{
}

bool UWindComponent::GetCanWindBlast()
{
	return _bCanWindBlast;
}

void UWindComponent::SetCanWindBlast_Implementation(bool bCanWindBlast)
{
	_bCanWindBlast = bCanWindBlast; 
}


// Called when the game starts
void UWindComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UWindComponent::AttemptWindBlast(const float& Strength, const FVector& Origin, const FVector& Direction)
{
	if(GetCanWindBlast())
	{
		UE_LOG(LogTemp, Display, TEXT("Can Wind Blast"))
		FHitResult HitResult;
		const FCollisionObjectQueryParams CollisionObjectQueryParams = FCollisionObjectQueryParams::DefaultObjectQueryParam;

		FCollisionQueryParams QueryParams = FCollisionQueryParams::DefaultQueryParam;
		QueryParams.AddIgnoredActor(GetOwner());
		
		// Line Trace in the Direction of the 
		if(GetWorld()->LineTraceSingleByObjectType(HitResult,
			Origin, Origin + Direction*Strength, CollisionObjectQueryParams, QueryParams))
		{

			if(IsValid(HitResult.GetActor()))
			{
				if(HitResult.GetActor()->Implements<UWindInterface>())
				{
					if(IWindInterface::Execute_AttemptWindBlast(HitResult.GetActor(), Strength, Direction))
					{
						UE_LOG(LogTemp, Display, TEXT("Wind Blast Attempt was Successful on [%s]"), *GetNameSafe(HitResult.GetActor()))
						return;
					}
				}
			}
			

			if(IWindInterface::Execute_AttemptWindBlast(GetOwner(), Strength, -Direction)){
				UE_LOG(LogTemp, Display, TEXT("Wind Blast Attempt was Successful on [%s]"), *GetNameSafe(GetOwner()))
				return;
			}
		}

		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No Collision, Cannot Wind Blast"));
		}
	
	}
}

