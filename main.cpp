#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "math.h"

//#include<malloc.h>
//#define maxSize 1000
//#define n 20
//#define MaxNum 1000   /*定义一个最大的整数*/

//#define INFINITY 65535  //无边时的权值
//#define MAX_VERTEX_NUM 10   //最大定点数

//#define MAXVEX 9
//#define INFINITY 65535

using namespace std;

// 快速排序
void quick_sort(int a[], int low, int high){
    int i,j,temp;
    i=low;
    j=high;
    if(low<high){
        temp = a[low]; //设置轴
        while (i!=j){
            while (j>i&&a[j]>=temp){
                --j;
            }
            if(i<j){
                a[i]=a[j];
                ++i;
            }
            while (i<j&&a[i]<temp){
                ++i;
            }
            if(i<j){
                a[j]=a[i];
                --j;
            }
        }
        a[i]=temp;
        quick_sort(a, low,i-1);
        quick_sort(a,i+1, high);
    }
}

int main(){
    int a[8] = {70,50,30,20,10,70,40,60};
    int n=8;
    quick_sort(a,0,n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<' ';
    }
    return 0;
}


/*

//归并排序法

void merge(int arr[], int l, int mid, int r){
    //开辟一个新的数组，将原数组映射进去
    int aux[r-l+1];
    for(int m=l; m<=r; m++){
        aux[m-l] = arr[m];
    }
    //i和j分别指向两个子数组开头部分
    int i=l,j=mid+1;

    for(int k=l; k<=r; k++){
        if(i>mid){
            arr[k] = aux[j-l];
            j++;
        }else if(j>r){
            arr[k] = aux[i-l];
            i++;
        }else if(aux[i-l]<aux[j-l]){
            arr[k]=aux[i-l];
            i++;
        }else{
            arr[k]=aux[j-l];
            j++;
        }
    }
}

void merge_sort(int arr[], int n){
    for(int sz=1; sz<=n; sz+=sz){
        for(int i=0;i+sz<n;i+=sz+sz){
           //i+sz防止越界
           //对局部：arr[i...sz-1]和arr[i+sz.....i+2*sz-1]进行排序
           //min函数防止越界
           merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1));
        }
    }
}

int main(){
    int a[8]={70,50,30,20,10,70,40,60};
    int n=8;
    merge_sort(a, n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
*/



/*

//堆排序

// Function:交换交换根节点和数组末尾元素的值
void Swap(int *heap, int len){
    int temp;
    temp = heap[0];
    heap[0] = heap[len-1];
    heap[len-1] = temp;
}

// Function:构建大顶堆
void BuildMaxHeap(int *heap, int len) {
    int i, temp;
    for (i = len / 2 - 1; i >= 0; i--) {
        //根节点大于左子树
        if ((2 * i + 1) < len && heap[i] < heap[2 * i + 1]) {
            temp = heap[i];
            heap[i] = heap[2 * i + 1];
            heap[2 * i + 1] = temp;

            //检查交换后的左子树是否满足大顶堆项性质，如果不满足，则重新调整子树结构
            if ((2 * (2 * i + 1) + 1 < len && heap[2 * i + 1] < heap[2 * (2 * i + 1) + 1]) ||
                (2 * (2 * i + 1) + 2 < len && heap[2 * i + 1] < heap[2 * (2 * i + 1) + 2])) {
                BuildMaxHeap(heap, len);
            }
        }

        if ((2 * i + 2) < len && heap[i] < heap[2 * i + 2]) {
            //根节点大于右子树
            temp = heap[i];
            heap[i] = heap[2 * i + 2];
            heap[2 * i + 2] = temp;
            //检查交换后的右子树是否满足大顶堆性质，如果不满足，则重新调整子树结构
            if ((2 * (2 * i + 2) + 1 < len && heap[2 * i + 2] < heap[2 * (2 * i + 2) + 1]) ||
                (2 * (2 * i + 2) + 2 < len && heap[2 * i + 2] < heap[2 * (2 * i + 2) + 2])) {
                BuildMaxHeap(heap, len);
            }
        }
    }
}


int main(){

    int a[8] = {70,50,30,20,10,70,40,60};

    int n=8;

    int i;

    for(i=n;i>0;i--){
        BuildMaxHeap(a, i);
        Swap(a,i);
    }

    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
*/


