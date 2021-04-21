#include "AssetDatabase.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "Database/ItemRenderPropertiesBase.h"

/**
 * @author Dego1n
 * Ох... когда же уже меня вынесут в файлы
 */
AssetDatabase* AssetDatabase::instance = nullptr;

AssetDatabase* AssetDatabase::GetInstance()
{
	if(instance == nullptr)
	{
		instance = new AssetDatabase();
	}
	return instance;
}

AssetDatabase::AssetDatabase()
{
	LoadCharacterAnimations();
	LoadCharacterAnimationMontages();
	LoadCharacterRaces();
	LoadActorTemplates();
	LoadItemRenderProperties();
}

AssetDatabase::~AssetDatabase()
{
}

void AssetDatabase::LoadItemRenderProperties()
{
	UDataTable* DataTable = LoadObject<UDataTable>(NULL, TEXT("DataTable'/Game/Data/Items/ItemRenderProperties.ItemRenderProperties'"), NULL, LOAD_None, NULL);
	FString Context; //
	TArray<FName> Names = DataTable->GetRowNames();
	if (!Names.Num()) return;
	TArray<FItemRenderPropertiesBase*> OutAllRows;
	DataTable->GetAllRows<FItemRenderPropertiesBase>(Context, OutAllRows);
	for (FItemRenderPropertiesBase* row : OutAllRows)
	{
		//Do something. Find Row Function -> * (DataTable->FindRow<FStructure> (Names[X], Context, true))
		//FItemRenderPropertiesBase* row = DataTable->FindRow<FItemRenderPropertiesBase>(Names[X], Context, true);
		//FName test = Names[X];
		itemRenderProperties.Add(row);
	}
}
void AssetDatabase::LoadUserWidgets()
{
	userWidgets.Add(
		UserWidgets{
			 "actorNameWidget",
			"WidgetBlueprint'/Game/CharacterNameWidget.CharacterNameWidget'"
		}
	);
}

void AssetDatabase::LoadCharacterRaces()
{
	characterRaces.Add(
		CharacterRaces{
		0,
		//"SkeletalMesh'/Game/Models/PlayableCharacters/Human/Male_Human_Rigged.Male_Human_Rigged'"
		//"SkeletalMesh'/Game/Models/PlayableCharacters/Humanv2/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"
		"SkeletalMesh'/Game/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone_empty.Greystone_empty'"
		}
	);
	characterRaces.Add(
		CharacterRaces{
		1,
		"SkeletalMesh'/Game/Models/PlayableCharacters/Elf/Female_Elf_Rigged.Female_Elf_Rigged'"
		}
	);
}

void AssetDatabase::LoadCharacterAnimations()
{
	//HUMAN MALE
	characterAnimations.Add(
		ActorAnimations {
		0,
		//"Class'/Game/Models/PlayableCharacters/Human/Animations/MaleHumanAnimBlueprint.MaleHumanAnimBlueprint_C'"
		//"Class'/Game/Models/PlayableCharacters/Humanv2/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP_C'"
		//"Class'/Game/Models/PlayableCharacters/Human/Animations/MaleHumanAnimBlueprint.MaleHumanAnimBlueprint_C'"
		"AnimBlueprint'/Game/ParagonGreystone/Characters/Heroes/Greystone/Greystone_AnimBlueprint.Greystone_AnimBlueprint_C'"
		}
	);

	//FEMALE ELF
	characterAnimations.Add(
		ActorAnimations {
		1,
		"Class'/Game/Models/PlayableCharacters/Elf/Animations/FemaleElfAnimBlueprint.FemaleElfAnimBlueprint_C'"
		}
	);

	//ZOMBIE
	characterAnimations.Add(
		ActorAnimations
		{
			101,
			"Class'/Game/Models/Actors/101/Animations/Animation.Animation_C'"
		}
	);
	//Manequen TODO
}

