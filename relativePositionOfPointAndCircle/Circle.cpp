#include"Circle.h"
#include<iostream>
#include<math.h>
using namespace std;

double len(int x,int y, int a, int b)
{
double len1=(x-a)*(x-a);
double len2=(y-b)*(y-b);
return sqrt(len1+len2);
}
void Circle::setPos(int a,int b)
{
x=a;
y=b;
}
void Circle::setRadius(int a)
{
radius=a;
}
void Circle::det(Point &p)
{
double dis=len(x,y,p.horizontalX(),p.verticalY());
if (dis<radius)
{
cout<<"the point is in the circle"<<endl;
}
else if(dis==radius)
{
cout<<"the point is on the circle"<<endl;
}
else
{
cout<<"the point is outside the circle"<<endl;
}
};

