#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
using namespace std;

class Point
{
  public:
    string name ;
    map<string,int> inEdge ;
    map<string,int> outEdge ;
    map<Point*, int> connect ;
    bool dfsWalked ;

    Point();
    virtual ~Point();
    Point( string name, string edges );
    void setContect( Point *p ) ;
  protected:

  private:
    vector<string> getEdges( string e ) ;
    void setIOEdge( vector<string> es ) ;
};

#endif // POINT_H
