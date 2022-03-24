/*
    1. Sort the Vector.
    2. We can make the lightest & heaviest person to go together.
    3. using Two pointer appraoch i is the lightest person & j is the heaviest.
    4. Traversing till start <= end.
    5. if sum of lightest & heaviest person are under limit then both can go together , updating i & j both.
    6. If sum exceeds the limit, then heaviest person will go alone, hence updating only the j pointer.
    7. increment the count .
    8. Return cnt.
*/



class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        // sort vector
        sort(people.begin(),people.end());
        
        int i = 0, j = people.size() - 1, boats = 0;
        
        while(i <= j)
        {   
            // lightest person + heaviest person sum <= limit
            // they can go together
            if(people[i] + people[j] <= limit)
            {
                ++i;
                --j;
            }
            // if sum is over the limit,
            // heaviest will go alone.
            else
                --j;
            
            ++boats;  // number of boats
        }
        
        return boats;
                
    }
};