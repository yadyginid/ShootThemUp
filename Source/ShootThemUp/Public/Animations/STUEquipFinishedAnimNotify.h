// Shoot Them Up Game. All right reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "STUEquipFinishedAnimNotify.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnNotifieldSignature, USkeletalMeshComponent*);

UCLASS()
class SHOOTTHEMUP_API USTUEquipFinishedAnimNotify : public UAnimNotify
{
    GENERATED_BODY()

public:
    virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

    FOnNotifieldSignature OnNotifield;
};
