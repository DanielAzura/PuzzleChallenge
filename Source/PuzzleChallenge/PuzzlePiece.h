// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzlePiece.generated.h"

UENUM()
enum class EPuzzleSideType
{
    InwardArrow,
    OutwardArrow,
    InwardInvertedArrow,
    OutwardInvertedArrow,
    Cross,
    InvertedCross,
    Octagon,
    InvertedOctagon,
    None,
};

UCLASS()
class PUZZLECHALLENGE_API APuzzlePiece : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APuzzlePiece();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Some pieces can be used twice, this sets the pieces to be able to be used twice
    bool canBeUsedTwice = false;
    // For pieces that can be used twice, this checks how many times its been used
    int timesUsed = 0;
    // Index of the piece
    int index;
    // Number of times that the piece has been rotated
    int numRotations = 0;

    EPuzzleSideType Top;
    EPuzzleSideType Bottom;
    EPuzzleSideType Left;
    EPuzzleSideType Right;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "Components")
    class UBoxComponent* BoxComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "Components")
    class UPaperSpriteComponent* SpriteComp;

};
