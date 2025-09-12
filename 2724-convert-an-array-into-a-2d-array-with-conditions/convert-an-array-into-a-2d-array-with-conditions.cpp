class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        for ( auto it : nums){
            mpp[it]++;
        }
       

        vector<vector<int>> res;

        while(!mpp.empty()){
            vector<int> tmp;
            for (auto it = mpp.begin(); it != mpp.end(); ) {
                tmp.push_back(it->first);
               
                if (--(it->second) == 0) {
                    it = mpp.erase(it); 
                } else {
                    ++it;
                }
            }
            res.push_back(tmp);
        }
       
        return res;
    }
};