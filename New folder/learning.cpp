#include<bits/stdc++.h>
using namespace std;
/*
File Handling (reading and writing files)
Exception Handling (try, throw, catch)
Templates (generic function)
*/

int main(){
///writing to a file
//ofstream file1;  // create a file object
//file1.open("data.txt"); //open file
//
//file1<<"hello world"<<endl;
//file1<<"welcome to c++"<<endl;
//
//file1.close();  //close file
//
//cout<<"Data written successfully"<<endl;

ifstream file;
string line;

file.open("data.txt");

while(getline(file, line)){
    cout<<line<<endl;
}

file.close();

return 0;



}