/*
//希尔排序
void shellSort(int arr[], int n){
    int i,j,gap;
    for(gap=n/2;gap>0;gap/=2){
        for(i=0;i<gap;i++){
            for(j=i+gap;j<n;j+=gap){
                for(int k=j;k>i&&arr[k]<arr[k-gap];k-=gap){
                    swap(arr[k-gap],arr[k]);
                }
            }
        }
    }
}


int main(){
    int a[8] = {70,50,30,20,10,70,40,60};
    int n=8;
    shellSort(a,n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
*/

/*
// 直接插入排序

void insert_sort(int a[], int n){
    int i,j;
    for(i=1; i<n; i++){
        //循环从第2个元素开始
        if(a[i]<a[i-1]){
            int temp=a[i];
            for(j=i-1;j>=0&&a[j]>temp;j--){
                a[j+1]=a[j];
            }
            a[j+1]=temp; //此处就是a[j+1]=temp;
        }
    }
}


int main(){
    int a[8] = {70,50,30,20,10,70,40,60};
    int n=7;
    insert_sort(a,n);
    for(int i=0; i<=n; i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
*/


/*
// 选择排序
void select_sort(int a[], int n){
    int temp;
    // 利用一个中间变量temp来记录需要交换元素的位置
    for(int i=0; i<n-1; i++){
        temp = i;
        for(int j=i+1;j<n;j++){
            if(a[temp]>a[j]){
                //选出待排数据中的最小值
                temp = j;
            }
        }
        swap(a[i],a[temp]);
    }
}

int main(){
    int a[8] = {2,10,9,4,8,1,6,5};
    int n=8;
    select_sort(a, n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<' ';
    }
    return 0;
}

*/


/*
// 排序的方法 冒泡排序法

template<class T>  //模版类，可以让参数为任意类型

static void swap(T &a, T &b){
    T c(a);
    a=b;
    b=c;
}


 //指定类型

 void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
 }


void bubble_sort(int a[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(a[j]>a[j+1]){
                // 交换数据
                swap(a[j], a[j+1]);
            }
        }
    }
}


int main(){
    int a[8] = {70,50,30,20,10,70,40,60};
    int n=7;
    bubble_sort(a,n);
    for(int i=0; i<=n; i++){
        cout<<a[i]<<' ';
    }
    return 0;
}

*/

/*

// 平衡二叉法排序

//结点设计
typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}BTNode;


int height(struct Node *N){
    if(N == NULL){
        return 0;
    }
    return N->height;
}

int max(int a, int b){
    return (a>b)?a:b;
}

BTNode* newNode(int key){
    struct Node* node = (BTNode*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}


//ll型调整
BTNode* ll_rotate(BTNode* y){
    BTNode *x = y->left;
    y->left = x->right;
    x->right = y;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

//rr型调整
BTNode* rr_rotate(BTNode* y){
    BTNode *x = y->right;
    y->right = x->left;
    x->left = y;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

//判断平衡
int getBalance(BTNode* N){
    if(N == NULL){
        return 0;
    }
    return height(N->left) - height(N->right);
}

//插入结点&数据
BTNode* insert(BTNode* node, int key){
    if(node == NULL){
        return newNode(key);
    }
    if(key < node->key){
        node->left = insert(node->left, key);
    }else if(key < node->key){
        node->right = insert(node->right, key);
    }else{
        return node;
    }

    node->height = 1+max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if(balance>1 && key<node->left->key){ //LL型
        return ll_rotate(node);
    }

    if(balance<-1 && key>node->right->key){ //RR型
        return rr_rotate(node);
    }

    if(balance>1 && key>node->left->key){ // LR型
        node->left = rr_rotate(node->left);
        return ll_rotate(node);
    }

    if(balance<-1 && key<node->right->key){ //RL型
        node->right = ll_rotate(node->right);
        return rr_rotate(node);
    }
    return node;
}

//遍历
void preOrder(struct Node *root){
    if(root != NULL){
        printf("%d", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    BTNode *root = NULL;
    root = insert(root,2);
    root = insert(root,1);
    root = insert(root,0);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,6);
    root = insert(root,9);
    root = insert(root,8);
    root = insert(root,7);

    printf("前序遍历:");
    preOrder(root);
    return 0;
}

*/


