#include <iostream>
#include <string>
#include "Point.h"
#include "MyIO.h"
using namespace std;

void walkDFS( vector<Point*> &pool, Point *p ) ;
void walkDjs( Point *from, vector<Point*> allPoint ) ;

int main()
{
  int a= 567 ;
  string s = (string) a ;
  cout << s[1] ;
  string inputLine = "" ;
  inputLine = MyIO::getLine() ;
  vector<Point*> allPoint ;
  vector<Point*> DFSPoint ;
  Point *start = NULL ;
  while ( inputLine.find( "ENDCIRCUIT" ) == -1 ) {
    if ( inputLine.find( "INSTANCE" ) != -1 ) {
      string name = inputLine.substr( inputLine.find( " " ) + 1 ).substr( 0, inputLine.substr( inputLine.find( " " ) + 1 ).find( " " ) ); // 切出 NAME
      inputLine = MyIO::getLine() ;
      if ( inputLine.find( "(" ) != -1 || inputLine.find( ")" ) != -1 ) {
        Point *p = new Point( name, inputLine ) ;
        if ( p->name.compare( "S" ) == 0 )
          start = p ;
        allPoint.push_back( p ) ;
      } // if
      else {
        cout << "input error" << endl ;
        break ;
      } // else
    } // if

    inputLine = MyIO::getLine() ;
  } // while

  /* 將所有點連接 */
  for ( Point *i : allPoint )
    for ( Point *j : allPoint )
      i->setContect( j ) ;

  cout << "=================================" << endl
       << "DFS 探索 : " << endl ;
  walkDFS( DFSPoint, start ) ;
  for ( Point *dfs : DFSPoint )
    cout << dfs->name << " " ;
  cout << endl ;
  cout << "=================================" << endl ;
  cout << endl ;
  cout << "=================================" << endl
       << "Dijkstra 與 S 距離 : " << endl ;
  walkDjs( start, allPoint ) ;
  cout << "=================================" << endl ;

  for ( Point *p : allPoint )
    delete p ;
  system( "pause" ) ;
  return 0;
} // main()

void walkDFS( vector<Point*> &pool, Point *p ) {
  p->dfsWalked = true ;
  pool.push_back(p) ;
  if ( p->name.compare( "D" ) == 0 )
    return ;
  for ( auto &point : p->connect ) {
    if ( !(point.first)->dfsWalked ) { // 沒走過
      // 走
      walkDFS( pool, point.first ) ;
    } // if
  } // for
} // walkDFS()

void walkDjs( Point *from, vector<Point*> allPoint ) {
  vector<Point*> PQ ;
  vector<int> PQdist ;
  map<Point*, int> dist ;
  for ( Point *p : allPoint )
    dist[p] = 999999 ;
  dist[from] = 0 ;
  for ( Point *p : allPoint ) {
    PQ.push_back( p ) ;
    PQdist.push_back(dist[p]) ;
  } // for

  Point *u = from ;
  Point *ptemp = NULL ;
  int temp = 0 ;
  while ( !PQ.empty() ) {
    // 將queue排序
    for ( int i = 0 ; i < PQ.size() ; i++ )
      for ( int j = i + 1 ; j < PQ.size() ; j++ )
        if ( PQdist[i] < PQdist[j] ) {
          temp = PQdist[i] ;
          PQdist[i] = PQdist[j] ;
          PQdist[j] = temp ;
          ptemp = PQ[i] ;
          PQ[i] = PQ[j] ;
          PQ[j] = ptemp ;
        } // if

    // 抓取queue中最小的距離
    u = PQ.back() ;
    PQ.pop_back() ;
    PQdist.pop_back() ;

    for ( auto &e : u->connect ) {
      int newDist = dist[u] + e.second ;
      if ( newDist < dist[e.first] ) {
        PQ.push_back( e.first ) ;
        PQdist.push_back( newDist ) ;
        dist[e.first] = newDist ;
      } // if
    } // for
  } // while

  for ( auto &e : dist )
    cout << "S to " << e.first->name << " : " << e.second << endl ;
} // walkDjs()
