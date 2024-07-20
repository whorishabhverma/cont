/* 
deep copy : constructor khud likhna pdta hai iske liye 
isme hum dynamically allocated ki bhi copy bnate hai
*/

#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    double *cgpaptr;
    Student(string name,double cgpa){
        this->name=name;
        cgpaptr = new double;
        *cgpaptr=cgpa;
        
    }
    Student(Student &obj){
        this->name = obj.name;
        cgpaptr = new double;
        *cgpaptr = *obj.cgpaptr;
    }

    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"cgpa : "<<*cgpaptr<<endl;
    }
};
int main(){
    Student obj1("rishabh",8.9);
    obj1.getInfo();
    Student obj2(obj1);
    obj2.getInfo();
    *(obj2.cgpaptr) = 9.9;
    obj2.getInfo();

    //deep copy me khud likhna pdega 
}
