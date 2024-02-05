#include <stdio.h>
//static float ds [5][20][2] = {0};//0==Value, 1==Wight
static float ds [5][20] = {0};//0==Value, 1==Wight
static float values[5];
static float weights[5];
static float best = 0;
// static char names[5][256];
// void compute_cell(int itemID, int WL){
//     if(itemID==0||WL==0){
//         ds[itemID][WL][0]=0;
//         ds[itemID][WL][1]=0;
//         return;
//     }
//     if(ds[itemID][WL][0]!=-1){
//         return;
//     }

//     float alowedW = WL-weights[itemID];
//     if((int)alowedW==alowedW){
//         alowedW=alowedW-1;
//     }
//     int oldWL=(int)alowedW+1;

//     if(ds[itemID-1][oldWL][1] + weights[itemID]>WL){
//         oldWL=oldWL-1;
//     }

//     float next_val;
//     float next_W;
//     if(ds[itemID-1][oldWL][0]+values[itemID]<=ds[itemID-1][WL][0]){
//         next_val = ds[itemID-1][WL][0];
//         next_W = ds[itemID-1][WL][1];
//     }
//     else{
//         next_val = ds[itemID-1][oldWL][0]+values[itemID];
//         next_W = ds[itemID-1][oldWL][1]+weights[itemID];
//     }
//     ds[itemID][WL][0]=next_val;
//     ds[itemID][WL][1]=next_W;

// }
//,char *strings[]

void compute_cell(int itemID, int WL){
    if(itemID==0||WL==0){
        ds[itemID][WL]=0;
        return;
    }
    if(ds[itemID][WL]!=-1){
        return;
    }

    if(ds[itemID-1][WL-(int)weights[itemID]]+(int)values[itemID]<=(int)ds[itemID-1][WL]){
        ds[itemID][WL]=ds[itemID-1][WL];
    }
    else{
        ds[itemID][WL]=ds[itemID-1][WL-(int)weights[itemID]]+(int)values[itemID];
    }

}

void selectItems(float values[5], float weights[5], int numStrings){
    for(int i=0;i<5;i++){
        for(int j=0;j<20;j++){
            //ds[i][j][0]=-1;
            //ds[i][j][1]=-1;
            ds[i][j]=-1;
        }

    }
    for(int i=0;i<5;i++){
        for(int j=0;j<20;j++){
            compute_cell(i,j);
        }

    }
    // printf("max value = %f\n",ds[4][19][0]);
    printf("max value = %f\n",ds[4][19]);
    return;
}


int main(){
    

    for(int i;i<5;i++){
        // scanf("%255s", names[i]);
        scanf("%f",&values[i]);
        scanf("%f",&weights[i]);
    }
    //printf("%c,%c,%c,%c,%c\n",names[0],names[1],names[2],names[3],names[4]);
    // printf("%f,%f,%f,%f,%f\n",weights[0],weights[1],weights[2],weights[3],weights[4]);
    // printf("%f,%f,%f,%f,%f\n",values[0],values[1],values[2],values[3],values[4]);
    selectItems(values, weights, 5);



















    printf("yo yo this is working mate!\n");
    return 0;
}