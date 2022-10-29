class Solution {
public:
    bool isPalindrome(string s) {
//         int flag=0;
//         int l=0;
//         int n=s.size();
//         string p;
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]>='A' && s[i]<='Z')
//                 p+=s[i]+32;
//             else if((s[i]>='a'&&s[i]<='z') || (s[i]>='0' && s[i]<='9'))
//             {
//                 p+=s[i];
//             }
//         }
            
//         string q=p;
//         reverse(q.begin(),q.end());
//         if(p==q)
//             return true;
//         else 
//             return false;
                int i=0;
        int j=s.length()-1;
        while(i<=j){         
        while(!((s[i]>='A' && s[i]<='Z')|| (s[i]>='a'&&s[i]<='z') ||(s[i]>='0' && s[i]<='9')) &&i<j) {
                i++;
            }
        while(!((s[j]>='A' && s[j]<='Z')|| (s[j]>='a'&&s[j]<='z') ||(s[j]>='0' && s[j]<='9')) &&i<j) {
                j--;
            }
         if (s[i]==s[j]||((s[i]+32==s[j]||s[i]==s[j]+32)&&((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z'))&&((s[j]>='A' && s[j]<='Z')||(s[j]>='a' && s[j]<='z')))){
                i++;
                j--;}  
            else 
                return 0;
        }
            
       return 1;
        
    }
};