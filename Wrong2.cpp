#include<bits/stdc++.h>
using namespace std;

class myphone;

class phone{
	// write your code here......
	friend int myphone::getprice();
	// friend class myphone;
	private:
	public:
		int price;
		phone(){};
		phone(int x){
			price=x;
		}
}; 

class myphone{
	private:
		phone a;
	public:
		myphone(int x): a(x){
		}
		int getprice(){
			return a.price;
		}
};



int main(){
	int p;
	cin>>p;
	myphone a(p);
	cout<<a.getprice();
	return 0;
}

