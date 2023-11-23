#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;


struct Person
{
    string name;
    int age;
    double height;
    double weight;
};

void inputPerson(vector<Person> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i].name>>v[i].age>>v[i].height>>v[i].weight;
    }
}

void getPersonf(int getPerson,const vector<Person>&v)
{
    for(int i=0;i<getPerson;i++)
    {
        string Name;
        cin>>Name;
        int count = 0;
        for (Person p:v)
        {
            if (p.name==Name)
            {
                cout<<p.name<<" "<<p.age<<" "<<fixed<<setprecision(1)<<p.height<<" "<<p.weight;
                break;
            }
            count++;
            if(count==v.size())
            {
                cout<<"404 Not Found"<<endl;
            }
        }
    }
}
int main()
{
    int numberOfPerson;
    int getPerson;
    cin>>numberOfPerson>>getPerson;
    vector<Person> v(numberOfPerson);
    inputPerson(v);
    getPersonf(getPerson,v);
    return 0;
}

