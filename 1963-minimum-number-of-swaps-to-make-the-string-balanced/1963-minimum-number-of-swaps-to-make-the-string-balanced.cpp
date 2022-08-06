class Solution {
public:
    
//     int minSwaps(string s) {
//       int count=0,maxcount=0;
//       for(int i=0;i<s.length();i++)
//       {
//           if(s[i]==']')
//               count++;
//           else 
//               count--;
//           maxcount=max(maxcount,count);
//       }
//       return (maxcount+1)/2;
//     }
//      int minSwaps(string s) {
//       stack<char> st;
//       for(int i=0;i<s.length();i++)
//       {
//           if(s[i]=='[' )
//               st.push(s[i]);
//           else  
//           {
//               if(!st.empty() && st.top()=='[')
//                   st.pop();
//               else
//                   st.push(s[i]);
//           }
//       }
//       float a=0,b=0;
//       while(!st.empty())
//       {
//           if(st.top()=='[')
//               a++;
//           else
//               b++;
//           st.pop();
//       }
//       if(a<=b)
//           return (b-a)/2+ceil(a/2);
//        else
//           return (a-b)/2+ceil(a/2);
//      }
    int minSwaps(string s) {
        
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]==']' and st.size()){
                if(st.top()=='[')
                    st.pop();
            }
            else
                st.push(s[i]);
        }
        return st.size()/2;
        
    }
};