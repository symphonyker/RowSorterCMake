#include "rowsorter.h"
#include "parser.h"

RowSorter::RowSorter( const std::string &inFile, const std::string &outFile )
    : _parser( new Parser ), _inFile( inFile ), _outFile( outFile )
{
    _inStream.open( _inFile );
    _outStream.open( _outFile );
}

RowSorter::~RowSorter()
{
    _inStream.close();
    _outStream.close();
}




void RowSorter::_sortFile()
{
    std::string inLine;
    std::string outLine;
    while( 1 )
    {
        if( _inStream.eof() ) break;
        std::getline( _inStream, inLine );
        outLine = _parser->parse( inLine );
        _outStream << outLine<<"\n";
    }

}

bool RowSorter::exec()
{
    if( !_inStream )
    {
        std::cerr<<"Can`t open Input file: "<<_inFile<<std::endl;
        return false;
    }
    if( !_outStream )
    {
        std::cerr<<"Can`t open Output file: "<<_outFile<<std::endl;
        return false;
    }
    _sortFile();
    std::cout<<"done\nInput file: "<<_inFile<<"\nSorted file: "<< _outFile <<std::endl;
    return true;

}
