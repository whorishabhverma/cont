#include<bits/stdc++.h>
using namespace std;
class Teacher{
    public:
    //non prmtrzed
    Teacher(){
        cout<<"hello, i`am constructor"<<endl;
        dept = "compuetr science";
    }
    //parametrized constructor
    Teacher(string name,string subject,string dept){
        this->name=name;
        this->subject=subject;
        this->dept=dept;
    }
    Teacher(Teacher &orgnlObj){
        cout<<" I am custom copy constructor "<<endl;
        this->name=orgnlObj.name;
        this->subject=orgnlObj.subject;
        this->dept=orgnlObj.dept;
    }
    string name;
    string dept;
    string subject;
    private:
    int salary=1000;
    public:
    void changeSalary(int newS){
        salary=newS;
        cout<<salary;
    }   
    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"subject : "<<subject<<endl;
        cout<<"department : "<<dept<<endl;
    }
};
int main(){
    // Teacher t1;
    // t1.name = "Rishabh";
    // t1.subject= "c++";
    Teacher t1("rishabh","automata","comp Science");
    t1.getInfo();
    // t1.changeSalary(1300);
    cout<<endl;
    // Teacher t2(t1);//defualt copy constructor
    Teacher t2(t1);//custom copy constructor
    t2.getInfo();
}