#include<stdio.h>
#include<limits.h>
#define N 5
#define INF INT_MAX

void printTb(int dist[N][N]){
    for(int i=0; i<N; i++){
        printf("Node %d: ", i);
        for(int j=0; j<N; j++){
            if(dist[i][j] == INF){
                printf("INF ");
            }else{
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}


void distanceVector(int dist[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
              if(dist[j][i] != INF && dist[i][k] != INF){
                    int newDist = dist[j][i] + dist[i][k];
                    if(newDist < dist[j][k]){
                        dist[j][k] = newDist;
                    }
                }
            }
        }
    }
}

int main(){
    int g[N][N]={
        {0, 4, INF, 0, 0},
        {4, 0, 8, 0, 0},
        {INF, 8, 0, 7, 0},
        {0, 0, 7, 0, 9},
        {0, 0, 0, 9, 0}
    };

    printf("Inital routing table is :\n");
    printTb(g);

    distanceVector(g);

    printf("\nRouting Table is \n");
    printTb(g);
    return 0;
}