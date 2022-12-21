/* Simply imagine a double ended queue in which the elements are stored in dec order:

1)Suppose the queue is something like: 6,4,2 and now you have to push in 5 , so you have to do it from the back.
2)When checking for out of bound elements,you have to check from the front.
3)You would be ready to take ans in consideration only when i>=k-1(as at i==k-1, you'll hit the first window)
*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty() && dq.front()==i-k) //check for out of bound elements
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i])//placing an element from the back
                dq.pop_back();
            dq.push_back(i);//now place the element
            if(i>=k-1)//we are now ready to start taking elements into consideration
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};