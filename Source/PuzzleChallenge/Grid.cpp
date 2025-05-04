// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"
#include "PuzzlePiece.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

// Sets default values
AGrid::AGrid()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    //puzzlePiece = CreateDefaultSubobject<APuzzlePiece>("PuzzlePiece");
    //AddOwnedComponent(Cast<UActorComponent>(puzzlePiece));

}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
    Super::BeginPlay();

    TSubclassOf<class APuzzlePiece> PuzzleClass;
    PuzzleClass = APuzzlePiece::StaticClass();

    FVector SpawnLoc = GetActorLocation();

    FActorSpawnParameters spawnParameters;
    spawnParameters.Instigator = GetInstigator();
    spawnParameters.Owner = this;

    for (int i = 0; i < 16; i++)
    {
        puzzlePieces.Add(GetWorld()->SpawnActor<APuzzlePiece>(SpawnLoc, GetActorRotation(), spawnParameters));
        puzzlePieces[i]->index = i;
        puzzlePieces[i]->SpriteComp->SetSprite(PuzzleSprites[i]);
    }

    Reset();

    OrderPieces();

    for (int i = 0; i < 16; i++)
    {

        if (i % 4 == 0 && i != 0)
        {
            SpawnLoc.X = GetActorLocation().X;
            SpawnLoc.Z -= 250;
        }

        SpawnLoc.X += 250;

        //int index = OrderOfPieces[i];
        //swap the i for index;
        puzzlePieces[i]->SetActorLocation(SpawnLoc);
    }
}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AGrid::Reset()
{
    NumPiecesRemoved = 0;

    OrderOfPieces.clear();

    InwardArrow.clear();
    OutwardArrow.clear();
    InwardInvertedArrow.clear();
    OutwardInvertedArrow.clear();
    Cross.clear();
    InvertedCross.clear();
    Octagon.clear();
    InvertedOctagon.clear();

    //Piece 1
    puzzlePieces[0]->Top = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[0]);
    puzzlePieces[0]->Bottom = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[0]);
    puzzlePieces[0]->Left = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[0]);
    puzzlePieces[0]->Right = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[0]);

    //Piece 2
    puzzlePieces[1]->Top = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[1]);
    puzzlePieces[1]->Bottom = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[1]);
    puzzlePieces[1]->Left = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[1]);
    puzzlePieces[1]->Right = EPuzzleSideType::Octagon;
    Cross.push_back(puzzlePieces[1]);

    //Piece 3
    puzzlePieces[2]->Top = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[2]);
    puzzlePieces[2]->Bottom = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[2]);
    puzzlePieces[2]->Left = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[2]);
    puzzlePieces[2]->Right = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[2]);

    //Piece 4
    puzzlePieces[3]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[3]);
    puzzlePieces[3]->Bottom = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[3]);
    puzzlePieces[3]->Left = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[3]);
    puzzlePieces[3]->Right = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[3]);

    //Piece 5
    puzzlePieces[4]->Top = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[4]);
    puzzlePieces[4]->Bottom = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[4]);
    puzzlePieces[4]->Left = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[4]);
    puzzlePieces[4]->Right = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[4]);

    //Piece 6
    puzzlePieces[5]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[5]);
    puzzlePieces[5]->Bottom = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[5]);
    puzzlePieces[5]->Left = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[5]);
    puzzlePieces[5]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[5]);

    //Piece 7
    puzzlePieces[6]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[6]);
    puzzlePieces[6]->Bottom = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[6]);
    puzzlePieces[6]->Left = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[6]);
    puzzlePieces[6]->Right = EPuzzleSideType::OutwardArrow;
    InwardArrow.push_back(puzzlePieces[6]);
    puzzlePieces[6]->canBeUsedTwice = true;
    puzzlePieces[6]->timesUsed = 0;


    //Piece 8
    puzzlePieces[7]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[7]);
    puzzlePieces[7]->Bottom = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[7]);
    puzzlePieces[7]->Left = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[7]);
    puzzlePieces[7]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[7]);

    //Piece 9
    puzzlePieces[8]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[8]);
    puzzlePieces[8]->Bottom = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[8]);
    puzzlePieces[8]->Left = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[8]);
    puzzlePieces[8]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[8]);
    puzzlePieces[8]->canBeUsedTwice = true;
    puzzlePieces[8]->timesUsed = 0;

    //Piece 10
    puzzlePieces[9]->Top = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[9]);
    puzzlePieces[9]->Bottom = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[9]);
    puzzlePieces[9]->Left = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[9]);
    puzzlePieces[9]->Right = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[9]);
    puzzlePieces[9]->canBeUsedTwice = true;
    puzzlePieces[9]->timesUsed = 0;


    //Piece 11
    puzzlePieces[10]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[10]);
    puzzlePieces[10]->Bottom = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[10]);
    puzzlePieces[10]->Left = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[10]);
    puzzlePieces[10]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[10]);

    //Piece 12
    puzzlePieces[11]->Top = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[11]);
    puzzlePieces[11]->Bottom = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[11]);
    puzzlePieces[11]->Left = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[11]);
    puzzlePieces[11]->Right = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[11]);

    //Piece 13
    puzzlePieces[12]->Top = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[12]);
    puzzlePieces[12]->Bottom = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[12]);
    puzzlePieces[12]->Left = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[12]);
    puzzlePieces[12]->Right = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[12]);
    puzzlePieces[12]->canBeUsedTwice = true;
    puzzlePieces[12]->timesUsed = 0;

    //Piece 14
    puzzlePieces[13]->Top = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[13]);
    puzzlePieces[13]->Bottom = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[13]);
    puzzlePieces[13]->Left = EPuzzleSideType::OutwardInvertedArrow;
    OutwardInvertedArrow.push_back(puzzlePieces[13]);
    puzzlePieces[13]->Right = EPuzzleSideType::OutwardArrow;
    OutwardArrow.push_back(puzzlePieces[13]);

    //Piece 15
    puzzlePieces[14]->Top = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[14]);
    puzzlePieces[14]->Bottom = EPuzzleSideType::Cross;
    Cross.push_back(puzzlePieces[14]);
    puzzlePieces[14]->Left = EPuzzleSideType::InwardInvertedArrow;
    InwardInvertedArrow.push_back(puzzlePieces[14]);
    puzzlePieces[14]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[14]);
    puzzlePieces[14]->canBeUsedTwice = true;
    puzzlePieces[14]->timesUsed = 0;

    //Piece 16
    puzzlePieces[15]->Top = EPuzzleSideType::InwardArrow;
    InwardArrow.push_back(puzzlePieces[15]);
    puzzlePieces[15]->Bottom = EPuzzleSideType::InvertedCross;
    InvertedCross.push_back(puzzlePieces[15]);
    puzzlePieces[15]->Left = EPuzzleSideType::InvertedOctagon;
    InvertedOctagon.push_back(puzzlePieces[15]);
    puzzlePieces[15]->Right = EPuzzleSideType::Octagon;
    Octagon.push_back(puzzlePieces[15]);
}