/*

// 分块查找
struct index{
    //定义块的结构
    int key;
    int start;
} newIndex[3]; //定义结构体数组

int search(int key, int a[]);

int cmp(const void *a, const void *b){
    return (*(struct index*)a).key>(*(struct index*)b).key?1:-1;
}

int main(){
    int i, j=-1,k,key;
    int a[] = {33,42,44,38,24,48,22,12,13,8,9,20,60,58,74,49,86,53};
    //确实模块的起始值和最大值
    for(i=0;i<3;i++){
        //确定每个块范围的起始值
        newIndex[i].start = j+1;
        j+=6;
        for(int k=newIndex[i].start; k<=j; k++){
            if(newIndex[i].key<a[k]){
                newIndex[i].key = a[k];
            }
        }
    }

    //对结构体按照 key 值进行排序
    qsort(newIndex,3, sizeof(newIndex[0]),cmp);
    //输入要查询的数，并调用函数进行查找
    printf("请输入你想要查找的数:\n");
    scanf("%d", &key);
    k = search(key, a);

    //输出查找的结果
    if(k>0){
        printf("查找成功!你要找的数在数组中的位置是：%d\n",k+1);
    }else{
        printf("查找失败！你要找的数不在数组中.\n");
    }

    return 0;
}

int search(int key, int a[]){
    int i, startValue;
    i=0;
    while (i<3 && key>newIndex[i].key){
        //确定在那个块中，遍历每个块，确定key在那个块中
        i++;
    }

    if(i>=3){
        //大于分得的块数，则返回0
        return -1;
    }
    // startValue等于块范围的起始值
    startValue = newIndex[i].start;
    while (startValue<=startValue+5 && a[startValue]!=key){
        startValue++;
    }
    if(startValue > startValue+5){
        //如果大于块范围的结束值，则说明没有查找的数
        return -1;
    }

    return startValue;

}
*/


/*
//二分查找算法，找不到就返回-1，找到了就返回值
int binary_search(int* list, int len, int target){
    int low = 0;
    int hight = len-1;
    int middle;

    while (low<=hight){
        middle = (low+hight)/2;
        if(list[middle] = target){
            printf("已经找到该值，数组下标为:%d\n",middle);
            return list[middle];
        }else if(list[middle]>target){
            hight = middle - 1;
        }else if(list[middle]<target){
            low = middle + 1;
        }
    }
    printf("末找到该值");
    return -1;
}

// sizeof()关键字 是所指的是占用的空间大小 32位的话就除以4 64位就除以8
int main(){
    int a[] = {2,4,5,8,9,44};
    int b = binary_search(a, sizeof(a)/4,5);
    printf("b=%d\n",b);
    printf("Hello World!\n");
    return 0;
}
*/


/*
int main(){
    int Shangping[6] = {10,10,9,10,10};
    for(int i=0; i<6; i++){
        if(Shangping[i]==9){
            printf("找到次品,它的位置在:%d",i+1);
        }
    }
    return 0;
}
*/




