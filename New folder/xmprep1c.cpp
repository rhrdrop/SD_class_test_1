#include<bits/stdc++.h>
using namespace std;

class Employee{
       string name;

       double salary;
public:
    Employee(string n, double s){
          name = n;
          salary = s;
    }
    virtual void calculateSalary() = 0;

    void display(){
          cout << name << endl;
          cout << salary << endl;
    }

};

class permanentEmployee : public Employee{
     int month;
     double PMsalary;
public:
    permanentEmployee(string n,int m, double pm): Employee(n,0){
           month = m;
           PMsalary = pm;
    }
    void calculateSalary() override{
         salary = month * PMsalary;
    }

};

class contractEmployee : public Employee{
     int day;
     double PDsalary;
public:
    contractEmployee(string n,int d, double pd): Employee(n,0){
           day = d;
           PDsalary = pd;
    }
    void calculateSalary() override{
         salary = day * PDsalary;
    }

};

int main(){
   permanentEmployee A("MOKLESS", 17 ,23000);
   contractEmployee B("Elahi", 7 , 700);

   A.calculateSalary();
   A.display();

   B.calculateSalary();
   B.display();

}
