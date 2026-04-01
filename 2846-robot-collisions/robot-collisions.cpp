class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        //
        vector<pair<pair<int,int>, pair<int,char>>> nums;

        int n = pos.size();
        for(int i = 0; i < n; i++){
            nums.push_back({{pos[i],i+1},{h[i],d[i]}});
        }

        sort(nums.begin(),nums.end());

        stack<pair<pair<int,int>, pair<int,char>>> st;
        vector<pair<int,int>> temp;
        int i = 0;
        while(i<n){
            if(nums[i].second.second == 'R') st.push(nums[i]);
            else {
                if(!st.empty()){
                    auto it = st.top();
                    st.pop();
                    if(it.second.first > nums[i].second.first){
                        it.second.first--;
                        st.push(it);
                    }
                    else if(it.second.first < nums[i].second.first){
                        nums[i].second.first--;
                        i--;
                    }
                    else{
                        
                    }
                    
                }
                else{
                    temp.push_back({nums[i].first.second, nums[i].second.first});
                }
            }
            i++;
        }
        while(!st.empty()){
            auto it = st.top();
            st.pop();

            temp.push_back({it.first.second, it.second.first});
        }
        sort(temp.begin(),temp.end());

        vector<int> ans;
        for(auto& it : temp){
            ans.push_back(it.second);
        }
        return ans;
    }
};