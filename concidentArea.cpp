#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Rectangle{
public:
    int x1,y1,x2,y2;
    Rectangle(int x,int y,int z,int w):x1(x),y1(y),x2(z),y2(w) {};
    int intersect_with(Rectangle r){
        if(y2<r.y1||y1>r.y2||x2<r.x1||x1>r.x2)  return 0;
        int X1=(x1>r.x1)?x1:r.x1;
        int X2=(x2<r.x2)?x2:r.x2;
        int Y1=(y1>r.y1)?y1:r.y1;
        int Y2=(y2<r.y2)?y2:r.y2;
        int len=abs(X1-X2);
        int lon=abs(Y1-Y2);
        return len*lon;
    }
};

int main(){
    double a_x, a_y, b_x, b_y;
    double c_x, c_y, d_x, d_y;
    cin >> a_x >> a_y >> b_x >> b_y;
    cin >> c_x >> c_y >> d_x >> d_y;
  	
    Rectangle r1(a_x, a_y,b_x, b_y);
    Rectangle r2(c_x, c_y,d_x, d_y);
    cout<<r1.intersect_with(r2)<<endl;
    
    return 0;
}