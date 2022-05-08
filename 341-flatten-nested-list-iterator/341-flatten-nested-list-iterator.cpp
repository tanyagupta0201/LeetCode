/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
	//initialize an empty list to save Integers after is flatted
    stack<int> list;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
		//initialize another empty list to save all NestedInteger 
		stack<NestedInteger> nestedList_stack;
        
		//save values of nestedList into nestedList_stack
        for (int i = 0; i < nestedList.size(); i++)
            nestedList_stack.push(nestedList[i]);

		//NOTE because we added values from left to right, now, the top value of nestedList_stack is the last value of nestedList. 
		//iterate all value in nestedList_stack
        while(!nestedList_stack.empty()){
			//get the top value
            auto curr = nestedList_stack.top();
            nestedList_stack.pop();
            
			//if it is an integer, add to list (NOTE because nestedList_stack.top() is the last value, list.top() will be the first value)
           if (curr.isInteger())
                list.push(curr.getInteger());
			//otherwise get list of curr and add it into nestedList_stack, so we can iterate this list after this iteration
			else{
                auto currList = curr.getList();
				//NOTE as before we add value of currList into nestedList_stack from left to right, so the top value will be the last value of curr list
                for (int i = 0; i < currList.size(); i++)
                    nestedList_stack.push(currList[i]);
            }
        }
    }
    
    int next() {
		//get the top value and return
        int res = list.top();
        list.pop();
        
        return res;
    }
    
    bool hasNext() {
		//if list is not empty means that it has next
        return !list.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */