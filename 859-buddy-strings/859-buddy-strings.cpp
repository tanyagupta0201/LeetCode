class Solution {
public:
    bool buddyStrings(string A, string B) 
    {
        int lenA = A.size();
        int lenB = B.size();
        
        if(lenA != lenB)
            return false;
        
        if(A == B) // (ab, ab) && (aa, aa) case
        {
            set<char> s(A.begin(), A.end());
            
            if(s.size() < lenB)
               return true;
        }
        
        // we can do only one swap so there can only be 2 positions where the characters of both strings are different
        vector<int> v;
        
        for(int i = 0; i < lenA; i++)
        {
            if(A[i] != B[i])
                v.push_back(i); // push the index where they are different
            
            if(v.size() > 2)
                return false;
        }
        
        if(v.size() == 2 && A[v[0]] == B[v[1]] && A[v[1]] == B[v[0]])
            return true;
        
        return false;
    }
};