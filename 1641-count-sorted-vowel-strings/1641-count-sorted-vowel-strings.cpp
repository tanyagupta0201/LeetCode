class Solution {
public:
    // This question is number of combination with repetition 
    // we have calculated according to that formula which results in the following formula
    int countVowelStrings(int n) 
    {
        return ((n + 1) * (n + 2) * (n + 3) * (n + 4)) / 24;
    }
};