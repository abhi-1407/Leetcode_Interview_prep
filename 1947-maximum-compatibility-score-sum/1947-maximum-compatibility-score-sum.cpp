class Solution {
        int compatible(vector<vector<int>> &s,vector<vector<int>> &m,vector<int> &arr)
        {
            int count=0;
            for(int i=0;i<s.size();i++)
            {
                for(int j=0;j<s[arr[i]].size();j++)
                {
                    if(s[i][j]==m[arr[i]][j])
                        count++;
                }
            }
            return count;
        }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size();
        vector<int> arr(n,0);
        for(int i=0;i<arr.size();i++)
            arr[i]=i;
        int maxi=INT_MIN; 
        do
        {
           maxi=max(maxi,compatible(students,mentors,arr));    
        }
        while(next_permutation(arr.begin(),arr.end()));
        return maxi;
    }
};