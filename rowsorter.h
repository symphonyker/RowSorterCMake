#ifndef ROWSORTER_H
#define ROWSORTER_H
#include <string>
#include <memory>
#include <iostream>
#include <fstream>

class Parser;

class RowSorter
{
private:
    std::unique_ptr<Parser> _parser;
    std::string _inFile;
    std::string _outFile;
    std::ifstream _inStream;
    std::ofstream _outStream;
    void _sortFile();

public:
    RowSorter( const std::string &inFile, const std::string &outFile );
    bool exec();
    ~RowSorter();

};

#endif // ROWSORTER_H
