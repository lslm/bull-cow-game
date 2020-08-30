// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
using namespace std;

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{   
    if (IsAnswerCorrect(Input)) {
        ClearScreen();
        PrintLine(TEXT("Parabéns! Você encontrou o hamster escondido!"));

        HiddenWord = GetRandomHiddenWord();
        PrintLine(TEXT("Outro hamster agora"));
        PrintLine(TEXT("Qual é o hamster escondido?"));
    } else {
        RemainingAttempts--;
        ClearScreen();

        if (RemainingAttempts > 0) {
            PrintLine(TEXT("Tente novamente! Qual é o Hamster escondido?"));
        } else {
            PrintLine(TEXT("Você falhou..."));  
        }
    }
}

void UBullCowCartridge::InitGame() {
    HamsterNames = {
        TEXT("Aloy"),
        TEXT("Ritinha"),
        TEXT("Stela"),
        TEXT("Bart"),
        TEXT("X"),
        TEXT("Billie")
    };

    HiddenWord = GetRandomHiddenWord();
    RemainingAttempts = 5;

    PrintLine(TEXT("Welcome to Bull Cow"));
    PrintLine(TEXT("Qual é o hamster escondido?"));
}

FString UBullCowCartridge::GetRandomHiddenWord() {
    int32 randomIndex = FMath::RandRange(0, (HamsterNames.Num() - 1));
    return HamsterNames[randomIndex];
}

bool UBullCowCartridge::IsAnswerCorrect(const FString& Answer) {
    return Answer.Equals(HiddenWord, ESearchCase::IgnoreCase);
}
