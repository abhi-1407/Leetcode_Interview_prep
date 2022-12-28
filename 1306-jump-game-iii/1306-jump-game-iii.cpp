class Solution {
    bool helper(vector<int> &arr,int index,vector<bool> &visited)
    {
        if(index>arr.size()-1 || index<0)
            return false;
        if(arr[index]==0)
            return true;
        if(!visited[index])
        {
            visited[index]=true;
            if((helper(arr,index+arr[index],visited)||helper(arr,index-arr[index],visited)))
            return true;
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        vector<bool> visited(n,0);
        return helper(arr,start,visited);
        
    }
};