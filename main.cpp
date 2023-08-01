#include <iostream>
#include <fstream>
#include<vector>
#include <queue>
using namespace std;

typedef pair <int,int>ii;
typedef pair <int,bool>ib;
int main()
{
    ifstream fin;
    fin.open("uvaprinterqueue.txt");
    if(!fin){
        cerr<<"error"<<endl;
        return 1;
    }
    int TC,n,m,id;
    int priority[100];

    vector<ib>v;
    fin>>TC;
    while(TC--){
        fin>>n>>m;
        v.assign(n,ib(0,0));
        for(int i=0;i<n;i++){
            fin>>priority[i]>>v[i].first;
            if(priority[i]==m) v[i].second=true;
            else v[i].second=false;
        }
            int t=0;
             int sum=0;
int sum1 =0;

            queue<ib>q;
            queue<int>q1,q2;
            priority_queue<int>pq,pq1,pq3;
        for(int i=0;i<n;i++){
            q.push(v[i]);
q1.push(priority[i]);
            pq.push(v[i].first);
sum1+=v[i].first;
        }
        while(!q.empty() && !q1.empty()){
            if(q.front().first<pq.top()){
                q.push(q.front());
                q1.push(q1.front());

                q.pop();
                q1.pop();
            }else{
            t++;
sum+=q.front().first;
            q2.push(q1.front());
            q1.pop();
            if(q.front().second) break;
            q.pop();
            pq.pop();
            }
        }
        while(!q1.empty()){
               q2.push(q1.front());
            q1.pop();
             q.pop();
            pq.pop();
        }
         while(!q2.empty()){
                cout<<q2.front()<<" ";
            q2.pop();
        }
     double x=(sum1+q.front().first)/2;
cout<<";"<<sum<<" ; "<<x<<endl;

        v.clear();
        while(!q.empty()){
            q.pop();
        }
        while(!pq.empty()){
            pq.pop();
        }

    }


    return 0;
}
