class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char,string> mpp;
        set<string> s;
        mpp['a']=".-";
        mpp['b']="-...";
        mpp['c']="-.-.";
        mpp['d']="-..";
        mpp['e']=".";
        mpp['f']="..-.";
        mpp['g']="--.";
        mpp['h']="....";
        mpp['i']="..";
        mpp['j']=".---";
        mpp['k']="-.-";
        mpp['l']=".-..";
        mpp['m']="--";
        mpp['n']="-.";
        mpp['o']="---";
        mpp['p']=".--.";
        mpp['q']="--.-";
        mpp['r']=".-.";
        mpp['s']="...";
        mpp['t']="-";
        mpp['u']="..-";
        mpp['v']="...-";
        mpp['w']=".--";
        mpp['x']="-..-";
        mpp['y']="-.--";
        mpp['z']="--..";
        for(auto it:words)
        {
           string temp="";
           for(auto i: it)
           {
               temp+=mpp[i];
           }
           s.insert(temp);
        }
        return s.size();
    }
};