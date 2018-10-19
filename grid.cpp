#include "grid.h"

Gridsquare::Gridsquare()
: marker{Marker::E}
{}

void Gridsquare::setMarker(Marker m)
{
    marker = m;
}

char Gridsquare::print()
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

void Grid::printGrid()
{
    printf("\n\n");
    printf("\t %2c |%2c |%2c\n",
            gsquares[0][0].print(),
            gsquares[0][1].print(),
            gsquares[0][2].print());
    printf("\t -----------\n");
    printf("\t %2c |%2c |%2c\n",
            gsquares[1][0].print(),
            gsquares[1][1].print(),
            gsquares[1][2].print());
    printf("\t -----------\n");
    printf("\t %2c |%2c |%2c\n",
            gsquares[2][0].print(),
            gsquares[2][1].print(),
            gsquares[2][2].print());
    printf("\n\n");
}
