// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "WeaponManager.generated.h"

UENUM(BlueprintType)
enum class EWeaponTypeEnum : uint8
{
	WE_AssaultRifle UMETA(DisplayName = "AssaultRifle"),
	WE_Shotgun UMETA(DisplayName = "Shotgun"),
	WE_SniperRifle UMETA(DisplayName = "SniperRifle")
};

UENUM(BlueprintType)
enum class EProjectileTypeEnum : uint8
{
	PE_Energy UMETA(DisplayName = "Energy"),
	PE_Projectile UMETA(DisplayName = "Projectile"),
};

UCLASS()
class WEAPONSYSTEM_API AWeaponManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EWeaponTypeEnum WeaponEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EProjectileTypeEnum ProjectileEnum;

	//AssautRifle

	//Shotgun
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float FShotgunSpread UMETA(DisplayName = "Shotgun Spread");

	//Shotgun-Projectile
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float FShotgunProjectileDamage UMETA(DisplayName = "Shotgun Projectile Damage");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float FShotgunProjectileSpread UMETA(DisplayName = "Shotgun Projectile Spread");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		int IShotgunProjectileAmount UMETA(DisplayName = "Shotgun Projectile Amount");

	//Shotgun-Energy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float FShotgunEnergyDamage UMETA(DisplayName = "Shotgun Energy Damage");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float FShotgunEnergySpread UMETA(DisplayName = "Shotgun Energy Spread");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		int IShotgunEnergyAmount UMETA(DisplayName = "Shotgun Energy Amount");

	//SniperRifle

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AWeaponSystemProjectile> ProjectileClass;

	UFUNCTION()
		void FireWeapon(FVector SpawnPoint, FRotator SpawnRotation);

	UFUNCTION()
		void SetWeaponType();

};
