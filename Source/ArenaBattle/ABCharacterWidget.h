// c komastar 2021

#pragma once

#include "ArenaBattle.h"
#include "Blueprint/UserWidget.h"
#include "ABCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	void UpdateHPWidget();
	
public:
	void BindCharacterStat(class UABCharacterStatComponent* NewCharacterStat);

private:
	TWeakObjectPtr<class UABCharacterStatComponent> CurrentCharaccterStat;

	UPROPERTY()
	class UProgressBar* HPProgressBar;
};
