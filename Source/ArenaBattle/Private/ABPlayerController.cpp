// c komastar 2021


#include "ABPlayerController.h"

void AABPlayerController::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    ABLOG_S(Warning);
}

void AABPlayerController::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);
    ABLOG_S(Warning);
}

void AABPlayerController::BeginPlay()
{
    Super::BeginPlay();

    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);
}

void AABPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
}
