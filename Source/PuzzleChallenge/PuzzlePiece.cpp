// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePiece.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values
APuzzlePiece::APuzzlePiece():
	BoxComp(nullptr),
	SpriteComp(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComp = CreateDefaultSubobject<UBoxComponent>("PuzzlePieceBoxComp");
	BoxComp->SetCollisionProfileName("NoCollision");
	BoxComp->SetSimulatePhysics(false);
	RootComponent = BoxComp;

	SpriteComp = CreateDefaultSubobject<UPaperSpriteComponent>("PuzzlePieceSpriteComp");
	SpriteComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APuzzlePiece::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzlePiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