void AGrid::Rotate(APuzzlePiece* puzzlePiece, int iterations)
{
    //Rotations are always clockwise
    FRotator rotation = puzzlePiece->GetActorRotation();
    for (int i = 0; i < iterations; i++)
    {
        EPuzzleSideType temp = puzzlePiece->Top;

        puzzlePiece->Top = puzzlePiece->Left;
        puzzlePiece->Left = puzzlePiece->Bottom;
        puzzlePiece->Bottom = puzzlePiece->Right;
        puzzlePiece->Right = temp;

        rotation.Pitch -= 90;
    }
    puzzlePiece->SetActorRotation(rotation);
}

//TODO IMPLEMENT ROTATE LOGIC

APuzzlePiece* AGrid::FindNextPiece(APuzzlePiece* currentPiece)
{
    if (NumPiecesRemoved < 4)
    {
        EPuzzleSideType neededPiece = currentPiece->Right;

        //Adding self to pieces tried to not go over self
        if (!PiecesTriedWithThisPiece.Contains(currentPiece->index))
        {
            std::vector<int> triedPieces;
            triedPieces.push_back(currentPiece->index);
            PiecesTriedWithThisPiece.Add(currentPiece->index, triedPieces);
        }

        if (neededPiece == EPuzzleSideType::InwardArrow)
        {
            APuzzlePiece* suitablePiece = FindSuitablePiece(currentPiece, InwardInvertedArrow, EPuzzleSideType::InwardInvertedArrow);
            if (suitablePiece != nullptr)
            {
                return suitablePiece;
            }
            else
                return nullptr;
        }
        if (neededPiece == EPuzzleSideType::OutwardArrow)
        {
            APuzzlePiece* suitablePiece = FindSuitablePiece(currentPiece, OutwardInvertedArrow, EPuzzleSideType::OutwardInvertedArrow);
            if (suitablePiece != nullptr)
            {
                return suitablePiece;
            }
            else
                return nullptr;
        }
        if (neededPiece == EPuzzleSideType::InwardInvertedArrow)
        {
            int size = InwardArrow.size();
            APuzzlePiece* suitablePiece = FindSuitablePiece(currentPiece, InwardArrow, EPuzzleSideType::InwardArrow);
            if (suitablePiece != nullptr)
            {
                return suitablePiece;
            }
            else
                return nullptr;
        }
        if (neededPiece == EPuzzleSideType::OutwardInvertedArrow)
        {
            int size = OutwardArrow.size();
            APuzzlePiece* suitablePiece = FindSuitablePiece(currentPiece, OutwardArrow, EPuzzleSideType::OutwardArrow);
            if (suitablePiece != nullptr)
            {
                return suitablePiece;
            }
            else
                return nullptr;
        }
        if (neededPiece == EPuzzleSideType::Cross)
        {
            int size = InvertedCross.size();
            APuzzlePiece* suitablePiece = FindSuitablePiece(currentPiece, InvertedCross, EPuzzleSideType::InvertedCross);
            if (suitablePiece != nullptr)
            {
                return suitablePiece;
            }
            else
                return nullptr;
        }
        if (neededPiece == EPuzzleSideType::InvertedCross)
        {
            int size = Cross.size();
            APuzzlePiece* suitablePiece = FindSuitablePiece(currentPiece, Cross, EPuzzleSideType::Cross);
            if (suitablePiece != nullptr)
            {
                return suitablePiece;
            }
            else
                return nullptr;
        }
        if (neededPiece == EPuzzleSideType::Octagon)
        {
            int size = InvertedOctagon.size();
            APuzzlePiece* suitablePiece = FindSuitablePiece(currentPiece, InvertedOctagon, EPuzzleSideType::InvertedOctagon);
            if (suitablePiece != nullptr)
            {
                return suitablePiece;
            }
            else
                return nullptr;
        }
        if (neededPiece == EPuzzleSideType::InvertedOctagon)
        {
            int size = Octagon.size();
            APuzzlePiece* suitablePiece = FindSuitablePiece(currentPiece, Octagon, EPuzzleSideType::Octagon);
            if (suitablePiece != nullptr)
            {
                return suitablePiece;
            }
            else
                return nullptr;
        }
    }
    return nullptr;
}

