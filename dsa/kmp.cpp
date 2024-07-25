//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // Function to create the partial match table (prefix table)
vector<int> computePrefixFunction(const string &pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}
        vector <int> search(string pattern, string text)
        {
            int n = text.length();
    int m = pattern.length();
    vector<int> lps = computePrefixFunction(pattern);

    int i = 0; // Index for text
    int j = 0; // Index for pattern
    vector<int> ans;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            ans.push_back(i-j+1);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return ans;
        }
     
};


int main()
{


    // string text="geeksforgeeks";
    // string pattern = "geek";
    int t;
    cout<<"enter no. of  test cases"<<endl;
    cin >> t;

    while (t--)
    {
        cout<<"enter text"<<" -> ";

        string S,pat;
        cin>>S;
        cout<<"\nenter pattern"<<" -> ";
         cin>>pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

