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

        if (i < 7)
        {
            int index = OrderOfPieces[i];
            //swap the i for index;
            puzzlePieces[index]->SetActorLocation(SpawnLoc);
        }
    }
    int foo = 0;
}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //TODO add the puzzlepieces order of pieces and see why no work

    for (int i = 0; i < OrderOfPieces.size(); i++)
    {
        if (i > 4)
        {
            auto Top =puzzlePieces[OrderOfPieces[i]]->Top;
            auto bottom = puzzlePieces[OrderOfPieces[i]]->Bottom;
            auto left = puzzlePieces[OrderOfPieces[i]]->Left;
            auto right = puzzlePieces[OrderOfPieces[i]]->Right;
            int slay =5;

            //It works but rotate no work

        }
    }


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
    Octagon.push_back(puzzlePieces[1]);

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
    OutwardArrow.push_back(puzzlePieces[6]);
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
    }
}

void AGrid::OrderPieces()
{
    APuzzlePiece* startingPiece = puzzlePieces[FMath::RandRange(0, puzzlePieces.Num() - 1)];
    //APuzzlePiece* startingPiece = puzzlePieces[5];
    OrderOfPieces.push_back(startingPiece->index);

    APuzzlePiece* checkPiece = startingPiece;
    APuzzlePiece* nextPiece = nullptr;
    APuzzlePiece* storedLastPiece = nullptr;
    do
    {
        if (OrderOfPieces.size() == 7) //Set to 8 to test next row
            break;

        if (OrderOfPieces.size() == 6)
            int fo = 9;

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
            int indexBack = OrderOfPieces.back();

            if (PiecesTriedWithThisPiece.Contains(indexBack))
                PiecesTriedWithThisPiece[indexBack].clear();

            //Readd to pool
            ReAddToPool(puzzlePieces[indexBack]);

            if (OrderOfPieces.size() > 1)
                OrderOfPieces.pop_back();
            else if (OrderOfPieces.size() == 1)
            {
                int pieceIndex = OrderOfPieces.at(0);
                OrderOfPieces.pop_back();
                if (pieceIndex == 15)
                    pieceIndex = 0;
                else
                    pieceIndex++;
                OrderOfPieces.push_back(puzzlePieces[pieceIndex]->index);

                PiecesTriedWithThisPiece.Empty();

            }

            indexBack = OrderOfPieces.back();

            //Set the check piece to the last piece
            //Change the next piece to something else if fail

            checkPiece = puzzlePieces[OrderOfPieces.back()];
            nextPiece = nullptr;
        }
    } while (NumPiecesRemoved != 16);
}

