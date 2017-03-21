#include "parser.h"
#include "rowitem.h"
#include <iostream>
#include <regex>


Parser::Parser()   
{

}

Parser::~Parser()
{

}


std::string Parser::parse( const std::string & in )
{
    if( in.empty() )
        return std::string();

    std::shared_ptr< MultiRowItem > parent { std::make_shared<MultiRowItem>() };
    std::shared_ptr< MultiRowItem > curItem { parent };
    std::regex r ("[a-zA-Z]");
    std::string sym;
    for( int i = 0; i < in.size(); ++i )
    {
        if( ( ( in[i] == '(' ) && ( i == 0 ) ) || ( ( in[i] == ')' ) && ( i == in.size() - 1 ) ) )
            continue;
        sym = in[i];
        if( sym == "(" )
        {
            std::shared_ptr< MultiRowItem >nItem {  std::make_shared<MultiRowItem>() };
            nItem->setParent(  curItem  );
            curItem = nItem;
        }
        else if( sym == ")" )
        {
            std::shared_ptr< MultiRowItem > p { std::dynamic_pointer_cast<MultiRowItem>( curItem->getParent() ) };
            p->addSortItem(  curItem  );
            curItem = p;
        }
        else if( std::regex_match( sym, r ) )
        {
            std::shared_ptr<SingleRowItem> nItem{ std::make_shared<SingleRowItem>() };
            nItem->setValue( sym );
            curItem->addSortItem( nItem  );
        }
    }
    return parent->toString();

}



