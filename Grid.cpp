#include "Grid.h"

Gridsquare::Gridsquare()
: marker{Marker::E}
{}

void Gridsquare::setMarker(Marker m)
{
    marker = m;
}

char Gridsquare::print() const
{
    switch (marker)
    {
        case Marker::E :
            return ' ';
        case Marker::X :
            return 'X';
        case Marker::O :
            return 'O';
    }
}

///////////////////////////////////////

Grid::Grid()
    : gsquares{new Gridsquare*[3]}
{
    for( int i = 0; i < 3; ++i )
        gsquares[i] = new Gridsquare[3];
}

Grid::~Grid()
{
    for( int i = 0; i < 3; ++i )
        delete[] gsquares[i];

    delete[] gsquares;

}

void Grid::printGrid() const
{
    printf("\n\n");
    printf("\t %2c |%2c |%2c\n",
            gsquares[2][0].print(),
            gsquares[2][1].print(),
            gsquares[2][2].print());
    printf("\t -----------\n");
    printf("\t %2c |%2c |%2c\n",
            gsquares[1][0].print(),
            gsquares[1][1].print(),
            gsquares[1][2].print());
    printf("\t -----------\n");
    printf("\t %2c |%2c |%2c\n",
            gsquares[0][0].print(),
            gsquares[0][1].print(),
            gsquares[0][2].print());
    printf("\n\n");
}

void Grid::placeMarker(Marker m)
{
    assert(m != Marker::E);
    
    int input;
    std::cin >> input;
    input--;

    if ( input >= 0 && input <= 8 )
    {
        int i = input/3;
        int j = input%3;
        Marker currmarker = gsquares[i][j].getMarker();

        if ( currmarker != Marker::E )
        {
            std::cout << "Invalid Input, space is occupied.\n";
            placeMarker(m);
        }
        else
        {
            gsquares[i][j].setMarker(m);
        }

    }
    else
    {
        std::cout << "Invalid Input, enter a number 1-9.\n";
        placeMarker(m);
    }
}

bool Grid::checkWinner()
{
    for (int i = 0; i < 3; ++i)
    {
        bool rbool = checkRow(i);
        bool cbool = checkColumn(i);
        
        if (cbool || rbool)
            return true;
    }

    if (checkDiags())
        return true;
    else 
        return false;
}

bool Grid::checkRow(int i)
{
    Marker checkmarker1 = gsquares[i][0].getMarker();
    Marker checkmarker2 = gsquares[i][1].getMarker();
    Marker checkmarker3 = gsquares[i][2].getMarker();
    
    if (checkmarker1 == Marker::X)
        {
            if (checkmarker2 == Marker::X && 
                checkmarker3 == Marker::X)
                return true;
            else 
                return false;
        }    
    else if (checkmarker1 == Marker::O)
        {
            if (checkmarker2 == Marker::O && 
                checkmarker3 == Marker::O)
                return true;
            else 
                return false;
        }    
    else 
        return false;
}

bool Grid::checkColumn(int j)
{
    Marker checkmarker1 = gsquares[0][j].getMarker();
    Marker checkmarker2 = gsquares[1][j].getMarker();
    Marker checkmarker3 = gsquares[2][j].getMarker();

    if (checkmarker1 == Marker::X)
        {
            if (checkmarker2 == Marker::X && 
                checkmarker3 == Marker::X)
                return true;
            else 
                return false;
        }    
    else if (checkmarker1 == Marker::O)
        {
            if (checkmarker2 == Marker::O &&
                checkmarker3 == Marker::O)
                return true;
            else 
                return false;
        }    
    else 
        return false;
}

bool Grid::checkDiags()
{
    Marker checkmarker1 = gsquares[0][0].getMarker();
    Marker checkmarker2 = gsquares[1][1].getMarker();
    Marker checkmarker3 = gsquares[2][2].getMarker();
    Marker checkmarker4 = gsquares[0][2].getMarker();
    Marker checkmarker5 = gsquares[2][0].getMarker();

    if (checkmarker1 == Marker::X &&
        checkmarker2 == Marker::X && 
        checkmarker3 == Marker::X)
        return true;
    else if (checkmarker1 == Marker::O &&
             checkmarker2 == Marker::O &&
             checkmarker3 == Marker::O
            )
        return true;
    else if (checkmarker2 == Marker::X &&
             checkmarker4 == Marker::X &&
             checkmarker5 == Marker::X)
        return true;
    else if (checkmarker2 == Marker::O && 
             checkmarker4 == Marker::O && 
             checkmarker5 == Marker::O)
        return true;
    else 
        return false;
}
