#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int n,m,p;
char k;
int g;
vector<int>value;
vector<int>graf[1000002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("plik.in","r",stdin);
    freopen("plik.out","w",stdout);
    cin>>n>>m;
    p=n*m;
    cout<<p<<endl;
    int licznik=0;
    //int wiersz=1;
    
    //środek
    for(int i=2;i<n;i++)
    {
        for(int j=2;j<m;j++)
        {
            graf[(i-1)*m+j].push_back((i-2)*m+j);
            graf[(i-1)*m+j].push_back((i)*m+j);
            graf[(i-1)*m+j].push_back((i-1)*m+j-1);
            graf[(i-1)*m+j].push_back((i-1)*m+j+1);

        }
    }
    
    //ramki
    //pierwsza poziom
    for(int i=2;i<m;i++)
    {
        graf[i].push_back(m+i);
        graf[i].push_back(i-1);
        graf[i].push_back(1+i);
    }
    //ostatnia poziom
    for(int i=((n-1)*m+2);i<n*m;i++)
    {
        graf[i].push_back(i-m);

        graf[i].push_back(i-1);
        graf[i].push_back(1+i);
    }
    //pion lewy
    
    for(int i=2;i<n;i++)
    {
        graf[(i-1)*m+1].push_back((i-1)*m+1-m);
        graf[(i-1)*m+1].push_back((i-1)*m+1+m);
        graf[(i-1)*m+1].push_back((i-1)*m+2);
    }
    //pion prawy
    for(int i=2;i<n;i++)
    {
        graf[i*m].push_back(i*m-1);
        graf[i*m].push_back(i*m-m);
        graf[i*m].push_back(i*m+m);
    }
    //naroznik LU
    graf[1].push_back(2);
    graf[1].push_back(1+m);
    //narożnik RD
    graf[n*m].push_back(n*m-1);
    graf[n*m].push_back(n*m-m);
    //narożnik LD
    graf[n*m-m+1].push_back(n*m-m+2);
    graf[n*m-m+1].push_back(n*m-m-m+1);
    //naroznik RU
    graf[m].push_back(2*m);
    graf[m].push_back(m-1);
    
    /*
    //elo
    for(int i=0;i<p;i++)
    {
        vector<int> przy;
        
        if(wiersz<n)
        {
           przy.push_back(i+m);
                   
       }
        if(licznik<(m-1))        {
            przy.push_back(i+1);
            licznik++;
        }
        else
        {
            licznik=0;
            wiersz++;
        }
       graf.push_back(przy);
       przy.erase(przy.begin(),przy.end());
        
    }
    */
    for(int i=0;i<p;i++)
    {
        cin>>k;
        if(k=='0')
        {
            value.push_back(INF);
        }
        else
        {
            value.push_back(0);
        }
        
    }
    //wyświetl
    licznik=0;
    for(int i=0;i<p;i++)
    {
        
        if(licznik<m)
        {
            cout<<value[i]<<" ";
            licznik++;

        }
        else
        {
            licznik=1;
            cout<<endl;
            cout<<value[i]<<" ";
        }
        
    
        
        
    }
    
    cout<<endl<<"tabelka"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<i*m+j<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl<<"połączenia"<<endl;
    for(int i=0;i<=p;i++)
    {
        cout<<i<<": ";
        for(int j=0;j<graf[i].size();j++)
        {
            cout<<graf[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}