// MMOClient 2020


#include "BaseQuestListWindow.h"
#include "WorldGameInstance.h"

FQuestTable UBaseQuestListWindow::GetQuestObjectByQuestId(int32 questId)
{
	UWorldGameInstance* wgi = Cast<UWorldGameInstance>(GetGameInstance());
	for (auto questRow : wgi->questsTable->GetRowMap())
	{
		FQuestTable* row = (FQuestTable*)questRow.Value;
		if (FString::FromInt(questId).Equals(row->id.ToString()))
		{
			return *row;
		}
	}
	return FQuestTable();
}

FQuestStep UBaseQuestListWindow::GetQuestStepObjectByQuestIdAndStep(int32 questId, FString step)
{
	UWorldGameInstance* wgi = Cast<UWorldGameInstance>(GetGameInstance());
	for (auto questRow : wgi->questsStepsTable->GetRowMap())
	{
		FQuestStep* row = (FQuestStep*)questRow.Value;
		if (questId == row->questId && step.Equals(row->questStep.ToString()))
		{
			return *row;
		}
	}
	return FQuestStep();
}

FItemTable UBaseQuestListWindow::GetItemTableObject(int32 item_id)
{
	UWorldGameInstance* wgi = Cast<UWorldGameInstance>(GetGameInstance());
	return *(wgi->itemsTable->FindRow<FItemTable>(FName(*FString::FromInt(item_id)), "", true));
}
UTexture2D* UBaseQuestListWindow::GetItemTexture(int32 item_id)
{
	FItemTable item = GetItemTableObject(item_id);
	auto* texture = LoadObject<UTexture2D>(NULL, *item.icon.ToString());

	return texture;
}
FString UBaseQuestListWindow::GetItemName(int32 item_id)
{
	FItemTable item = GetItemTableObject(item_id);
	return item.name.ToString();
}