void AssetDatabase::LoadCharacterAnimationMontages()
{
	characterAnimationMontages.Add(
		ActorAnimationMontages{
			0,
			"Attack_1HandSword",
			//"AnimMontage'/Game/Models/PlayableCharacters/Humanv2/Mannequin/Animations/Combat/A_SW_Attack_01_Montage.A_SW_Attack_01_Montage'"
			"AnimMontage'/Game/ParagonGreystone/Characters/Heroes/Greystone/Animations/Attack_A_Med_Montage.Attack_A_Med_Montage'"
		}
	);

	characterAnimationMontages.Add(
		ActorAnimationMontages{
			0,
			"Attack_1HandSword",
			//"AnimMontage'/Game/Models/PlayableCharacters/Humanv2/Mannequin/Animations/Combat/A_SW_Attack_02_Montage.A_SW_Attack_02_Montage'"
			"AnimMontage'/Game/ParagonGreystone/Characters/Heroes/Greystone/Animations/Attack_B_Med_MSA_Montage.Attack_B_Med_MSA_Montage'"
		}
	);

	characterAnimationMontages.Add(
		ActorAnimationMontages{
			0,
			"Attack_1HandSword",
			//"AnimMontage'/Game/Models/PlayableCharacters/Humanv2/Mannequin/Animations/Combat/A_SW_Attack_03_Montage.A_SW_Attack_03_Montage'"
			"AnimMontage'/Game/ParagonGreystone/Characters/Heroes/Greystone/Animations/Attack_C_Med_MSA_Montage.Attack_C_Med_MSA_Montage'"
		}
	);

	characterAnimationMontages.Add(
		ActorAnimationMontages{
			0,
			"Attack_1HandSword",
			//"AnimMontage'/Game/Models/PlayableCharacters/Humanv2/Mannequin/Animations/Combat/A_SW_Attack_04_Montage.A_SW_Attack_04_Montage'"
			"AnimMontage'/Game/ParagonGreystone/Characters/Heroes/Greystone/Animations/Attack_D_Med_MSA_Montage.Attack_D_Med_MSA_Montage'"
		}
	);

	characterAnimationMontages.Add(
		ActorAnimationMontages{
			0,
			"Attack_1HandSword",
			//"AnimMontage'/Game/Models/PlayableCharacters/Humanv2/Mannequin/Animations/Combat/A_SW_Attack_05_Montage.A_SW_Attack_05_Montage'"
			"AnimMontage'/Game/ParagonGreystone/Characters/Heroes/Greystone/Animations/Attack_PrimaryA_Montage.Attack_PrimaryA_Montage'"
		}
	);
	characterAnimationMontages.Add(
		ActorAnimationMontages{
			0,
			"Skill_1",
			//"AnimMontage'/Game/Models/PlayableCharacters/Humanv2/Mannequin/Animations/Combat/A_SW_Combo_Montage.A_SW_Combo_Montage'"
			"AnimMontage'/Game/ParagonGreystone/Characters/Heroes/Greystone/Animations/Ability_E_MSA_Montage.Ability_E_MSA_Montage'"
		}
	);
	characterAnimationMontages.Add(
		ActorAnimationMontages{
			0,
			"Skill_2",
			//"AnimMontage'/Game/Models/PlayableCharacters/Humanv2/Mannequin/Animations/Combat/A_SW_Fatality_Atacker_02_Montage.A_SW_Fatality_Atacker_02_Montage'"
			"AnimMontage'/Game/ParagonGreystone/Characters/Heroes/Greystone/Animations/Ability_E_MSA_Montage.Ability_E_MSA_Montage'"
		}
	);
	characterAnimationMontages.Add(
		ActorAnimationMontages{
			0,
			"Skill_3",
			//"AnimMontage'/Game/Models/PlayableCharacters/Humanv2/Mannequin/Animations/Combat/A_SW_HeavyAttack_Montage.A_SW_HeavyAttack_Montage'"
			"AnimMontage'/Game/ParagonGreystone/Characters/Heroes/Greystone/Animations/Ability_E_MSA_Montage.Ability_E_MSA_Montage'"
		}
	);
	characterAnimationMontages.Add(
		ActorAnimationMontages {
			101,
			"Attack_1HandSword",
			"AnimMontage'/Game/Models/Actors/101/Animations/Inside_Crescent_Kick_Montage.Inside_Crescent_Kick_Montage'"
		}
	);

	characterAnimationMontages.Add(
		ActorAnimationMontages{
			101,
			"Attack_1HandSword",
			"AnimMontage'/Game/Models/Actors/101/Animations/Punching_Montage.Punching_Montage'"
		}
	);

	characterAnimationMontages.Add(
		ActorAnimationMontages{
			101,
			"Attack_1HandSword",
			"AnimMontage'/Game/Models/Actors/101/Animations/Roundhouse_Kick_Montage.Roundhouse_Kick_Montage'"
		}
	);
	characterAnimationMontages.Add(
		ActorAnimationMontages{
			101,
			"Die",
			"AnimMontage'/Game/Models/Actors/101/Animations/Dying_Montage.Dying_Montage'"
		}
	);

}

