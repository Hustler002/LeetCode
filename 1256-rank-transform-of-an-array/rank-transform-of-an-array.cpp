class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        int n = arr.size();
        sort(temp.begin(), temp.end());
        unordered_map<int,int> mpp;
        int rank = 1;
        if(!temp.empty()) mpp[temp[0]] = rank;
        for(int i = 1; i < n; i++){
            if(temp[i-1] != temp[i]) 
                rank++;
            mpp[temp[i]] = rank;
        }

        for(auto& it : arr){
            it = mpp[it];
        }
        return arr;
    }
};