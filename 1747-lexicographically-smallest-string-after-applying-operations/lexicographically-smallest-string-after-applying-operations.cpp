class Solution {
public:
    string add(string s, int a){
        for(int i = 0; i < s.size(); i++){
            if(i%2==0) continue;
            
            s[i] = ((s[i]-'0' + a)%10) + '0';
        }
        return s;
    }
    string rotate(string s, int b){
        string sub = s.substr(0,b);
        s.erase(0,b);
        //cout<<s;
        s = s+sub;
        return s;
    }
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);
        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr < ans){
                ans = curr;
            }
            // add operation
            string temp = add(curr,a);
            if(vis.find(temp) ==vis.end()) {
                q.push(temp);
                vis.insert(temp);
            }

            //rotate operation
            temp = rotate(curr,b);
            if(vis.find(temp) == vis.end()) {
                q.push(temp);
                vis.insert(temp);
            }
            
        }
        return ans;
    }
};