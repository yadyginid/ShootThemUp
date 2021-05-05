// Shoot Them Up Game. All right reserved.

#include "Pickups/STUAmmoPickup.h"
#include "Components/STUWeaponComponent.h"
#include "Components/STUHealthComponent.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);

bool ASTUAmmoPickup::GivePickUpTo(APawn* PlayerPawn)
{
    UE_LOG(LogAmmoPickup, Display, TEXT("ASTUAmmoPickup::GivePickUpTo1"));
    const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);

    if (!HealthComponent || HealthComponent->IsDead()) return false;

    UE_LOG(LogAmmoPickup, Display, TEXT("ASTUAmmoPickup::GivePickUpTo2"));
    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(PlayerPawn);

    if (!WeaponComponent) return false;
    UE_LOG(LogAmmoPickup, Display, TEXT("ASTUAmmoPickup::GivePickUpTo3"));
    return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}