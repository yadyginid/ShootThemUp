// Shoot Them Up Game. All right reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/STUBasePickup.h"
#include "STUHealthPickup.generated.h"

UCLASS()
class SHOOTTHEMUP_API ASTUHealthPickup : public ASTUBasePickup
{
    GENERATED_BODY()

public:
    virtual bool GivePickUpTo(APawn* PlayerPawn) override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1.0", ClampMax = "100.0"))
    float HealthAmount = 100.f;
};
