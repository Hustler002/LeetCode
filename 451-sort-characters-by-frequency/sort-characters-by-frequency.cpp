class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(auto &it : s) mpp[it]++;
        vector<pair<int,char>> freq;
        for(auto& it : mpp) freq.push_back({it.second,it.first});

        sort(freq.rbegin(), freq.rend());

        string res = "";

        for(auto& it : freq) 
            while(it.first--)
                res.push_back(it.second);
        
        return res;
    }
};