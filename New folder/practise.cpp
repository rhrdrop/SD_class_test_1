#include<bits/stdc++>
using namespace std;
class complex{
public:
    double real;
    double image;
    complex(double real=0,0, double image=0.0){
    this-> real=real;
    this->image=image;
    }
complex operator + (complex c2){
double newReal= real + c2.real;
double newImage= image + c2.image;
return complex (newReal, newImage);
} bool operator == (complex c2){
if(real==c2.real && image==c2.image){
    return true;
}else
return false;
}
void display(){
if (image>= 0){
    cout<< real << " + "<< image << "i"<< endl;}
    else
        cout<< real << "-"<<-image<<"i"<< endl;

}




} ;