void AGrid::OrderPieces()
{
    APuzzlePiece* startingPiece = puzzlePieces[FMath::RandRange(0, puzzlePieces.Num() - 1)];
    OrderOfPieces.push_back(startingPiece->index);

    APuzzlePiece* checkPiece = startingPiece;
    APuzzlePiece* nextPiece = nullptr;
    APuzzlePiece* storedLastPiece = nullptr;
    do
    {
        if (NumPiecesRemoved == 4) //4 For now to test the first row
            break;

        nextPiece = FindNextPiece(checkPiece);

        if (nextPiece)
        {
            OrderOfPieces.push_back(nextPiece->index);
            //Store the last piece to check it later
            storedLastPiece = checkPiece;
            //Set the next piece as the piece to check
            checkPiece = nextPiece;
        }
        else
        {
            //Reset the pieces checked with this one
            if (NumPiecesRemoved != 0)
                NumPiecesRemoved -= 1;
            PiecesTriedWithThisPiece[OrderOfPieces.back()].empty();
            //if (OrderOfPieces > 1)?
            OrderOfPieces.pop_back();
            //Set the check piece to the last piece
            //Change the next piece to something else if fail
            checkPiece = puzzlePieces[OrderOfPieces.back()];
            nextPiece = nullptr;
        }
    } while (NumPiecesRemoved != 16);
}

APuzzlePiece* AGrid::FindSuitablePiece(APuzzlePiece* currentPiece, std::vector<APuzzlePiece*> vectorOfPieces, EPuzzleSideType SidePiece, EPuzzleSideType TopPiece)
{
    for (int i = 0; i < vectorOfPieces.size(); i++)
    {
        //Checking if vector has tried the piece before
        if (std::find(PiecesTriedWithThisPiece[currentPiece->index].begin(),
            PiecesTriedWithThisPiece[currentPiece->index].end(),
            vectorOfPieces[i]->index) != PiecesTriedWithThisPiece[currentPiece->index].end())
        {
            continue;
        }
        else
        {
            NumPiecesRemoved += 1;

            APuzzlePiece* returnedPiece = vectorOfPieces[i];

            if (!returnedPiece->canBeUsedTwice)
            {
                PiecesTriedWithThisPiece[currentPiece->index].push_back(vectorOfPieces[i]->index);

                auto it = std::find(vectorOfPieces.begin(), vectorOfPieces.end(), vectorOfPieces[i]);
                vectorOfPieces.erase(it);
            }
            else
            {
                // TODO find a way to check which side piece was used and rotate and use the other one
                //You could use the first one needed and then if it was used before, dont take the first available one, rotate it


                if (returnedPiece->timesUsed < 1)
                    returnedPiece->timesUsed++;
                else
                {
                    PiecesTriedWithThisPiece[currentPiece->index].push_back(vectorOfPieces[i]->index);

                    auto it = std::find(vectorOfPieces.begin(), vectorOfPieces.end(), vectorOfPieces[i]);
                    vectorOfPieces.erase(it);
                }
            }

            return returnedPiece;
        }
    }
    return nullptr;
}

