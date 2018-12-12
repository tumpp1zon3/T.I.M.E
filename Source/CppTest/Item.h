// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Item.generated.h"

UCLASS()
class CPPTEST_API AItem : public APawn
{
	GENERATED_BODY()

public:

	AItem();
	UFUNCTION(BlueprintCallable)
		void Physics(float deltatime);
	UFUNCTION(BlueprintCallable)
		void Bounce(float deltatime);
	UFUNCTION(BlueprintCallable)
		void DestroyFunc();
	///Calls blueprint function attack
	UFUNCTION(BlueprintImplementableEvent)
		void UseWeapon(bool hitenemy, FVector direction);
	UFUNCTION()
		void DestroyWeapon();

	UPROPERTY(EditAnywhere, Category = "Variables")
		FTransform ItemOffset;
	UPROPERTY(EditDefaultsOnly, Category = Combat, BlueprintReadWrite)
		bool meleeweapon;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Variables)
		int endurance;

protected:

	UPROPERTY(BlueprintReadWrite)
		float shoottime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
		float firerate;
	UPROPERTY(EditAnywhere, Category = "CustomPhysics")
		float weight;
	UPROPERTY(EditAnywhere, Category = "CustomPhysics")
		float groundLevel;
	UPROPERTY(EditDefaultsOnly, Category = "Variables")
		float destroyTime;
	float lastSpeed;
	// Default transform offset position when picked up

	FTransform GetOffset() { return ItemOffset; }
};
