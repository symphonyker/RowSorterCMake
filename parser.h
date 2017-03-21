#ifndef PARSER_H
#define PARSER_H
#include <string>

class RowItem;

class Parser
{
public:
    Parser();
    ~Parser();
    std::string parse( const std::string& );

};

#endif // PARSER_H
