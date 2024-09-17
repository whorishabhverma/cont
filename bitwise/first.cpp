#include<bits/stdc++.h>
using namespace std;
void DecimalToBinary(){
    int n=258;
    string ans="";
    while(n!=0){
        if(n%2==0){
            ans+='0';
        }else{
            ans+='1';
        }
        n=n/2;
    }
    reverse(ans.begin(),ans.end());
    cout<<"decimal to binary -> "<<ans;
}
void BinaryToDecimal(){
    string str = "11111";
    int p=0,ans=0;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]=='1'){
            ans+=pow(2,p);
        }
        p++;
    }
    cout<<"binary to decimal -> "<<ans;
}

int main(){
    // DecimalToBinary();
    // BinaryToDecimal();
    
}