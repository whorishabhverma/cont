#include<bits/stdc++.h>
using namespace std;
class Teacher{
    public: //default private
    //properties
    string name,dept,subject;
    int salary;
    //methods,member functions
    void changeDept(string newDept){
       dept=newDept;
    }
};
int main(){
    Teacher obj1;
    obj1.name ="rishabh";
    obj1.dept = "computer science";
    obj1.subject = "c++";
    obj1.salary = 10000;
    cout<<obj1.name;


}