/*
// 最短路径-弗洛伊德算法

struct MGraph{
    int numVertexes;
    int *vex;
    int arc[MAXVEX][MAXVEX];
};

typedef int PathMatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void ShortestPath_Floyd(MGraph *G, PathMatrix *P, ShortPathTable *D){
    int v,w,k;
    //初始化
    for(v=0; v<G->numVertexes; v++){
        for(w=0; w<G->numVertexes; ++w){
            (*D)[v][w] = G->arc[v][w];
            (*P)[v][w] = w;
        }
        for(k=0;k<G->numVertexes;++k){
            for(v=0; v<G->numVertexes; ++v){
                for(w=0; w<G->numVertexes; ++w){
                    if((*D)[v][w]>(*D)[v][k]+(*D)[k][w]){
                        // (v到w的距离) VS（v到k的距离+k到w的距离）
                        (*D)[v][w] = (*D)[v][k]+(*D)[k][w];
                        (*P)[v][w] = (*P)[v][k];
                        // 若从v出发，要去w,则先要从v到k，"再作下一步的打算下一步 （*P）[k][w]"
                    }
                }
            }
        }
    }
}


int main(){
    MGraph *my_g = (struct MGraph*)malloc(sizeof(struct MGraph));
    int i,j;
    int t=0;
    int v0=0;
    int vv=8;

    my_g->numVertexes=MAXVEX;
    my_g->vex =  (int *)malloc(sizeof(char) * my_g->numVertexes);

    if(!my_g->vex) return 0;

    //一维数组（图中各结点）初始化{0,1,2,3,4,5,6,7,8}
    for(i=0; i<my_g->numVertexes;++i){
        my_g->vex[i]=i++;
    }

    for(i=0; i<my_g->numVertexes; ++i){
        for(j=0; j<my_g->numVertexes; ++j){
            my_g->arc[i][j] = INFINITY;
        }
    }

    //无向图的权值二位数组为对称矩阵
    my_g->arc[0][1]=1;
    my_g->arc[0][2]=5;

    my_g->arc[1][2]=3;
    my_g->arc[1][3]=7;
    my_g->arc[1][4]=5;
    my_g->arc[2][4]=1;
    my_g->arc[2][5]=7;
    my_g->arc[3][4]=2;
    my_g->arc[3][6]=3;
    my_g->arc[4][5]=3;
    my_g->arc[4][6]=6;
    my_g->arc[4][7]=9;
    my_g->arc[5][7]=5;
    my_g->arc[6][7]=2;

    my_g->arc[6][8]=7;
    my_g->arc[7][8]=4;

    for(i=0; i<my_g->numVertexes; ++i){
        for(j=0; j<=i;++j){
            if(i==j){
                my_g->arc[i][j]=0;
                continue;
            }
            my_g->arc[i][j]=my_g->arc[j][i];
        }
    }

    for(i=0; i<my_g->numVertexes; ++i){
        //二位数组表示图中结点间连接边的weight
        for(j=0;j<my_g->numVertexes;++j){
            printf("%5d", my_g->arc[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    PathMatrix D;
    ShortPathTable P;
    ShortestPath_Floyd(my_g, &P, &D);

    //二位数组表示图中各结点间连接边的weight
    for(i=0; i<MAXVEX; ++i){
        for(j=0;j<MAXVEX; ++j){
            printf("%5d", P[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    free(my_g->vex);

    return 0;
}
*/


