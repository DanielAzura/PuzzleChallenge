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
    //SpawnLoc.X -= 2;
    //SpawnLoc.Z += 2;

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

