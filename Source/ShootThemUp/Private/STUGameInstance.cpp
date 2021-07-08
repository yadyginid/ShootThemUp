// Shoot Them Up Game. All right reserved.

#include "STUGameInstance.h"
#include "Sound/SoundClass.h"
#include "Sound/STUSoundFuncLib.h"

void USTUGameInstance::ToggleVolume()
{
    USTUSoundFuncLib::ToggleSoundClassVolume(MasterSoundClass);
}