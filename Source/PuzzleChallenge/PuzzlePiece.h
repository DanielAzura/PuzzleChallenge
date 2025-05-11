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

UENUM()
enum class EPuzzlePieceSide
{
    Top,
    Bottom,
    Left,
    Right
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

    bool canBeUsedTwice = false;
    int timesUsed = 0;
    int index;

    int numRotations = 0;

    //TMap<EPuzzlePieceSide, EPuzzleSideType> 
    EPuzzleSideType Top;
    EPuzzleSideType Bottom;
    EPuzzleSideType Left;
    EPuzzleSideType Right;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "Components")
    class UBoxComponent* BoxComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess), Category = "Components")
    class UPaperSpriteComponent* SpriteComp;

};
