#include<bits/stdc++.h>
using namespace std;

class Demo {
    int x;
public:
    Demo(int x) {
        this->x = x;
    }
    
    void show() const { cout << x; }

    ~Demo() { cout << "END"; }

    
    friend void bump(Demo &d); 
};

void bump(Demo &d) { 
    d.x++; 
}

int main() {
    Demo* p = new Demo(5);
    bump(*p);    // x এর মান ৫ থেকে বেড়ে ৬ হবে
    p->show();   // আউটপুট: 6
    delete p;    // আউটপুট: END (ডেস্ট্রাক্টর কল হবে)
    return 0;
}