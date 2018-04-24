#include "Point.h"

Point::Point()
{
  //ctor
  this->dfsWalked = false ;
}

Point::~Point()
{
  //dtor
}

Point::Point( string name, string edges ) {
  this->dfsWalked = false ;
  this->name = name ;
  this->setIOEdge( this->getEdges( edges ) ) ;
  /*
  for( auto &one : this->inEdge )
    cout << one.first << one.second << endl ;
  /* debug¥Î~ */

} // Point

vector<string> Point::getEdges( string e ) {
  vector<string> v ;
  while ( e.find( "(" ) != -1 ) {
    v.push_back( e.substr( 0, e.find( " " ) ) ) ;
    e = e.substr( e.find( " " ) + 1, e.length() ) ;
    if ( v.back().find( e ) != -1 )
      break ;
  } // while

  return v ;
} // getEdges())

void Point::setIOEdge( vector<string> es ) {
  string name = "" ;
  int weight = 0 ;
  for ( string e : es ) {
    name = e.substr( 0, e.find( "("  ) ) ;
    e = e.substr( e.find( "(" ) + 1 ) ;
    weight = atoi( e.substr( 0, e.find( "," ) ).c_str() ) ;
    if ( e.find( ",i" ) != -1 ) {
      this->inEdge[name] = weight ;
    } // if
    else {
      this->outEdge[name] = weight ;
    } // else
  } // for
} // setIOEdge()

void Point::setContect( Point *p ) {
  for ( auto &e : this->outEdge )
    if ( p->inEdge[e.first] != 0 ) {
      this->connect[p] = e.second ;
      // cout << this->name << " " << e.first << " w:" << this->connect[p] << " " << p->name << endl ;
    } // if
} // setContect())
