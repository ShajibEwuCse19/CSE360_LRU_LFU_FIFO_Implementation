#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl             '\n'

int block  = 3;

int FIFO(vector<int>v, int n)
{
    int hit = 0;
    map<int,int>cnt;
    for(int i=1; i<=block; i++)cnt[i] = v[i-1];

    int l = 1;
    for(int i=block; i<n; i++)
    {
        bool f = true;
        for(auto x : cnt)if(v[i]==x.second)f = false;
        if(f)
        {
            cnt[l] = v[i];
            l++;
            if(l==block+1)l=1;
        }
        else hit++;
    }


    return hit;
}

int LRU(vector<int>v, int n)
{
    int hit = 0;
    deque<int>q;
    for(int i=0; i<block; i++)q.push_back(v[i]);

    for(int i=block; i<n; i++)
    {
        bool f = true;
        for(auto it=q.begin(); it!=q.end(); it++)
        {
            if(v[i] == *it)
            {
                f=false;
                q.erase(it);
                break;
            }
        }
        if(f and !q.empty())q.pop_front();
        else hit++;

        q.push_back(v[i]);
    }


    return hit;
}

int LFU(vector<int>v, int n)
{
    int hit = 0;
    deque<int>q;
    map<int,int>cnt;
    for(int i=0; i<block; i++)q.push_back(v[i]);
    for(int i=0; i<n; i++)cnt[v[i]]=0;



    for(int i=block; i<n; i++)
    {
        bool f = true;
        for(auto it=q.begin(); it!=q.end(); it++)
        {
            if(v[i] == *it)
            {
                f=false;
                cnt[v[i]]++;
                break;
            }
        }
        int mn=1e9;
        for(auto it=q.begin(); it!=q.end(); it++)
        {
            if(cnt[*it]<mn)mn = cnt[*it];
        }

        if(!f)hit++;
        else
        {
            for(auto it=q.begin(); it!=q.end(); it++)
            {
                if(cnt[*it]==mn)q.erase(it);break;
            }

            q.push_back(v[i]);
        }
    }


    return hit;
}

