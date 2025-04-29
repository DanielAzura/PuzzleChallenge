// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzlePiece.h"
#include "Grid.generated.h"


class UPaperSpriteComponent;

UCLASS()
class PUZZLECHALLENGE_API AGrid : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AGrid();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    void Reset();

private:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "Components")
    TArray<class APuzzlePiece*> puzzlePieces;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "Components")
    TArray<class UPaperSprite*> PuzzleSprites;

    std::vector<EPuzzleSideType> InwardArrow;
    std::vector<EPuzzleSideType> OutwardArrow;
    std::vector<EPuzzleSideType> InwardInvertedArrow;
    std::vector<EPuzzleSideType> OutwardInvertedArrow;
    std::vector<EPuzzleSideType> Cross;
    std::vector<EPuzzleSideType> InvertedCross;
    std::vector<EPuzzleSideType> Octagon;
    std::vector<EPuzzleSideType> InvertedOctagon;



};