/*
 *
 * // 迪杰斯特拉算法介绍
typedef struct MGraph{
    string vexs[10];   //顶点信息
    int arcs[10][10];  //邻接矩阵
    int vexnum,arcnum; // 顶点数和边数
} MGraph;


// 返回定点u在图中的位置
int LocateVex(MGraph G, string u){
    for(int i=0; i<G.vexnum; i++){
        if(G.vexs[i] == u){
            return i;
        }
        return -1;
    }
}

void CreateDN(MGraph &G){ //构造有向网
    string v1,v2;
    int w;
    int i,j,k;
    cout<<"请输入顶点数和边数:";
    cin>>G.vexnum>>G.arcnum;

    cout<<"请输入定点:";
    for(i=0;i<G.vexnum;i++){
        cin>>G.vexs[i];
    }

    for(i=0;i<G.vexnum;i++){
        for(j=0;j<G.vexnum;j++){
            G.arcs[i][j]=INFINITY;
        }
    }

    cout<<"请输入边和权值:"<<endl;
    for(k=0;k<G.arcnum;k++){
        cin>>v1>>v2>>w;
        i=LocateVex(G, v1);
        j=LocateVex(G, v2);
        G.arcs[i][j]=w;
    }
}

void ShortestPath_DIJ(MGraph G, int v0, int p[][MAX_VERTEX_NUM], int D[]){
    int v, w, i, j, min;
    bool final[10];

    for(v=0; v<G.vexnum; v++){
        //初始值为false
        final[v]= false;
        //D[] 存放v0到v1得最短距离，初值为v0到v的直接距离
        D[v]=G.arcs[v0][v];

        for(w=0; w<G.vexnum; w++){
            //设p[][]初值为-1，即没有路径
            p[v][w] = -1;
        }
        //v0到v有直接路径
        if(D[v]<INFINITY){
            //v0到v最短路径经过第一个顶点
            p[v][0]=v0;
            //v0到v最短路径经过第二个顶点
            p[v][1]=v;
        }
    }

    D[v0] = 0; //v0到v0的距离为0
    final[v0]=true; // v0顶点并入s集

    //其余G.vexnum-1个顶点
    for(i=1; i<G.vexnum; i++){
        //开始主循环，每次求得v0到某个顶点v的最短路径，并将v并入s集，然后更新p和D
        min = INFINITY;
        //对所有顶点检查
        for(w=0; w<G.vexnum; w++){
            if(!final[w] && D[w]<min){
                // 在S集之外（即final[]=false）的顶点中找离v0最近的顶点，将其赋给v，距离赋给min
                v=w;
                min=D[w];
            }
        }
        //v并入S集
        final[v] = true;
        //根据新并入的顶点，更新不在S集的顶点到v0的距离和路径数组
        for(w=0; w<G.vexnum; w++){
            if(!final[w] && min<INFINITY && G.arcs[v][w]<INFINITY&&(min+G.arcs[v][w])){
                //w不属于S集并v0->v->w的距离<目前v0->w距离
                D[w] = min+G.arcs[v][w]; //更新D[w]
                // 修改p[w],v0到w经过顶点包括v0到v经过的所有顶点再加上顶点w
                for(j=0; j<G.vexnum; j++){
                    p[w][j] = p[v][j];
                    if(p[w][j]==-1){ //在p[w][]第一个等于-1的地方加上顶点w
                        p[w][j]=w;
                        break;
                    }
                }
            }
        }
    }
}


int main(){
    int i,j;
    MGraph g;
    CreateDN(g);
    // 最短路径数组p
    int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int D[MAX_VERTEX_NUM]; //最短距离数组D
    ShortestPath_DIJ(g,0,p,D);

    cout<<"最短路径数组p[i][j]如下:"<<endl;

    for(i=0; i<g.vexnum; i++){
        for(j=0; j<g.vexnum; j++){
            cout<<setw(3)<<p[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<g.vexs[0]<<"到各顶点的最短路径及长度为:"<<endl;

    for(i=0; i<g.vexnum; i++){
        if(i!=0 && D[i]!=INFINITY){
            cout<<g.vexs[0]<<"-"<<g.vexs[i]<<"的最短路径长度为:"<<D[i];
            cout<<"最短的路径为: ";
            for(j=0; j<g.vexnum; j++){
                if(p[i][j]>-1){
                    cout<<g.vexs[p[i][j]]<<" ";
                }
            }
            cout<<endl;
        }else if(D[i] == INFINITY){
            cout<<g.vexs[0]<<"-"<<g.vexs[i]<<":"<<"不可达"<<endl;
        }
    }
    return 0;
}
*/



