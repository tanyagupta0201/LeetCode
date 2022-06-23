/*
    1) sort array according to end dates in ascending order
    2) take maxheap to store the durations
    3) iterate over the input and try to minimize the endtime while maximize the courses
    4) number of courses completed == size of priority queue

*/


bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        sort(courses.begin(), courses.end(), cmp);
        
        priority_queue<int> pq;
        int time = 0;
        
        for(auto c : courses)
        {
            int duration = c[0];
            int endDay = c[1];
            
            if(time + duration <= endDay)
            {
                time = time + duration;
                pq.push(duration);
            }
            else
            {
                if(pq.size() > 0 && pq.top() > duration)
                {
                    // max duration wala course nikaal do
                    time = time - pq.top();
                    pq.pop();
                    
                    // current course push kardo
                    pq.push(duration);
                    time = time + duration;
                }
            }
        }
        
        return pq.size();        
    }
};