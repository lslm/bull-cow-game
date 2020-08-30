// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	virtual FString GetRandomHiddenWord();
	virtual bool IsAnswerCorrect(const FString& Answer);
	virtual void InitGame();

	// Your declarations go below!
	private:
	FString HiddenWord;
	TArray<FString> HamsterNames;
	int32 RemainingAttempts;
};