void AGrid::ReAddToPool(APuzzlePiece* puzzlePiece)
{
    if (puzzlePiece->Top == EPuzzleSideType::InwardArrow ||
        puzzlePiece->Bottom == EPuzzleSideType::InwardArrow ||
        puzzlePiece->Left == EPuzzleSideType::InwardArrow ||
        puzzlePiece->Right == EPuzzleSideType::InwardArrow)
    {
        if (std::find(InwardArrow.begin(), InwardArrow.end(), puzzlePiece) != InwardArrow.end())
        {
            //Do nothing if its already in the vector
        }
        else
            InwardArrow.push_back(puzzlePiece);

    }
    if (puzzlePiece->Top == EPuzzleSideType::OutwardArrow ||
        puzzlePiece->Bottom == EPuzzleSideType::OutwardArrow ||
        puzzlePiece->Left == EPuzzleSideType::OutwardArrow ||
        puzzlePiece->Right == EPuzzleSideType::OutwardArrow)
    {
        if (std::find(OutwardArrow.begin(), OutwardArrow.end(), puzzlePiece) != OutwardArrow.end())
        {
            //Do nothing if its already in the vector
        }
        else
            OutwardArrow.push_back(puzzlePiece);
    }
    if (puzzlePiece->Top == EPuzzleSideType::InwardInvertedArrow ||
        puzzlePiece->Bottom == EPuzzleSideType::InwardInvertedArrow ||
        puzzlePiece->Left == EPuzzleSideType::InwardInvertedArrow ||
        puzzlePiece->Right == EPuzzleSideType::InwardInvertedArrow)
    {
        if (std::find(InwardInvertedArrow.begin(), InwardInvertedArrow.end(), puzzlePiece) != InwardInvertedArrow.end())
        {
            //Do nothing if its already in the vector
        }
        else
            InwardInvertedArrow.push_back(puzzlePiece);
    }
    if (puzzlePiece->Top == EPuzzleSideType::OutwardInvertedArrow ||
        puzzlePiece->Bottom == EPuzzleSideType::OutwardInvertedArrow ||
        puzzlePiece->Left == EPuzzleSideType::OutwardInvertedArrow ||
        puzzlePiece->Right == EPuzzleSideType::OutwardInvertedArrow)
    {
        if (std::find(OutwardInvertedArrow.begin(), OutwardInvertedArrow.end(), puzzlePiece) != OutwardInvertedArrow.end())
        {
            //Do nothing if its already in the vector
        }
        else
            OutwardInvertedArrow.push_back(puzzlePiece);
    }
    if (puzzlePiece->Top == EPuzzleSideType::Cross ||
        puzzlePiece->Bottom == EPuzzleSideType::Cross ||
        puzzlePiece->Left == EPuzzleSideType::Cross ||
        puzzlePiece->Right == EPuzzleSideType::Cross)
    {
        if (std::find(Cross.begin(), Cross.end(), puzzlePiece) != Cross.end())
        {
            //Do nothing if its already in the vector
        }
        else
            Cross.push_back(puzzlePiece);
    }
    if (puzzlePiece->Top == EPuzzleSideType::InvertedCross ||
        puzzlePiece->Bottom == EPuzzleSideType::InvertedCross ||
        puzzlePiece->Left == EPuzzleSideType::InvertedCross ||
        puzzlePiece->Right == EPuzzleSideType::InvertedCross)
    {
        if (std::find(InvertedCross.begin(), InvertedCross.end(), puzzlePiece) != InvertedCross.end())
        {
            //Do nothing if its already in the vector
        }
        else
            InvertedCross.push_back(puzzlePiece);
    }
    if (puzzlePiece->Top == EPuzzleSideType::Octagon ||
        puzzlePiece->Bottom == EPuzzleSideType::Octagon ||
        puzzlePiece->Left == EPuzzleSideType::Octagon ||
        puzzlePiece->Right == EPuzzleSideType::Octagon)
    {
        if (std::find(Octagon.begin(), Octagon.end(), puzzlePiece) != Octagon.end())
        {
            //Do nothing if its already in the vector
        }
        else
            Octagon.push_back(puzzlePiece);
    }
    if (puzzlePiece->Top == EPuzzleSideType::InvertedOctagon ||
        puzzlePiece->Bottom == EPuzzleSideType::InvertedOctagon ||
        puzzlePiece->Left == EPuzzleSideType::InvertedOctagon ||
        puzzlePiece->Right == EPuzzleSideType::InvertedOctagon)
    {
        if (std::find(InvertedOctagon.begin(), InvertedOctagon.end(), puzzlePiece) != InvertedOctagon.end())
        {
            //Do nothing if its already in the vector
        }
        else
            InvertedOctagon.push_back(puzzlePiece);
    }
}

APuzzlePiece* AGrid::FindNextPiece(APuzzlePiece* currentPiece)
{
    if (!PiecesTriedWithThisPiece.Contains(currentPiece->index))
    {
        std::vector<int> triedPieces;
        triedPieces.push_back(currentPiece->index);
        PiecesTriedWithThisPiece.Add(currentPiece->index, triedPieces);
    }

    EPuzzleSideType neededSidePiece = currentPiece->Right;
    EPuzzleSideType neededTopPiece = EPuzzleSideType::None;

    if (OrderOfPieces.size() >= 4)
    {
        int abovePieceIndex = OrderOfPieces.size() - 4;
        //Get the piece above this pieces's bottom
        neededTopPiece = puzzlePieces[OrderOfPieces[abovePieceIndex]]->Bottom;
    }

    if (OrderOfPieces.size() % 4 == 0)
    {
        neededSidePiece = EPuzzleSideType::None;
    }
    //These are the same???
    if (OrderOfPieces.size() < 4)
    {
        neededTopPiece = EPuzzleSideType::None;

        APuzzlePiece* suitablePiece = FindSuitablePiece(currentPiece, neededSidePiece, neededTopPiece);
        if (suitablePiece != nullptr)
            return suitablePiece;
        else
            return nullptr;
    }
    else if (OrderOfPieces.size() < 8)
    {
        APuzzlePiece* suitablePiece = FindSuitablePiece(currentPiece, neededSidePiece, neededTopPiece);
        if (suitablePiece != nullptr)
            return suitablePiece;
        else
            return nullptr;

    }
    return nullptr;
}

