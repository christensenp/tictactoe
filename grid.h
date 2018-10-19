#include <vector>
#include <string>

enum class Marker {E, X, O}; 

class Gridsquare 
{
    private:

        Marker marker;
        
    public:

        Gridsquare();
    
        void setMarker(Marker m);
        
        char print();
};


class Grid
{
    private:

    Gridsquare** gsquares;

    public:

        Grid();
        
        ~Grid();

        void printGrid();
        
};







