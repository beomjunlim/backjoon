#include<iostream>
#include<algorithm>
using namespace std;

int n,m,x,y,k;
int arr[21][21];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int dice[6]; // 0 left 1 up 2 right 3 front 4 down 5 back

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int main(){
    cin>>n>>m>>x>>y>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int a=0; a<k; a++){
        int num;
        cin>>num;
        num--;

        int nx = x + dx[num];
        int ny = y + dy[num];

        if(InRange(nx,ny)){

            if(num==0){
                int tmp = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[2];
                dice[2] = dice[1];
                dice[1] = tmp;
            }
            else if(num==1){
                int tmp = dice[0];
                dice[0] = dice[1];
                dice[1] = dice[2];
                dice[2] = dice[4];
                dice[4] = tmp;
            }
            else if(num==2){
                int tmp = dice[1];
                dice[1] = dice[3];
                dice[3] = dice[4];
                dice[4] = dice[5];
                dice[5] = tmp;
            }
            else if(num==3){
                int tmp = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[4];
                dice[4] = dice[3];
                dice[3] = tmp;
            }
            x = nx;
            y = ny;
            cout<<dice[1]<<'\n';

            if(arr[x][y]==0)
                arr[x][y] = dice[4];
            else{
                dice[4] = arr[x][y];
                arr[x][y] = 0;
            }
        }
    }
    return 0;
}
