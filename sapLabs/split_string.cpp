#include<bits/stdc++.h>
using namespace std;
vector<string> splitString(const string &str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str); //creates a string stream object named ss and initializes with the content of the string str
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
   return tokens;
}
int main() {
   string str = "split,this,string,by,comma";
    char delimiter = ',';
    vector<string> result = splitString(str, delimiter);
    for (const auto &s : result) {
        cout << s << endl;
    }
    return 0;
}

/*
stringstream: 
This is a class in C++ that allows you to treat a string as if it were a stream
(like a file or input/output stream). It enables operations like reading from and writing to 
the string in a way similar to how you'd handle files or standard input/output.

while (std::getline(ss, token, delimiter)) { ... }
Purpose: This loop continuously extracts tokens (substrings) from the string stream ss
until there are no more tokens left.




*/