/*
#define MAXEDGE 100
#define MAXVERTEX 100

using namespace std;

typedef struct Edge{
    int begin; //边的起点
    int end; //边的终点
    int wight; //边的权值
} Edge;

typedef struct Graph{
    char vertex[MAXVERTEX]; //顶点
    Edge edges[MAXEDGE]; //边
    int numvertex, numedges; //顶点和边的个数
} MGraph;


void CreateGraph(MGraph* G){
    printf("请输入定点和边的个数: \n");
    scanf("%d%d",&G->numvertex, &G->numedges);
    printf("请输入顶点:\n");
    //利用该函数除去上一系我们在输入结束时按得回车符
    getchar();

    for(int i=0; i<G->numvertex; i++){
        scanf("%c", &G->vertex[i]);
    }

    printf("按权值从小到大输入边(vi,vj)对应的起点和终点的下标，begin,end以及权值wight:\n");
    for(int k=0; k<G->numedges; k++){
        Edge e;
        scanf("%d%d%d",&e.begin, &e.end, &e.wight);
        G->edges[k] = e;
    }
}

int Find(int *parent, int f){
    while (parent[f]>0){
        f=parent[f];
    }
    return f;
}

//最小生成树，克鲁斯卡尔算法
void Kruskal(MGraph *G){
    // 存放最小生成树的顶点
    int parent[MAXVERTEX];

    for(int i=0; i<G->numvertex; i++){
        parent[i] = 0;
    }

    int m,n;
    for(int i=0; i<G->numedges; i++){
        n = Find(parent, G->edges[i].begin);
        m = Find(parent, G->edges[i].end);

        if(n!=m){ //m=n说明有环边和权值
            parent[n] = m;
            //打印值
            printf("(%d,%d) %d\t",G->edges[i].begin,G->edges[i].end,G->edges[i].wight);
        }
    }
}

int main(){
    MGraph G;
    CreateGraph(&G);
    Kruskal(&G);

    return 0;
}

*/






/*

// 最小生成树 算法

//定义邻接矩阵类型
typedef int adjmatrix[n+1][n+1];

typedef struct{
    int fromvex, tovex;
    int weight;
} Edge;

typedef Edge *EdgeNode;
int arcnum;   //边的个数

//建立图的邻接矩阵
void CreateMatrix(adjmatrix GA){
    int i, j, k, e;
    printf("=================================\n");
    printf("图中有%d个顶点\n",n);

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i==j){
                GA[i][j] = 0; //对角线的值置为0
            }else{
                GA[i][j]=MaxNum; //其他位置的值初始化为一个最大整数
            }
        }
    }
    printf("请输入边的个数:\n");
    scanf("%d",&arcnum);
    printf("请输入边的信息,依照起点，终点，权值的形式输入:\n");
    for(k=1; k<=arcnum; k++){
        //读入边的信息
        scanf("%d,%d,%d",&i, &j, &e);
        GA[i][j]=e;
        GA[j][i]=e;
    }
}

//初始化图的边集数组
void InitEdge(EdgeNode GE, int m){
    int i;
    for(i=1; i<=m; i++){
        GE[i].weight = 0;
    }
}

//依据图的邻接矩阵生成图的边集数组
void GetEdgeSet(adjmatrix GA, EdgeNode GE){
    int i, j, k = 1;
    for(i=1; i<=n; i++){
        for(j=i+1;j<=n;j++){
            if(GA[i][j]!=0 && GA[i][j] != MaxNum){
                GE[k].fromvex = i;
                GE[k].tovex = j;
                GE[k].weight = GA[i][j];
                k++;
            }
        }
    }
}

//按升序排列图的边集数组
void SortEdge(EdgeNode GE, int m){
    int i, j, k;
    Edge temp;
    for(i=1; i<m; i++){
        k=i;
        for(j=i+1; j<=m; j++){
            if(GE[k].weight > GE[j].weight){
                k=j;
            }
        }
        if(k!=i){
            temp = GE[i];
            GE[i] = GE[k];
            GE[k] = temp;
        }
    }
}

// 利用普里姆算法从初始点v出发求邻接矩阵表示图的最小生成树
void Prim(adjmatrix GA, EdgeNode T){
    int i, j, k, min, u, m, w;
    Edge  temp;
    // 给T赋初值，相应为v1依次到其余各顶点的边
    k = 1;
    for(i=1; i<=n; i++){
        if(i!=1){
            T[k].fromvex=1;
            T[k].tovex=i;
            T[k].weight = GA[1][i];
            k++;
        }
    }

    // 进行n-1次循环，每次求出最小生成树中的第k条边
    for(k=1; k<n; k++){
        min = MaxNum;
        m=k;
        for(j=k;j<n;j++){
            if(T[j].weight<min){
                min = T[j].weight;
                m=j;
            }
        }

        // 把最短边对调到k-1下标的位置
        temp=T[k];
        T[k]=T[m];
        T[m]=temp;
        // 把新增加最小生成树T中的顶点序号赋给j
        j = T[k].tovex;
        // 改动有关边， 使T中到T外的每个顶点保持一条到眼下为止最短的边
        for(i=k+1; i<n; i++){
            u = T[i].tovex;
            w=GA[j][u];
            if(w<T[i].weight){
                T[i].weight=w;
                T[i].fromvex = j;
            }
        }
    }
}

//输出边集数组的每条边
void OutEdge(EdgeNode GE, int e){
    int i;
    printf("依照起点、终点。权值的形式输出的最小生成树为:\n");
    for(i=1; i<=e; i++){
        printf("%d,%d,%d\n",GE[i].fromvex,GE[i].tovex,GE[i].weight);
    }
    printf("=======================\n");
}

int main(){
    adjmatrix GA;
    Edge GE[n*(n-1)/2],T[n];
    CreateMatrix(GA);
    InitEdge(GE, arcnum);
    GetEdgeSet(GA, GE);
    SortEdge(GE, arcnum);
    Prim(GA, T);
    printf("\n");
    OutEdge(T, n-1);
    return 0;
}

*/

