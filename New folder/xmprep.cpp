#include<bits/stdc++.h>
using namespace std;

class Complex{
    double real;
    double imag;
public:
    //constructor
    Complex(double r, double i){
        real = r;
        imag = i;
    }
    Complex operator+(const Complex &c){
        return (real + c.real,imag + c.imag);
    }
    bool operator==(const Complex &c){
        return (real == c.real && imag == c.imag);
    }
    void display(){
       cout << real;
       if(c>=0){cout << " + " << imag << endl; }
       else{cout << " - " << -imag << endl; }
    }

};
int main(){
   Complex c1(2,4), c2(-3,-7);
   c1.display();
   c2.display();
   if(c1==c2){
    cout <<"both are equal" << endl;
   }else{cout << "Not Equal"<< endl;}
}