bool AGrid::isPieceViable(APuzzlePiece* puzzlePiece, EPuzzleSideType SidePiece, EPuzzleSideType TopPiece)
{
    if (puzzlePiece->Top == TopPiece && puzzlePiece->Left == SidePiece ||
        puzzlePiece->Right == TopPiece && puzzlePiece->Top == SidePiece ||
        puzzlePiece->Bottom == TopPiece && puzzlePiece->Right == SidePiece ||
        puzzlePiece->Left == TopPiece && puzzlePiece->Bottom == SidePiece)
        return true;

    return false;
}

APuzzlePiece* AGrid::FindSuitablePiece(APuzzlePiece* currentPiece, EPuzzleSideType SidePiece, EPuzzleSideType TopPiece)
{
    std::vector<APuzzlePiece*> SideVector = SelectNeededVector(SidePiece);
    std::vector<APuzzlePiece*> TopVector = SelectNeededVector(TopPiece);

    EPuzzleSideType neededSidePiece = SelectNeededSideType(SidePiece);
    EPuzzleSideType neededTopPiece = SelectNeededSideType(TopPiece);

    //TODO check in here where the bug is probably to do with the rotate while loop (not the <4 one)

    if (TopPiece != EPuzzleSideType::None && SidePiece != EPuzzleSideType::None)
    {
        for (int i = 0; i < SideVector.size(); i++)
        {
            if (std::find(PiecesTriedWithThisPiece[currentPiece->index].begin(),
                PiecesTriedWithThisPiece[currentPiece->index].end(),
                SideVector[i]->index) != PiecesTriedWithThisPiece[currentPiece->index].end() ||
                std::find(OrderOfPieces.begin(),
                    OrderOfPieces.end(),
                    SideVector[i]->index) != OrderOfPieces.end())
            {
                continue;
            }

            if (isPieceViable(SideVector[i], neededSidePiece, neededTopPiece))
            {
                APuzzlePiece* returnedPiece = SideVector[i];
                int iterations = 0;

                if (returnedPiece->canBeUsedTwice)
                    int fp = 0;

                PiecesTriedWithThisPiece[currentPiece->index].push_back(SideVector[i]->index);

                if (std::find(TopVector.begin(), TopVector.end(), SideVector[i]) != TopVector.end())
                {
                    auto it = std::find(TopVector.begin(), TopVector.end(), SideVector[i]);
                    TopVector.erase(it);
                }

                if (std::find(SideVector.begin(), SideVector.end(), SideVector[i]) != SideVector.end())
                {
                    auto it2 = std::find(SideVector.begin(), SideVector.end(), SideVector[i]);
                    SideVector.erase(it2);
                }
                while (1)
                {
                    Rotate(returnedPiece, 1);
                    iterations++;

                    if (returnedPiece->Left == neededSidePiece)
                        if (returnedPiece->Top == neededTopPiece)
                            break;
                }
                FRotator rotation = returnedPiece->GetActorRotation();
                rotation.Pitch -= (90 * iterations);
                returnedPiece->SetActorRotation(rotation);

                return returnedPiece;
            }
        }
    }
    else if (TopPiece == EPuzzleSideType::None)
    {
        for (int i = 0; i < SideVector.size(); i++)
        {
            //Checking if vector has tried the piece before or if piece is already in use
            if (std::find(PiecesTriedWithThisPiece[currentPiece->index].begin(),
                PiecesTriedWithThisPiece[currentPiece->index].end(),
                SideVector[i]->index) != PiecesTriedWithThisPiece[currentPiece->index].end() ||
                std::find(OrderOfPieces.begin(),
                    OrderOfPieces.end(),
                    SideVector[i]->index) != OrderOfPieces.end())
            {
                continue;
            }
            else
            {
                NumPiecesRemoved += 1;

                APuzzlePiece* returnedPiece = SideVector[i];

                if (!returnedPiece->canBeUsedTwice)
                {
                    PiecesTriedWithThisPiece[currentPiece->index].push_back(SideVector[i]->index);

                    auto it = std::find(SideVector.begin(), SideVector.end(), SideVector[i]);
                    SideVector.erase(it);
                }
                else
                {


                    if (returnedPiece->timesUsed < 1)
                        returnedPiece->timesUsed++;
                    else
                    {
                        PiecesTriedWithThisPiece[currentPiece->index].push_back(SideVector[i]->index);

                        auto it = std::find(SideVector.begin(), SideVector.end(), SideVector[i]);
                        SideVector.erase(it);

                        Rotate(returnedPiece, 1);
                    }
                }
                int iterations = 0;

                while (returnedPiece->Left != neededSidePiece)
                {
                    Rotate(returnedPiece, 1);
                    iterations++;
                }
                FRotator rotation = returnedPiece->GetActorRotation();
                rotation.Pitch -= (90 * iterations);
                returnedPiece->SetActorRotation(rotation);

                return returnedPiece;
            }
        }
    }
    else if (SidePiece == EPuzzleSideType::None)
    {
        for (int i = 0; i < TopVector.size(); i++)
        {
            int iterations = 0;

            //Checking if vector has tried the piece before or if piece is already in use
            if (std::find(PiecesTriedWithThisPiece[currentPiece->index].begin(),
                PiecesTriedWithThisPiece[currentPiece->index].end(),
                TopVector[i]->index) != PiecesTriedWithThisPiece[currentPiece->index].end() ||
                std::find(OrderOfPieces.begin(),
                    OrderOfPieces.end(),
                    TopVector[i]->index) != OrderOfPieces.end())
            {
                continue;
            }
            else
            {
                NumPiecesRemoved += 1;

                APuzzlePiece* returnedPiece = TopVector[i];

                if (!returnedPiece->canBeUsedTwice)
                {
                    PiecesTriedWithThisPiece[currentPiece->index].push_back(TopVector[i]->index);

                    auto it = std::find(TopVector.begin(), TopVector.end(), TopVector[i]);
                    TopVector.erase(it);
                }
                else
                {

                    if (returnedPiece->timesUsed < 1)
                        returnedPiece->timesUsed++;
                    else
                    {
                        PiecesTriedWithThisPiece[currentPiece->index].push_back(TopVector[i]->index);

                        auto it = std::find(TopVector.begin(), TopVector.end(), TopVector[i]);
                        TopVector.erase(it);

                        Rotate(returnedPiece, 1);
                        iterations++;
                    }
                }

                while (returnedPiece->Top != neededTopPiece)
                {
                    Rotate(returnedPiece, 1);
                    iterations++;
                }
                FRotator rotation = returnedPiece->GetActorRotation();
                rotation.Pitch -= (90 * iterations);
                returnedPiece->SetActorRotation(rotation);

                return returnedPiece;
            }
        }
    }
    return nullptr;
}

