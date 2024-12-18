#include<stdio.h>
#define N 5

void dispTree(int tree[N][N]){
    for(int i=0; i<N; i++){
        printf("Host %d sends boardcase to : ",i);
        for(int j=0; j<N; j++){
           if(tree[i][j] == 1){
            printf("Host %d ", j);
           }
        }
        printf("\n");
    }
}

void createBoardCast(int network[N][N], int tree[N][N], int root, int visited[N]){
    visited[root] = 1;

    for(int i=0; i<N; i++){
        if(network[root][i] == 1 && !visited[i]){
            tree[root][i] = 1;
            createBoardCast(network, tree, i, visited);
        }
    }

   
}

int main(){
    int network[N][N] = {
        {0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}
    };

    int tree[N][N] = {0};
    int visited[N] = {0};

    int root = 0;


    createBoardCast(network, tree, root, visited);
    printf("Board cast starting from the vertex %d\n", root);
     dispTree(tree);

    return 0;
}