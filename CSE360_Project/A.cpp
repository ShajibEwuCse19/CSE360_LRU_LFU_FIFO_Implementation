#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl             '\n'

int block  = 10;
int n=1000;
vector<int>v(n);

int FIFO()
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

int LRU()
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
        if(f)q.pop_front();
        else hit++;

        q.push_back(v[i]);
    }


    return hit;
}

int LFU()
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
    int fifo=0, lru=0, lfu = 0;

    ifstream file1("1.txt");
    if(file1.is_open())
    {
        for(int i=0; i<1000; i++)file1 >> v[i];
        fifo += FIFO();
        lru  += LRU();
        lfu  += LFU();
    }

    ifstream file2("2.txt");
    if(file2.is_open())
    {
        for(int i=0; i<1000; i++)file2 >> v[i];
        fifo += FIFO();
        lru  += LRU();
        lfu  += LFU();
    }

    ifstream file3("3.txt");
    if(file3.is_open())
    {
        for(int i=0; i<1000; i++)file3 >> v[i];
        fifo += FIFO();
        lru  += LRU();
        lfu  += LFU();
    }


    cout<<"Total Hit for 3 times in FIFO = "<<fifo<<" LRU = "<<lru<<" LFU = "<<lfu<<endl;
    cout<<"Total Miss for 3 times in FIFO = "<<3000-fifo<<" LRU = "<<3000-lru<<" LFU = "<<3000-lfu<<endl;
    cout<<"Average Hit Value for block "<<block<<" : "<<endl;
    cout<<"FIFO : "<<fixed<<setprecision(2)<<(double)fifo/3.0<<endl;
    cout<<"LRU : "<<fixed<<setprecision(2)<<(double)lru/3.0<<endl;
    cout<<"LFU : "<<fixed<<setprecision(2)<<(double)lfu/3.0<<endl;
}
