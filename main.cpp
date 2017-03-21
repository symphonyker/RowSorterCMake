#include <iostream>
#include "rowsorter.h"

using namespace std;

const std::string prefix = "_sorted";

int main(int argc, char *argv[])
{

    if( argc != 2 )
    {
        std::cerr<<"Invalid parametrs";
        return 1;
    }
    std::string fileName = argv[1];//"C:\\Users\\User\\Documents\\build-RowSorter-Desktop_Qt_5_5_1_MinGW_32bit-Debug\\debug\\testRow1.txt";
    RowSorter rowSorter( std::string( fileName ), std::string( fileName + prefix ) );
    return  !rowSorter.exec();
}
