// c komastar 2021


#include "ABPlayerController.h"

void AABPlayerController::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    ABLOG_S(Warning);
}

void AABPlayerController::Possess(APawn* aPawn)
{
    Super::Possess(aPawn);
    ABLOG_S(Warning);
}
