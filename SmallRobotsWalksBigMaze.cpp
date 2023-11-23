#include<iostream>
#include<vector>
using namespace std;

void drawMap(vector<vector<char> > &v,int A,int B)
{
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<B;j++)
        {
            cin>>v[i][j];
        }
    }
}
bool determine(vector<vector<char> > &v,int A,int B,int x=1,int y=1)
{
    if(x==B-2&&y==A-2)
    {
        return true;
    }
    if(v[x][y+1]=='x'&&y+1<=A-2)
    {
        if (determine(v, A, B, x , y+1)) {
            return true;
        }
    }
    if(v[x+1][y]=='x'&&x+1<=B-2)
    {
        if (determine(v, A, B, x + 1, y))
         {
            return true;
        }
    }
    return false;
}
int main()
{
    int A,B;
    cin>>A>>B;
    vector<vector<char> >v(B,vector<char> (A));
    drawMap(v,A,B);
    bool result=determine(v,A,B);
    if(result)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}