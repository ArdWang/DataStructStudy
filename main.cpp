#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>


//#include<malloc.h>
//#define maxSize 1000
//#define n 20
//#define MaxNum 1000   /*定义一个最大的整数*/

//#define INFINITY 65535  //无边时的权值
//#define MAX_VERTEX_NUM 10   //最大定点数

#define MAXVEX 9
#define INFINITY 65535


using namespace std;



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