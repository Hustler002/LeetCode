class Solution {
public:
    struct hash_pair {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        unordered_set<pair<int,int>, hash_pair> st;
        for(auto& it : obstacles) st.insert({it[0], it[1]});
        int x = 0, y = 0;
        int maxi = INT_MIN;
        int dir = 0;
        for(auto& it : commands){
            if(it>= 1 && it <= 9){
                if(dir == 0){

                    while(it--){
                        y++;
                        if(st.find({x, y}) != st.end()) {y--; break;}
                        
                    }
                }
                else if(dir == 2){
                    while(it--){
                        y--;
                        if(st.find({x, y}) != st.end()) {y++; break;}
                        
                    }
                }
                else if(dir == 1){
                    while(it--){
                        x++;
                        if(st.find({x, y}) != st.end()) {x--; break;}
                        
                    }
                }
                else if(dir == 3){
                    while(it--){
                        x--;
                        if(st.find({x, y}) != st.end()) {x++; break;}
                    }
                }
            }
            else if(it == -1){
                dir = (dir + 1) % 4;
            }
            else if(it == -2){
                dir = ((dir - 1) + 4) % 4;
            }
            //cout<<x<<" "<<y<< " dir-"<<dir<<endl;
            
            int dist = (x*x)+(y*y);
            maxi = max(maxi,dist);
        }
        return maxi;
    }
};