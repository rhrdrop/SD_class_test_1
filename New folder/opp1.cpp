#include <bits/stdc++.h>
using namespace std;

class shape {
public:
    virtual void area() {
    cout << "area not define" << endl;
    }
};

class rectangular : public shape {
  float length , width;

  public :
      rectangular(float l, float w) {
      length = l;
      width = w;
      }
      void area() override {
      cout << "area of rectangle :" << length * width << endl;

      }
};

class circle : public shape {
   float radius;

   public :
       circle (float r) {

       radius = r;
       }
   void area() override {

   cout << "area of circle :" << 3.1216 * radius * radius << endl;

       }
};

int main() {
shape *s;

rectangular r(10 , 20);
circle c(23);

s = &r;
s -> area();
s = &c;
s -> area();
return 0;

}









