// https://www.youtube.com/watch?v=1LkOrc-Le-Y

class MedianFinder {
public:
    priority_queue<int> maxH; // left half
    priority_queue<int, vector<int>, greater<int>> minH; // right half
    
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        int lsize = maxH.size();
        int rsize = minH.size();
        
        if(lsize == 0) // 1st element
        {
            maxH.push(num);
        }
        else if(lsize == rsize) // even case, put the new element in max heap
        {
            if(num < minH.top())
                maxH.push(num);
            else
            {
                int temp = minH.top();
                minH.pop();
                minH.push(num);
                maxH.push(temp);
            }
        }
        else
        {
            if(minH.size() == 0) // 2nd element is to be inserted
            {
                if(num > maxH.top())
                    minH.push(num);
                else
                {
                    int temp = maxH.top();
                    maxH.pop();
                    maxH.push(num);
                    minH.push(temp);
                }
            }
            else if(num >= minH.top())
                minH.push(num);
            else
            {
                if(num < maxH.top())
                {
                    int temp = maxH.top();
                    maxH.pop();
                    maxH.push(num);
                    minH.push(temp);
                }
                else
                {
                    minH.push(num);
                }
            }
        }
    }
      
    double findMedian() 
    {
        int lsize = maxH.size();
        int rsize = minH.size();
        
        if(lsize > rsize) // odd case
        {
            return double(maxH.top());            
        }
        else
        {
            return (double(maxH.top()) + double(minH.top())) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */