/*
phle parent class ka constructor call hoga fir child ka
destructor phle childka fur parent ka 
parametrized constructor ko hmne bnaya to ye automatically called nhi hote inhe hme call krna hoga*/
#include<bits/stdc++.h>
using namespace std;
class Person{
    public:
    string name;
    int age;
    int rollno;
    // Person(){
    //     cout<<"Parent constructor called"<<endl;
    // }
    Person(string name,int age,int rollno){
        this->name = name;
        this->age = age;
        this->rollno  = rollno;

    }
};
class Student:private Person{
    public:
    string type;
        Student(string name,int age,int rollno,string type):Person(name,age,rollno){
            this->type=type;
            cout<<"child constructor called\n";
        }
    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"roll no. : "<<rollno<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"type : "<<type<<endl;
    }
};
int main(){
    Student s1("rishabh",13,26,"male");
    // s1.name = "rishabh verma ";
    // s1.age = 98;
    // s1.rollno = 80;
    // s1.type = "male";
    s1.getInfo();

}