void AssetDatabase::LoadActorTemplates()
{
	actorTemplates.Add(
		ActorTemplates{
		100,
		"SkeletalMesh'/Game/Arissa/arissa.arissa'"
		}
	);

	actorTemplates.Add(
		ActorTemplates{
		101,
		"SkeletalMesh'/Game/Models/Actors/101/Zombie.Zombie'"
		}
	);

	actorTemplates.Add(
		ActorTemplates{
		102,
		"SkeletalMesh'/Game/Models/Actors/102/SK_Mannequin_2.SK_Mannequin_2'"
		}
	);

	actorTemplates.Add(
		ActorTemplates{
		103,
		"SkeletalMesh'/Game/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone'"
		}
	);
}

FString AssetDatabase::GetAnimationsForActor(int32 templateId)
{
	if(characterAnimations.Num() == 0)
	{
		LoadCharacterAnimations();
	}
	TArray<AssetDatabase::ActorAnimations> animations;

	for(AssetDatabase::ActorAnimations actorAnimation : characterAnimations)
	{
		if(actorAnimation.actorId == templateId)
		{
			return actorAnimation.animationsPath;
		}
	}
	return "undefined";
}


FString AssetDatabase::GetSkeletalMeshForCharacterRace(int32 raceId)
{
	for (CharacterRaces cr : characterRaces)
	{
		if(cr.raceId == raceId)
		{
			return cr.skeletalMeshPath;
		}
	}
	return "undefined";
}

FString AssetDatabase::GetSkeletalMeshForActor(int32 actorTemplate)
{
	for(ActorTemplates at : actorTemplates)
	{
		if(at.templateId == actorTemplate)
		{
			return at.skeletalMeshPath;
		}
	}
	return "undefined";
}

TArray<AssetDatabase::ActorAnimationMontages> AssetDatabase::GetActorMontageAnimations(int32 actorTemplate)
{
	TArray<AssetDatabase::ActorAnimationMontages> animations;
	for (ActorAnimationMontages montage : characterAnimationMontages)
	{
		if (montage.actorId == actorTemplate)
		{
			animations.Add(montage);
		}
	}
	return animations;
}
FItemRenderPropertiesBase* AssetDatabase::GetItemPropertiesByActorAndItem(int32 actorId, int32 itemId)
{
	for (FItemRenderPropertiesBase* item : itemRenderProperties)
	{
		if (item->actorTemplate == actorId && item->itemId == itemId)
		{
			return item;
		}
	}
	return nullptr;
}
/**
 * TODO: Что это ???? О_О
 */
UUserWidget* AssetDatabase::GetUserWidgetByName(FString name)
{
	for(UserWidgets widget : userWidgets)
	{
		if(widget.name.Equals(name, ESearchCase::IgnoreCase))
		{
			//return Cast<UUserWidget>(StaticLoadObject(UUserWidget::StaticClass(), NULL, *widget.userWidgetPath));
		}
	}
	return nullptr;
}
