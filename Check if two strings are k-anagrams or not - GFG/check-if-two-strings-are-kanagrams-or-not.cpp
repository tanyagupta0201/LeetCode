// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) 
    {
        int n = str1.length();
        
        if(str1.length() != str2.length())
             return false;
             
        int freq[26] = {0};
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            freq[str1[i] - 'a']++;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(freq[str2[i] - 'a'] > 0) // the character in str2 is present in freq array (ie. in str1)
            {
                freq[str2[i] - 'a']--; // decrease its occurence
            }
            else
            {
                count++;
            }
        }
        
        if(count <= k)
           return true;
           
        return false;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}  // } Driver Code Ends