#include <stdio.h>
#include "my_mat.h"
static int FW[10][10] = {0};

void FloydWarshall(int mat[10][10], int out[10][10]){
    int prev[10][10] = {0};
    int next[10][10] = {0};
    int go_arownd=0;
    int strait_path=0;
    int min_path=0;
    int inf = 10000000;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            prev[i][j]=mat[i][j];
            inf=inf+mat[i][j]; 
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(prev[i][j]==0){
                prev[i][j]=inf;
            }
        }
    }
    printf("the initial matrix is:\n");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d ",prev[i][j]);
        }
        printf("\n");
    }
    for(int k=0;k<10;k++){
        for(int i=0;i<10;i++){
            next[k][i]=prev[k][i];
            next[i][k]=prev[k][i];
        }
        for(int i=0;i<10;i++){
            if(i==k){
                continue;
            }
            for(int j=0;j<10;j++){
                if(j==k){
                    continue;
                }
                go_arownd=prev[i][k]+prev[k][j];
                strait_path=prev[i][j];
                if(go_arownd<=strait_path){
                    min_path=go_arownd;
                }
                else{
                    min_path=strait_path;
                }
                next[i][j]=min_path;
            }
        }
        printf("the %dth matrix is:\n",k);
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                prev[i][j]=next[i][j];
                printf("%d ",prev[i][j]);
            }
            printf("\n");
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(next[i][j]<inf){
                out[i][j]=next[i][j];
            }
            else{
                out[i][j]=-1;
            }
        }
    }
}

void get_mat_from_usr(int mat[10][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    FloydWarshall(mat,FW);
}
void print_is_path(){
    int i=0;
    int j=0;
    scanf("%d",&i);
    scanf("%d",&j);
    if(FW[i][j]>=0 && i!=j){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}
void print_path(){
    int i=0;
    int j=0;
    scanf("%d",&i);
    scanf("%d",&j);
    if(i==j){
        printf("%d\n",-1);
    }
    else{
        printf("%d\n",FW[i][j]);
    }
}
