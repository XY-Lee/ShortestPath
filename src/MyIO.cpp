#include "MyIO.h"

MyIO::MyIO()
{
  //ctor
}

MyIO::~MyIO()
{
  //dtor
}

string MyIO::getLine() {
  string rtn = "" ;
  char ch = '\0' ;
  scanf( " %c", &ch ) ;
  while ( ch != '\n' ) {
    rtn += ch ;
    scanf( "%c", &ch ) ;
  } // while

  while ( rtn.find( "\t" ) != -1 )
    rtn = rtn.replace( rtn.find( "\t" ), rtn.find( "\t" ) + 1, " ") ;
  return rtn ;
} // getLine())
