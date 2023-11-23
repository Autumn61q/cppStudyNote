#include<iostream>
#include<vector>
using namespace std;

bool determine(const vector<vector<char> >&maze,int x,int y)
{
    if (maze[x][y]=='o') return true;
    else if (maze[x][y]=='w') return false;
    return determine(maze,x+1,y)||determine(maze,x,y+1);
}

int main()
{   int A,B;
    cin>>A>>B;
    vector<vector<char> > maze(A,vector<char>(B));
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<B;j++)
        {
            cin>>maze[i][j];
        }
    }
    maze[1][1]='x';
    cout << (determine(maze,1,1)? "True" : "False")<< endl;
    return 0;
}