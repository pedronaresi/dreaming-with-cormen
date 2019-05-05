#include <stdio.h>
#include<stdlib.h>

#define MaxNumVertices  1000
#define MaxNumArestas   4500
#define TRUE  1
#define FALSE 0

typedef struct TipoGrafo {
  int Mat[MaxNumVertices + 1][MaxNumVertices + 1];
  int NumVertices;
  int NumArestas;
} TipoGrafo;

void makeEmptyGraph(TipoGrafo *graph)
{
  short i, j;

  for (i = 0; i <= graph->NumVertices; i++) {
    for (j = 0; j <= graph->NumVertices; j++)
      graph->Mat[i][j] = 0;
  }
}

/*void createGraph(TipoGrafo graph, int n){

}*/

void connectVertices(TipoGrafo *graph, int a, int b){
    graph->Mat[a-1][b-1] = 1;
    graph->Mat[b-1][a-1] = 1;
}

/*void mostInvitedQuantity(TipoGrafo graph){

}*/

int subGraph(TipoGrafo *graph, int n, int k){
    int i,j,aux=-1,grau=0;

    for(i=0;i<n;i++){
        if(graph->Mat[i][n]!=-1){
        for(j=0;j<n;j++){
            if(graph->Mat[i][j]!=0){
                grau++;
            }
        }
        if(grau<k){
            aux=i;
            graph->Mat[i][n]=-1;
        }
            if(aux!=-1){
            for(j=0;j<n;j++){
                graph->Mat[aux][j]= -1;
                if(graph->Mat[j][aux]!=-1){
                    graph->Mat[j][aux]=0;
                }
            }
        }
        grau=0;
    }
    }
    return aux;
}

int verify(TipoGrafo *graph, int n){
    int i,total=0;

    for(i=0;i<n;i++){
        if(graph->Mat[i][0]!=-1){
            total++;
        }
    }
    return total;
}

int main(){
    int n, p, k, a, b, aux = 0;
    TipoGrafo graph;

    scanf("%d", &n);
    // (1 ≤ N ≤ 1000)
    if(n < 1 || n > 1000)
        return 0;
    //createGraph(graph, n);

    scanf("%d", &p);
    scanf("%d", &k);
    // (1 <= K <= N-1)
    if(k < 1 || k > (n-1))
        return 0;

    for(int i = 0; i < p; i++){
        scanf("%d %d", &a, &b);
        //(1 <= a <= N, 1 <= b <= N e a != b)
        //if((1 > a) || (a > n) || (1 > b) || (b > n) || (a = b)){
           //printf("hahah");
            //return 0;
       // }
        //funcao conecta aresta
        connectVertices(&graph, a, b);
    }

    while(aux!=-1){
        aux=subGraph(&graph,n,k);
    }

    int total = verify(&graph,n);
    printf("%d", total);
    return 0;
    //printf("%d", mostInvitedQuantity(graph));
}
