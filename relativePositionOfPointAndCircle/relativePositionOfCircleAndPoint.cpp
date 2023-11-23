#include<iostream>
#include<math.h>
using namespace std;
#include"Circle.h"
#include"point.h"



int main()
{
Circle o;
o.setRadius(2);
o.setPos(1,1);
Point p;
p.setPos(1,3);
o.det(p);
return 0;
}