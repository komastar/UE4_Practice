// c komastar 2021


#include "BTTask_Attack.h"
#include "ABAIController.h"
#include "ABCharacter.h"

UBTTask_Attack::UBTTask_Attack()
{
	bNotifyTick = true;
	IsAttacking = false;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
	AABCharacter* Character = Cast<AABCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == Character)
	{
		return EBTNodeResult::Failed;
	}

	Character->Attack();
	IsAttacking = true;
	Character->OnAttackEnd.AddLambda([this]() -> void
		{
			IsAttacking = false;
		});

	return EBTNodeResult::InProgress;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	if (false == IsAttacking)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);		
	}
}
