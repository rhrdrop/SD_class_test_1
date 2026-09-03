//#include<bits/stdc++.h>
//
//using namespace std;
//class A{
//public:
//    void show(){
//        cout<<"hello from class A"<<endl;
//    }
//};
//
//class B{
//public:
//    void show(){
//        cout<<"hello from class B"<<endl;
//    }
//};
//
//class Derived: public A , public B{
//
//} ;
//
//int main(){
//    Derived objD;
//    objD.A::show();
//    objD.B::show();
//
//
//}

#include<bits/stdc++.h>
using namespace std;
class A{
public:
    void show(){
        cout<<"From class A"<<endl;
    }
};

class B: virtual public A{

};

class C: virtual public A{

};

class D: public B, public C{

};
int main(){
    D objD;
    objD.show();
}
