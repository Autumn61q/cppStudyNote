//Deep Copy and Shallow Copy
//Shallow Copy:simple assignment(赋值) copy
//             the constructor defined by complier will just shallow copy.Which means that the height in the 26th line in p1 and p2 comes
//             from the same address,which means p1.m_height and p2.m_height point to the same address.then when destruct p2.m_height,
//             we actually release the area in the heap area, then p1.m_height becomes a wild pointer.To summarize,the problem we meet is 
//             want to release the memory in heap area two times.
//             # we need Deep copy to solve this problem
//Deep Copy:re-apply for space in the heap area and perform the copy operation
//Conclusion:if there is some member variables in heap area,you are ought to provide relevant contructor and destructor by yourself.

// #include<iostream>
// using namespace std;

// class Person
// {
// public:
//     Person()
//     {
//         cout<<"default constructor"<<endl;
//     }
//     ~Person()
//     {
//         //destruct code,release data in the heap area
//         if(m_height!=NULL)
//         {
//             delete m_height;
//             m_height=NULL;
//         }
//         cout<<"default destructor"<<endl;
//     }
//     Person(int a,int height)
//     {
//         m_age=a;
//         m_height=new int (height);
//         cout<<"parameterized constructor"<<endl;
//     }
//     int m_age;
//     int *m_height;
// };

// void test01()//the order to relesae p1 and p2:the first to enter is the last to left.
// {
//     Person p1(18,160);
//     cout<<p1.m_age<<"\t"<<*p1.m_height<<endl;
//     Person p2(p1);
//     cout<<p2.m_age<<"\t"<<*p2.m_height<<endl;
// }

// int main()
// {
//     test01();
//     return 0;
// }


#include<iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout<<"default constructor"<<endl;
    }
    ~Person()
    {
        //destruct code,release data in the heap area
        if(m_height!=NULL)
        {
            delete m_height;
            m_height=NULL;
        }
        cout<<"default destructor"<<endl;
    }
    Person(const Person &p)
    {
        m_age=p.m_age;
        //m_height=p.m_height;//the defined copy constructor write this line
        m_height=new int(*p.m_height);//change it into this
        cout<<"copy constructor"<<endl;
    }
    Person(int a,int height)
    {
        m_age=a;
        m_height=new int (height);
        cout<<"parameterized constructor"<<endl;
    }
    int m_age;
    int *m_height;
};

void test01()//the order to relesae p1 and p2:the first to enter is the last to left.
{
    Person p1(18,160);
    cout<<p1.m_age<<"\t"<<*p1.m_height<<endl;
    Person p2(p1);
    cout<<p2.m_age<<"\t"<<*p2.m_height<<endl;
}

int main()
{
    test01();
    return 0;
}