/*
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct{
    int data;
    ArcNode *firstarc;
} Vnode;

// 可以利用结构体整体结构， 也可以拆分结构体变为单独搜索
typedef struct{
    Vnode adjlist[maxSize];
    int n, e;
} AGraph;

AGraph *graph;

// 插入链表的末尾
void insertNode(ArcNode *node, ArcNode *newNode){
    ArcNode *p = node;
    while (p->nextarc != NULL){
        p = p->nextarc;
    }
    p->nextarc = newNode;
}

void create(){
    graph = (AGraph*)malloc(sizeof(AGraph));
    cout<<"输入顶点的数目:"<<endl;
    cin>>graph->n;
    cout<<"输入图中边的数目:"<<endl;
    cin>>graph->e;

    int u=-1, v=-1;
    for(int i=0;i<graph->n;i++){
        graph->adjlist[i].firstarc=NULL;
    }

    ArcNode *node;

    for(int i=0; i<graph->e; i++){
        cout<<"请输入联通点A与B"<<endl;
        cin>>u>>v;
        node = (ArcNode*)malloc(sizeof(ArcNode));
        node->adjvex = v;
        node->nextarc = NULL;
        graph->adjlist[u].data = u;
        if(graph->adjlist[u].firstarc == NULL){
            //边
            graph->adjlist[u].firstarc = node;
        }else{
            // 插入边
            insertNode(graph->adjlist[u].firstarc, node);
        }
    }
}

void travseTree(){
    for(int i=0; i < graph->n; i++){
        if(graph->adjlist[i].firstarc != NULL){
            cout<<"与"<<i<<"连接的点有:";
            ArcNode *p = graph->adjlist[i].firstarc;
            while (p!=NULL){
                cout<<p->adjvex<<" ";
            }
            cout<<endl;
        }
    }
}

int main(void){
    create();
    travseTree();
    return 0;
}
*/


/*
// 最简单的存储-----邻接矩阵

const int maxn=105;
// 定义邻接矩阵
int adj[maxn][maxn]={0};

int x,y; //输入两条边
int n,m; //供输入n对边，m个顶点（x,y<=m）

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        adj[x-1][y-1]=1;
        adj[y-1][x-1]=1;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cout<<adj[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
*/


//程序员爬楼梯
/*
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
*/

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