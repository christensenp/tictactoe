#ifndef GRID_H
#define GRID_H

#include <string>
#include <iostream>
#include <cassert>


enum class Marker {E, X, O}; 

class Gridsquare 
{
    private:

        Marker marker;
        
    public:

        Gridsquare();
    
        void setMarker(Marker m);
       
        Marker getMarker() const
        {
            return marker;
        }

        char print() const;
};


class Grid
{
    private:

        Gridsquare** gsquares;

        bool checkRow(int i);

        bool checkColumn(int j);

        bool checkDiags();

    public:

        Grid();
        
        ~Grid();

        void printGrid() const;
        
        void placeMarker(Marker m);

        bool checkWinner();
};




#endif
