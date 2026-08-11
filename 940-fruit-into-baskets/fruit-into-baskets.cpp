class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mpp;

        int i = 0, j = 0;
        int len = 0;
        while(j < n){
            mpp[fruits[j]]++;
            while(mpp.size() > 2){
                mpp[fruits[i]]--;
                
                    
                    if(mpp[fruits[i]]==0) mpp.erase(fruits[i]);
                
                i++;
            }
            len = max(len, j-i+1);
            
            j++;
        }
        return len;

    }
};