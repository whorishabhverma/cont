#include<bits/stdc++.h>
using namespace std;
pair<int,int> fun(int a,int b){
    int sum = a+b;
    int sub = a-b;
    return {sub,sum};
}
int main(){
    pair<int,int> p =  fun(10,4);
    cout<<p.first<<" "<<p.second;
}