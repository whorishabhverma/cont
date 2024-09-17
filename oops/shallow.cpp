/* shallow copy : ye tb dikkt krega jb memory dynamically allocate krao like with the help of new and pointers 
Shallow Copy:
Creates a new object and copies the values of all members.
For pointer members, only the pointer address is copied, not the pointed-to data.
Both the original and copied objects end up pointing to the same memory locations for dynamically allocated members.
Typically implemented by the default copy constructor and assignment operator.
*/

#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    double *cgpaptr;
    Student(string n,double cg){
        cgpaptr = new double;
        *cgpaptr=cg;
        name=n;
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
    obj1.getInfo();
    //change hum obj2 ke andr kr rhe but change obj1 bhi ho gya , bss yhi problem h shallow copy ki 
}
