// c komastar 2021


#include "ABGameMode.h"
#include "ABCharacter.h"
#include "ABPawn.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode()
{
    DefaultPawnClass = AABCharacter::StaticClass();
    PlayerControllerClass = AABPlayerController::StaticClass();
}

void AABGameMode::PostLogin(APlayerController* NewPlayer)
{
    ABLOG(Warning, TEXT("PostLogin Begin"));
    Super::PostLogin(NewPlayer);
    ABLOG(Warning, TEXT("PostLogin End"));
}
