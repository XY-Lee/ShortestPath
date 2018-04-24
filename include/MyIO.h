#ifndef MYIO_H
#define MYIO_H
#include <stdio.h>
#include <string>
using namespace std;

class MyIO
{
  public:
    MyIO();
    virtual ~MyIO();
    static string getLine() ;
  protected:

  private:
};

#endif // MYIO_H
