// Shoot Them Up Game. All right reserved.

#include "Animations/STUEquipFinishedAnimNotify.h"

void USTUEquipFinishedAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    OnNotifield.Broadcast(MeshComp);
    Super::Notify(MeshComp, Animation);
}