EPuzzleSideType AGrid::SelectNeededSideType(EPuzzleSideType neededPiece)
{
    if (neededPiece == EPuzzleSideType::InwardArrow)
    {
        return EPuzzleSideType::OutwardInvertedArrow;
    }
    if (neededPiece == EPuzzleSideType::OutwardArrow)
    {
        return EPuzzleSideType::InwardInvertedArrow;
    }
    if (neededPiece == EPuzzleSideType::InwardInvertedArrow)
    {
        return EPuzzleSideType::OutwardArrow;
    }
    if (neededPiece == EPuzzleSideType::OutwardInvertedArrow)
    {
        return EPuzzleSideType::InwardArrow;
    }
    if (neededPiece == EPuzzleSideType::Cross)
    {
        return EPuzzleSideType::InvertedCross;
    }
    if (neededPiece == EPuzzleSideType::InvertedCross)
    {
        return EPuzzleSideType::Cross;
    }
    if (neededPiece == EPuzzleSideType::Octagon)
    {
        return EPuzzleSideType::InvertedOctagon;
    }
    if (neededPiece == EPuzzleSideType::InvertedOctagon)
    {
        return EPuzzleSideType::Octagon;
    }

    return EPuzzleSideType::None;
}

std::vector<APuzzlePiece*> AGrid::SelectNeededVector(EPuzzleSideType neededPiece)
{
    if (neededPiece == EPuzzleSideType::InwardArrow)
    {
        return OutwardInvertedArrow;
    }
    if (neededPiece == EPuzzleSideType::OutwardArrow)
    {
        return InwardInvertedArrow;
    }
    if (neededPiece == EPuzzleSideType::InwardInvertedArrow)
    {
        return OutwardArrow;
    }
    if (neededPiece == EPuzzleSideType::OutwardInvertedArrow)
    {
        return InwardArrow;
    }
    if (neededPiece == EPuzzleSideType::Cross)
    {
        return InvertedCross;
    }
    if (neededPiece == EPuzzleSideType::InvertedCross)
    {
        return Cross;
    }
    if (neededPiece == EPuzzleSideType::Octagon)
    {
        return InvertedOctagon;
    }
    if (neededPiece == EPuzzleSideType::InvertedOctagon)
    {
        return Octagon;
    }
    return std::vector<APuzzlePiece*> {};

}
