// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TimeManipulator.h"
#include "AudioPlayer.h"
#include "Player2D.generated.h"



UCLASS()
class CPPTEST_API APlayer2D : public APawn
{
	GENERATED_BODY()
		///IDLE, MOVEMENT,ATTACK Animation implementation needed

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	void GetTimeManipulator();

public:
	APlayer2D();
	class AActor *item;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	class AActor *ItemGetter() { return item; };

	UPROPERTY(BlueprintReadOnly)
		bool canMove;
	UFUNCTION(BlueprintCallable)
		void PlayerDeath();
	UFUNCTION(BlueprintCallable)
		void UnEquip();

	void AttackEnemy(class AActor *enemy);
	void PickUp(class AActor *targetObj);
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly)
		bool bPlayerDeath;

	UPROPERTY(VisibleAnywhere)
		bool bIsAttacking;
	///Values for pickups and attack ranges
	UPROPERTY(EditAnywhere, Category = "Movement")
		float moveRange;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float moveSpeed;
	UPROPERTY(EditAnywhere, Category = "Attack")
		float pickUpRange;
	UPROPERTY(EditAnywhere, Category = "Attack")
		float attackTime;
	UPROPERTY(BlueprintReadOnly)
		FVector BulletDirection;

	FVector MovementInput;
	bool bHoldingItem;
	class UBoxComponent *base;
	class ATestPlayerController *PC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTimeManipulator* timeManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AAudioPlayer> audioPlayerBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AAudioPlayer *audioPlayer;
};
