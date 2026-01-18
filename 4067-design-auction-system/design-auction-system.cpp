class AuctionSystem {
public:
    map <int, map<int,int>> mpp;

    map<int, set<pair<int,int>>> pq;
    
    AuctionSystem() {
        //
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        auto it = mpp[itemId].find(userId);
        if(it != mpp[itemId].end()){
            pq[itemId].erase({it->second, userId});
        }
        mpp[itemId][userId] = bidAmount;
        pq[itemId].insert({bidAmount,userId});
        
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        pq[itemId].erase({mpp[itemId][userId], userId});
        mpp[itemId][userId] = newAmount;
        pq[itemId].insert({newAmount,userId});
    }
    
    void removeBid(int userId, int itemId) {
        pq[itemId].erase({mpp[itemId][userId],userId});
        mpp[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        if(pq[itemId].size() == 0)return -1;
        pair<int,int> high = *pq[itemId].rbegin();
        return high.second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */