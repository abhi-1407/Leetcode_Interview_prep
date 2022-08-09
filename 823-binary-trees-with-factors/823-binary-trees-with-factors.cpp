class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int ,long long int> mpp;
        sort(arr.begin(),arr.end());//to keep the array in sorted fashion only then could we apply 2 pointer approach
        int mod=pow(10,9)+7;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        for(int i=1;i<arr.size();i++)
        {
            long long int count=0;
            for(int j=0;j<i;j++)
            {
                
                if(arr[i]%arr[j]==0)//if this element is a multiple of the parent
                {
                   int element=arr[i]/arr[j];
                   if(mpp.find(element)!=mpp.end())//see if the other multiple exists in the map
                   {
                       count+=mpp[element]*mpp[arr[j]];//add the value to the count
                   }
                }
            }
            mpp[arr[i]]+=count;//increment the ways of forming this integar by this amount
        }
        long long int ans=0;
        for(auto it:mpp)
        {
            ans+=it.second;//add all the frequencies
        }
        return ans%mod;//returing ans%mod as values could be very large
    }
};