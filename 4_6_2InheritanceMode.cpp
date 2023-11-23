//Interitance Mode(继承方式)
    //0.子类无论用哪种继承方式，都无法访问到父类中的private，但是继承了private中的属性和行为
    //1.public interit:父类中的protected和public在子类中该是啥还是啥
        //可以试一下这串代码，然后可以对其做调整，把friend的声明加到Father里面试一下
        // class Father{
        // 	private:
        // 	int a;
        // };
        // class Son:public Father{
        // 	friend void test01();
        // };
        // void test01(){
        // 	Son m;
        // 	m.a=3;
        // }
    //2.protected:父类中的public和protected在子类中都变为protected
    //3.private:父类中的public和protected在子类中都变为private