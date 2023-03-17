#include <bits/stdc++.h>
using namespace std;
vector<int>s;
vector<deque<pair<int,int>>>deques;
int main(){
    s.push_back(0);
    deques.emplace_back();
    deques[0].push_back({0,0});
    while(true){
        int l;
        cin>>l;
        if(l<0)break;
        s.push_back(s.back()+l);
        deques.emplace_back();
        for(int i = 0;i<s.size()-1;i++){
            int x = -1,y = -1;
            while(!deques[i].empty() and deques[i].front().first+s[i]<s.back()){
                x = deques[i].front().first;
                y = deques[i].front().second;
                deques[i].pop_front();
            }
            if(x != -1 and y != -1){
                deques[i].push_front({x,y});
                auto &dq = deques.back();
                while(!dq.empty() and dq.back().first>=y){
                    dq.pop_back();
                }
                dq.push_back({y,s.back()-s[i]});
            }
        }
        for(auto a:deques.back()){
            cout<<"("<<a.second<<","<<a.first<<") ";
        }
        cout<<"\n";
    }
    return 0;
}

