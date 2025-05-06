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

    void Rotate(APuzzlePiece* puzzlePiece, int iterations);

    void OrderPieces();

    APuzzlePiece* FindNextPiece(APuzzlePiece* currentPiece);
    
    APuzzlePiece* FindSuitablePiece(APuzzlePiece* currentPiece, std::vector<APuzzlePiece*> vectorOfPieces, EPuzzleSideType SidePiece, EPuzzleSideType TopPiece = EPuzzleSideType::None);

    APuzzlePiece* SelectNeededVector(APuzzlePiece* currentPiece, APuzzlePiece* neededPiece, EPuzzlePieceSide side);
private:

    int NumPiecesRemoved = 0;
    std::vector<int> OrderOfPieces;

    TMap<int, std::vector<int>> PiecesTriedWithThisPiece;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "Components")
    TArray<class APuzzlePiece*> puzzlePieces;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "Components")
    TArray<class UPaperSprite*> PuzzleSprites;



    std::vector<APuzzlePiece*> InwardArrow;
    std::vector<APuzzlePiece*> OutwardArrow;
    std::vector<APuzzlePiece*> InwardInvertedArrow;
    std::vector<APuzzlePiece*> OutwardInvertedArrow;
    std::vector<APuzzlePiece*> Cross;
    std::vector<APuzzlePiece*> InvertedCross;
    std::vector<APuzzlePiece*> Octagon;
    std::vector<APuzzlePiece*> InvertedOctagon;
};
