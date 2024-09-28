#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int arr[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int main(){
    cin>>n>>m;

    int sum = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            sum += (4*arr[i][j] + 2);            
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(InRange(nx,ny)){
                    int num = arr[nx][ny];
                    num = min(num, arr[i][j]);
                    sum -= num;
                }
            }
        }
    }

    cout<<sum;
    return 0;
}
