class Solution {
public:
    int diff(string& q, string& d){
        int n = q.size();
        int cnt  = 0;
        for(int i = 0; i < n; i++){
            if(q[i] != d[i]) cnt++;
            if(cnt > 2) return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for(auto& q : queries){
            for(auto& d : dictionary){
                if(diff(q,d)){
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};