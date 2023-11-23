#include"point.h"
#include<iostream>
using namespace std;

void Point::setPos(int a,int b)
{
x=a;
y=b;
}
int Point::horizontalX()
{
return x;
}
int Point::verticalY()
{
return y;
}