// Shoot Them Up Game. All right reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "STUMenuHUD.generated.h"

UCLASS()
class SHOOTTHEMUP_API ASTUMenuHUD : public AHUD
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> MenuWidgetClass;
};
