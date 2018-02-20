#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
 {
  ll visited[50][50],n,m,t,i,j,count,x,y;
  char mat[50][50];
  cin>>t;
  while(t--)
  {
    queue< pair<ll,ll> > q;
      cin>>n>>m;
      for(i=0;i<n;i++)
          for(j=0;j<m;j++)
          {   
              cin>>mat[i][j];
              visited[i][j] = 0;
              if(mat[i][j] == 'O') visited[i][j] = 1;
          }

          count = 0;

      for(i=0;i<n;i++) {
          for(j=0;j<m;j++) {
            if(mat[i][j] == 'X' && visited[i][j] == 0) {
              q.push({i,j});
              visited[i][j] = 1;
              while(!q.empty()) {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                if( x>0 && (mat[x-1][y] == 'X' && visited[x-1][y] == 0)) { visited[x-1][y] = 1; q.push({x-1,y});  }
                if( y>0 && (mat[x][y-1] == 'X' && visited[x][y-1] == 0)) { visited[x][y-1] = 1; q.push({x,y-1});  }
                if( x<(n-1) && (mat[x+1][y] == 'X' && visited[x+1][y] == 0)) { visited[x+1][y] = 1; q.push({x+1,y});  }
                if( y<(m-1) && (mat[x][y+1] == 'X' && visited[x][y+1] == 0)) { visited[x][y+1] = 1; q.push({x,y+1});  }
              }
              count++;
            }
          }
      }
      cout<<count<<endl;
  }
  return 0;
}