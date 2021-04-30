#include "cstdlib"
#include "stdio.h"
#include <iostream>
#include "cmath"


using namespace std;


//程序员爬楼梯

typedef long long ll;
ll ans, n;

void dfs(ll k){
    if(k==n){
        ans++;
        return;
    }else if(k>n){
        return;
    }
    dfs(k+1);
    dfs(k+3);
}

int main(){
    while (cin>>n){
        ans=0;
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}


/*
// 模拟树的思维

int p[10]={0};
bool vis[10]={0};
int n;

void dfs(int x){
    if(x==n+1){
        for(int i=1; i<=n; i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1; i<=n; i++){
        if(vis[i] == false){
            p[x] = i;
            vis[i] = true;
            dfs(x+1);
            vis[i] = false;
        }
    }
}

int main(){
    while (cin>>n){
        dfs(1);
    }
    return 0;
}

*/

//const int maxn = 105;
//
// 矩阵的
//int n,m;
//
//int org[maxn][maxn] = {0};
//int ker[3][3]={0};
//int ans[maxn][maxn] = {0};

/*
// 二叉树的基本创建

//树的结点
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;

//树根
typedef struct {
    Node *root;
} Tree;

//创建树 -- 插入数据
void insert(Tree *tree, int value){
    //创建一个节点， 让左右指针全部指向为空，数据为value
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    //判断树是不是空树，如果是，直接让树根指向这一个结点即可
    if(tree->root == NULL){
        tree->root = node;
    }else{
        //不是空树
        Node *temp = tree->root; //从树根开始
        while (temp != NULL){
            if(value < temp->data) {
                //小于就进左儿子
                if(temp->left == NULL){
                    temp->left = node;
                    return;
                }else{
                    // 继续往下搜寻
                    temp = temp->left;
                }
            }else{
                // 否则进右儿子
                if(temp->right == NULL){
                    temp->right = node;
                    return;
                }else{
                    //继续往下搜索
                    temp = temp->right;
                }
            }
        }
    }
}

//树的中序遍历 In-order traversal
void inorder(Node* node){
    if(node != NULL){
        inorder(node->left);
        printf("%d", node->data);
        inorder(node->right);
    }
}

int main(){
    Tree tree;
    //创建一个空树
    tree.root = NULL;
    int n;
    scanf("%d", &n);

    //输入n个数并创建这个树
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        insert(&tree, temp);
    }
    inorder(tree.root); //中序遍历
    return 0;
}

*/

/*int main() {

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



    //矩阵 3*3 代码样列为

    cin >> n >> m;

    //待处理的矩阵
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> org[i][j];
        }
    }

    //直接以倒置的方法进行输入
    for(int i=2; i>=0; i--){
        cin >> ker[i][2] >> ker[i][1] >> ker[i][0];
    }

    //卷积运算
    for(int i=1; i<n; i++){
        for(int j=1; j<=m; j++){
            int tmp=0;
            for(int a=0; a<3; a++){
                for(int b=0; b<3; b++){
                    tmp +=(ker[a][b] * org[i-1+a][j-1+b]);
                }
            }
            ans[i][j]=tmp;
        }
    }

    //结果输出
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;

}
*/