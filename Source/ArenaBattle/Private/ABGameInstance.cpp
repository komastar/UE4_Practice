// c komastar 2021


#include "ABGameInstance.h"

UABGameInstance::UABGameInstance()
{
    FString CharacterDataPath = TEXT("/Game/Book/GameData/ABCharacterData.ABCharacterData");
    static ConstructorHelpers::FObjectFinder<UDataTable> DT_ABCHARACTER(*CharacterDataPath);
    ABCHECK(DT_ABCHARACTER.Succeeded());
    ABCharacterTable = DT_ABCHARACTER.Object;
    ABCHECK(0 < ABCharacterTable->GetRowMap().Num());
}

void UABGameInstance::Init()
{
    Super::Init();
    ABLOG(Warning, TEXT("DropExp of Level 20 ABCharacter : %d"), GetABCharacterData(20)->DropExp);
}

FABCharacterData* UABGameInstance::GetABCharacterData(int32 Level)
{
    return ABCharacterTable->FindRow<FABCharacterData>(*FString::FromInt(Level), TEXT(""));
}
