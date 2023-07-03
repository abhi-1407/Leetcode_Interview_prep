class Solution {
    bool helper(vector<int> &cookies, int maxLimit,int maxChild)
    {
        do
        {
            int child = 1;
            int currLimit = 0;
            int n = cookies.size();
            for(int i=0;i<n;i++)
            {
                if(currLimit + cookies[i] > maxLimit)
                {
                    child++;
                    currLimit = cookies[i];
                    
                    if(currLimit > maxLimit)
                        return false;
                }
                else
                    currLimit += cookies[i];
            }
            if(child <= maxChild)
                return true;
        }while(next_permutation(cookies.begin(), cookies.end()));
        return false;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int i=0,j=0,ans=-1;
        for(auto it:cookies)
        {
            j+=it;
        }
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(helper(cookies,mid,k))
            {
                ans=mid;
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans;
    }
};