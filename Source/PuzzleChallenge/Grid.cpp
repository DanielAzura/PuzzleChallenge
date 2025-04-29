// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"
#include "PuzzlePiece.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

// Sets default values
AGrid::AGrid()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //puzzlePiece = CreateDefaultSubobject<APuzzlePiece>("PuzzlePiece");
    //AddOwnedComponent(Cast<UActorComponent>(puzzlePiece));



}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
    Super::BeginPlay();

    FActorSpawnParameters spawnParameters;
    spawnParameters.Instigator = GetInstigator();
    spawnParameters.Owner = this;

    TSubclassOf<class APuzzlePiece> PuzzleClass;
    PuzzleClass = APuzzlePiece::StaticClass();

    FVector SpawnLoc = GetActorLocation();

    for (int i = 0; i < 16; i++)
    {
        puzzlePieces.Add(GetWorld()->SpawnActor<APuzzlePiece>(SpawnLoc, GetActorRotation(), spawnParameters));
        puzzlePieces[i]->SpriteComp->SetSprite(PuzzleSprites[i]);
    }

    Reset();

    for (int i = 0; i < 16; i++)
    {
        if (i % 4 == 0 && i != 0)
        {
            SpawnLoc.X = GetActorLocation().X;
            SpawnLoc.Z -= 250;
        }

        SpawnLoc.X -= 250;

        puzzlePieces.Add(GetWorld()->SpawnActor<APuzzlePiece>(SpawnLoc, GetActorRotation(), spawnParameters));
        puzzlePieces[i]->SpriteComp->SetSprite(PuzzleSprites[i]);

    }


}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AGrid::Reset()
{
    //Piece 1
    puzzlePieces[0]->Top = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[0]->Right);

    //Piece 2
    puzzlePieces[0]->Top = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::Octagon;
    Cross.push_back(puzzlePieces[0]->Right);

    //Piece 3
    puzzlePieces[0]->Top = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[0]->Right);

    //Piece 4
    puzzlePieces[0]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[0]->Right);

    //Piece 5
    puzzlePieces[0]->Top = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]->Right);

    //Piece 6
    puzzlePieces[0]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[0]->Right);

    //Piece 7
    puzzlePieces[0]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]->Right);

    //Piece 8
    puzzlePieces[0]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[0]->Right);

    //Piece 9
    puzzlePieces[0]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[0]->Right);

    //Piece 10
    puzzlePieces[0]->Top = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]->Right);

    //Piece 11
    puzzlePieces[0]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[0]->Right);

    //Piece 12
    puzzlePieces[0]->Top = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[0]->Right);

    //Piece 13
    puzzlePieces[0]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]->Right);

    //Piece 14
    puzzlePieces[0]->Top = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[0]->Right);

    //Piece 15
    puzzlePieces[0]->Top = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[0]->Right);

    //Piece 16
    puzzlePieces[0]->Top = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]->Top);
    puzzlePieces[0]->Bottom = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[0]->Bottom);
    puzzlePieces[0]->Left = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[0]->Left);
    puzzlePieces[0]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[0]->Right);
}

