// Shoot Them Up Game. All right reserved.

#include "Menu/STUMenuPlayerController.h"

void ASTUMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}
