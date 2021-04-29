#include <iostream>

using namespace std;

const int maxn = 505;

int a[maxn][maxn];
int b[maxn][maxn];
int ans[maxn][maxn];


int main() {
    //矩阵加法
    int n,m;
    cin >>n >>m;

    //输入a
    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    //输入b
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }

    //相减
    for(int i=0; i<n ;i++){
        for(int j=0; j<m; j++){
            ans[i][j]=a[i][j]-b[i][j];
        }
    }

    //输出
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;



    //std::cout << "Hello, World!" << std::endl;

    //return 0;
}
