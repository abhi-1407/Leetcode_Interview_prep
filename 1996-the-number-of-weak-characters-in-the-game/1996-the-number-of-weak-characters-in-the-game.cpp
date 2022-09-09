class Solution {
static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        
        int n = arr.size();
        
        // sort the arr
        
        sort(arr.begin(), arr.end(), compare);
        
        int count = 0;
        
        // max_defence will keep track of maximum defence from last
        
        int max_defence = arr[n - 1][1];
        
        for(int i = n - 2; i >= 0; i--)
        {
		    // if curr_defence is less than max_defence
			
            if(arr[i][1] < max_defence)
            {
                count++;
            }
            
            // update max_defence
            
            max_defence = max(max_defence, arr[i][1]);
        }
        
        return count;
    }

};