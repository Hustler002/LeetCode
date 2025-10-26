class Solution {
public:
    long long countStableSubarrays(vector<int>& cap) {
        unordered_map<int,vector<int>> mpp;
        int m = cap.size();
        vector<long long> pre(m,0);
        pre[0] = cap[0];
        for(int i = 0; i < cap.size(); i++) {
            mpp[cap[i]].push_back(i);
            if(i!=0) pre[i] = pre[i-1] + cap[i];
        }
        long long cnt = 0;
        for(auto& it : mpp){
            if(it.second.size() > 1){
                vector<int> nums = it.second;
                long long num = it.first;

                unordered_map<long long,int> pref;
                int p = 0;
                for(int j = 0; j < nums.size(); j++){
                    int b = nums[j];
                    if(b==0) continue;
                
                
                while(p < j && nums[p] <= b-2){
                    pref[pre[nums[p]]]++;
                    p++;
                }

                long long target = pre[b-1]-num;
                auto itf = pref.find(target);
                if(itf != pref.end()) cnt += itf->second;
    
                /*for(int i = 0; i < nums.size(); i++){
                    for(int j = i+1; j < nums.size(); j++){
                        if(pre[nums[j]-1] - pre[nums[i]] == num && nums[j]-nums[i] > 1) cnt++;
                    }
                }*/
                }
            }
        }
        return cnt;
        
    }
};