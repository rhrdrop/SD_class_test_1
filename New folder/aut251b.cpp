#include<bits/stdc++.h>
using namespace std;

class Counter{

    int count;

 public:
    
    Counter(int c=0){
        count=c;
    }

    friend Counter& operator++(Counter &c);

    friend Counter operator++(Counter &c, int);
    
    void display(){
        cout << count << endl;
    }
};

Counter& operator++(Counter &c){
        ++c.count;
        return c;
    }

Counter operator++(Counter &c, int){
        Counter temp=c;
        c.count++;
        return temp;
    }
   

int main(){
    Counter a(5);

    a.display();

    ++a;

    a.display();

    a++;

    a.display();


}