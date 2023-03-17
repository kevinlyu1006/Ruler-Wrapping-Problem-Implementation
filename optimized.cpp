


#include <bits/stdc++.h>
using namespace std;

struct Item{
    int w,h,id;
};
vector<int>inputs;
vector<int>s;
vector<deque<Item>>deques;
vector<pair<int,int>>pos; // prev, nxt

int main(){
    s.push_back(0);
    deques.emplace_back();
    deques[0].push_back({0,0,0});
    pos.push_back({-1,-1});
    int p = 0;
    while(true){
        int l;
        cin>>l;
        if(l<0)break;
        s.push_back(s.back()+l);
        int id = deques.size();
        deques.emplace_back();
        pos.back().second = id;
        pos.push_back({id-1,-1});
        int p = 0;
        while(p!=-1){
            auto &prevDq = deques[p];
            int x = -1,y = -1,preId = -1;
            while(!prevDq.empty() and prevDq.front().w+s[p]<s.back()){
                x = prevDq.front().w;
                y = prevDq.front().h;
                preId = p;
                prevDq.pop_front();
            }
            if(x != -1 and y != -1){
                prevDq.push_front({x,y});
                auto &dq = deques.back();
                while(!dq.empty() and dq.back().w>=y){
                    int idd = dq.back().id;
                    deques[idd].pop_front();
                    if(deques[idd].empty()){
                        pos[pos[idd].first].second = pos[idd].second;
                        pos[pos[idd].second].first = pos[idd].first;
                    }
                    dq.pop_back();
                }
                dq.push_back({y,s.back()-s[p],preId});
            }
            p = pos[p].second;
        }
        for(auto a:deques.back()){
            cout<<"("<<a.h<<","<<a.w<<") ";
        }
        cout<<"\n";
    }
    return 0;
}

