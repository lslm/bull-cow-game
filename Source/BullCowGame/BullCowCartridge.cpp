// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
using namespace std;

FString HiddenWord;

TArray<FString> HamsterNames = {
    TEXT("Aloy"),
    TEXT("Ritinha"),
    TEXT("Stela"),
    TEXT("Bart"),
    TEXT("X"),
    TEXT("Billie")
};

FString UBullCowCartridge::GetRandomHiddenWord() {
    int32 randomIndex = FMath::RandRange(0, (HamsterNames.Num() - 1));
    return HamsterNames[randomIndex];
}

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    HiddenWord = GetRandomHiddenWord();

    PrintLine(TEXT("Welcome to Bull Cow"));
    PrintLine(TEXT("Qual é o hamster escondido?"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{   
    if (HiddenWord.Equals(Input, ESearchCase::IgnoreCase)) {
        ClearScreen();
        PrintLine(TEXT("Parabéns! Você encontrou o hamster escondido!"));

        HiddenWord = GetRandomHiddenWord();
        PrintLine(TEXT("Vamos tentar novamente..."));
        PrintLine(TEXT("Qual é o hamster escondido?"));
    } else {
        ClearScreen();
        PrintLine(TEXT("Tente novamente! Qual é o Hamster escondido?"));
    }
}