int main()
{
    FAST;
    vector<int>v1(1000);
    ifstream file4("4.txt");
    if(file4.is_open()){
        for(int i=0; i<1000; i++)v1[i] = rand()%11;
        int fifo = FIFO(v1,1000);
        int lru  = LRU(v1,1000);
        int lfu  = LFU(v1,1000);
        cout<<"Total Hit for 1st 1000 numbers, FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
        cout<<"Total Miss for first 1000 numbers, FIFO = "<<1000-fifo<<" LRU = "<<1000-lru<<" LFU = "<<1000-lfu<<endl;
    }cout<<endl<<endl;

    vector<int>v2(2000);
    if(file4.is_open()){
        int idx=0;
        for(int i=0; i<2000; i++)v2[idx++] = rand()%11;
        int fifo = FIFO(v2,2000);
        int lru  = LRU(v2,2000);
        int lfu  = LFU(v2,2000);
        cout<<"Total Hit for 2000 numbers, FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
        cout<<"Total Miss for 2000 numbers, FIFO = "<<2000-fifo<<" LRU = "<<2000-lru<<" LFU = "<<2000-lfu<<endl;
    }cout<<endl<<endl;

    vector<int>v3(3000);
    if(file4.is_open()){
        int idx=0;
        for(int i=0; i<3000; i++)v3[idx++] = rand()%11;
        int fifo = FIFO(v3,3000);
        int lru  = LRU(v3,3000);
        int lfu  = LFU(v3,3000);
        cout<<"Total Hit for 3000 numbers, FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
        cout<<"Total Miss for 3000 numbers, FIFO = "<<3000-fifo<<" LRU = "<<3000-lru<<" LFU = "<<3000-lfu<<endl;
    }cout<<endl<<endl;

    vector<int>v4(4000);
    if(file4.is_open()){
        int idx=0;
        for(int i=0; i<4000; i++)v4[idx++] = rand()%11;
        int fifo = FIFO(v4,4000);
        int lru  = LRU(v4,4000);
        int lfu  = LFU(v4,4000);
        cout<<"Total Hit for 4000 numbers, FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
        cout<<"Total Miss for 4000 numbers, FIFO = "<<4000-fifo<<" LRU = "<<4000-lru<<" LFU = "<<4000-lfu<<endl;
    }cout<<endl<<endl;

    vector<int>v5(5000);
    if(file4.is_open()){
        int idx=0;
        for(int i=0; i<5000; i++)v5[idx++] = rand()%11;
        int fifo = FIFO(v5,5000);
        int lru  = LRU(v5,5000);
        int lfu  = LFU(v5,5000);
        cout<<"Total Hit for 5000 numbers, FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
        cout<<"Total Miss for 5000 numbers, FIFO = "<<5000-fifo<<" LRU = "<<5000-lru<<" LFU = "<<5000-lfu<<endl;
    }cout<<endl<<endl;

    vector<int>v6(6000);
    if(file4.is_open()){
        int idx=0;
        for(int i=0; i<6000; i++)v6[idx++] = rand()%11;
        int fifo = FIFO(v6,6000);
        int lru  = LRU(v6,6000);
        int lfu  = LFU(v6,6000);
        cout<<"Total Hit for 6000 numbers, FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
        cout<<"Total Miss for 6000 numbers, FIFO = "<<6000-fifo<<" LRU = "<<6000-lru<<" LFU = "<<6000-lfu<<endl;
    }cout<<endl<<endl;

    vector<int>v7(7000);
    if(file4.is_open()){
        int idx=0;
        for(int i=0; i<7000; i++)v7[idx++] = rand()%11;
        int fifo = FIFO(v7,7000);
        int lru  = LRU(v7,7000);
        int lfu  = LFU(v7,7000);
        cout<<"Total Hit for 7000 numbers, FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
        cout<<"Total Miss for 7000 numbers, FIFO = "<<7000-fifo<<" LRU = "<<7000-lru<<" LFU = "<<7000-lfu<<endl;
    }cout<<endl<<endl;

    vector<int>v8(8000);
    if(file4.is_open()){
        int idx=0;
        for(int i=0; i<8000; i++)v8[idx++] = rand()%11;
        int fifo = FIFO(v8,8000);
        int lru  = LRU(v8,8000);
        int lfu  = LFU(v8,8000);
        cout<<"Total Hit for 8000 numbers, FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
        cout<<"Total Miss for 8000 numbers, FIFO = "<<8000-fifo<<" LRU = "<<8000-lru<<" LFU = "<<8000-lfu<<endl;
    }cout<<endl<<endl;

    vector<int>v9(9000);
    if(file4.is_open()){
        int idx=0;
        for(int i=0; i<9000; i++)v9[idx++] = rand()%11;
        int fifo = FIFO(v9,9000);
        int lru  = LRU(v9,9000);
        int lfu  = LFU(v9,9000);
        cout<<"Total Hit for 9000 numbers, FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
        cout<<"Total Miss for 9000 numbers, FIFO = "<<9000-fifo<<" LRU = "<<9000-lru<<" LFU = "<<9000-lfu<<endl;
    }cout<<endl<<endl;

    vector<int>v10(10000);
    if(file4.is_open()){
        int idx=0;
        for(int i=0; i<10000; i++)v10[idx++] = rand()%11;
        int fifo = FIFO(v10,10000);
        int lru  = LRU(v10,10000);
        int lfu  = LFU(v10,10000);
        cout<<"Total Hit for 10000 numbers, FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
        cout<<"Total Miss for 10000 numbers, FIFO = "<<10000-fifo<<" LRU = "<<10000-lru<<" LFU = "<<10000-lfu<<endl;
    }cout<<endl<<endl;

}
