#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlockDecorator.h"
#include "RichTextBlockButtonDecorator.generated.h"

/**
 * @author Dego1n
 */
UCLASS(Abstract)
class MMOUNREALCLIENT_API URichTextBlockButtonDecorator : public URichTextBlockDecorator
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = Appearance)
	FSlateBrush Brush;

	URichTextBlockButtonDecorator(const FObjectInitializer& ObjectInitializer);

	virtual TSharedPtr<ITextDecorator> CreateDecorator(URichTextBlock* InOwner) override;
};
