class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> ans(n,0);
        int index = n - 1;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            }
            if(st.empty()){
                ans[index] = prices[i];
            }else{
                ans[index] = prices[i] - st.top();
            }
            st.push(prices[i]);
            index--;
        }
        return ans;
        
    }
};



