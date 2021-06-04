#include "RichTextBlockButtonDecorator.h"

#include "Widgets/Layout/SScaleBox.h"
#include "Fonts/FontMeasure.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SScaleBox.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Input/SButton.h"

#include "Network/Game/Thread/GameSocketThread.h"

#define LOCTEXT_NAMESPACE "UMG"

/**
 * @author Dego1n
 */
class SRichButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRichButton){}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, FText buttonText, TMap<FString,FString> metadata, TOptional<int32> Width = 1000, TOptional<int32> Height = 40)
	{
		FString* type = metadata.Find("type");
		if(type->Equals("npc_dialog"))
		{
			FString* objectId = metadata.Find("object_id");
			FString* ref = metadata.Find("ref");

			ChildSlot
			[
				SNew(SBox)
				.WidthOverride(Width.GetValue())
				.HeightOverride(Height.GetValue())
				[
					SNew(SScaleBox)
					.Stretch(EStretch::Fill)
					[
						SNew(SButton)
						.OnClicked(this, &SRichButton::OnChatDialogClicked, *objectId, *ref)
						.HAlign(HAlign_Fill)
						.Text(buttonText)
						.VAlign(VAlign_Center)
					]
				]
			];
		}
		else if (type->Equals("quest"))
		{
			FString* objectId = metadata.Find("object_id");
			FString* ref = metadata.Find("ref");
			FString* questId = metadata.Find("quest_id");

			ChildSlot
				[
					SNew(SBox)
					.WidthOverride(Width.GetValue())
				.HeightOverride(Height.GetValue())
				[
					SNew(SScaleBox)
					.Stretch(EStretch::Fill)
				[
					SNew(SButton)
					.OnClicked(this, &SRichButton::OnQuestTalk, *objectId, *questId, *ref)
				.HAlign(HAlign_Fill)
				.Text(buttonText)
				.VAlign(VAlign_Center)
				]
				]
				];
		}
	}
	void onRichButtonClick(TMap<FString,FString> metadata)
	{

	}

	FReply OnChatDialogClicked(FString objectId, FString ref)
	{
		GameSocketThread::Runnable->character->GetDialog(FCString::Atoi(*objectId),*ref);
		return FReply::Handled();
	}
	
	FReply OnQuestTalk(FString objectId, FString questId, FString ref)
	{
		GameSocketThread::Runnable->character->OnQuestTalk(FCString::Atoi(*objectId), FCString::Atoi(*questId), *ref);
		return FReply::Handled();
	}
};

class FRichButton : public FRichTextDecorator{
public:
	FRichButton(URichTextBlock* InOwner, URichTextBlockButtonDecorator* InDecorator)
		: FRichTextDecorator(InOwner)
		, Decorator(InDecorator)
	{
	}

	virtual bool Supports(const FTextRunParseResults& RunParseResult, const FString& Text) const override
	{
		return RunParseResult.Name == TEXT("button");
	}

protected:
	virtual TSharedPtr<SWidget> CreateDecoratorWidget(const FTextRunInfo& RunInfo, const FTextBlockStyle& TextStyle) const override
	{
		return SNew(SRichButton, RunInfo.Content, RunInfo.MetaData);
	}

private:
	URichTextBlockButtonDecorator* Decorator;
};

URichTextBlockButtonDecorator::URichTextBlockButtonDecorator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


TSharedPtr<ITextDecorator> URichTextBlockButtonDecorator::CreateDecorator(URichTextBlock* InOwner)
{
	return MakeShareable(new FRichButton(InOwner, this));
}

#undef LOCTEXT_NAMESPACE