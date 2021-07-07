// Shoot Them Up Game. All right reserved.

#include "Menu/UI/STUMenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/STUBaseWidget.h"

void ASTUMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (MenuWidgetClass)
    {
        const auto MenuWidget = CreateWidget<USTUBaseWidget>(GetWorld(), MenuWidgetClass);
        if (MenuWidget)
        {
            MenuWidget->AddToViewport();
            MenuWidget->Show();
        }
    }
}