template<class T>
class Person{
public:
    Person(T a);
    void getAge();
    T age;
};

//implement constructor
template<class T>
Person<T>::Person(T a):age(a){}

//implement member function
template<class T>
void Person<T>::getAge(){
    cout<<age<<endl;
}
