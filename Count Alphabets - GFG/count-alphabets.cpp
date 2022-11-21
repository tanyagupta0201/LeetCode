//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int Count(string S);


int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        cout << Count(S) << endl;
    }
return 0;
}


// } Driver Code Ends


int Count(string s)
{
    //complete the function here
    int cnt = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') )
        {
            cnt++;
        }
    }
    
    return cnt;
}