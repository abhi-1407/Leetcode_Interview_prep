class Solution {
public:
    long isPalim(long num, bool even){
        long result = num;

        if(even == false){
            num/=10;
        }

        while(num>0){
            long temp = num%10;
            result = result * 10 + temp;
            num/=10;
        }
        return result;
    }

    string nearestPalindromic(string n) {
        int size = n.size();

        int mid = size/2;

        int firstHalf = (size%2==0) ? mid : mid+1;

        long firstHaflNumber = stol(n.substr(0,firstHalf));

        vector<long> permutations;

        permutations.push_back(isPalim(firstHaflNumber, size%2==0));
        permutations.push_back(isPalim(firstHaflNumber-1, size%2==0));
        permutations.push_back(isPalim(firstHaflNumber+1, size%2==0));
        permutations.push_back(pow(10,size)+1);
        permutations.push_back(pow(10,size-1) - 1);

        long result = -1;
        int diff = INT_MAX;
        long originalValue = stol(n);
        

        for(long i : permutations){
            if(i==originalValue)continue;
            if(abs(originalValue-i) < diff){
                result = i;
                diff = abs(originalValue-i);
            }else if(abs(originalValue-i) == diff){
                result = min(i,result);
            }
        }

        return to_string(result);

    }
};