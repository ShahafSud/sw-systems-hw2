#include <stdio.h>
static float ds [5][21] = {0};
static float values[5];
static float weights[5];
char names[5][256];
char *strAdress[5];
static float best_value_for_waight = 0;

//TODO : comments!
void compute_cell(int itemID, int WL){//mostly if statmants
    if(WL==0){
        ds[itemID][WL]=0;
        return;
    }
    if(ds[itemID][WL]!=-1){
        return;
    }
    //first row
    if(itemID==0 && WL-(int)weights[itemID]<0){
        ds[itemID][WL]=0;
        return;
    }
    if(itemID==0 && WL-(int)weights[itemID]>=0){
        ds[itemID][WL]=values[itemID];
        return;
    }
    //early columns
    if(WL-(int)weights[itemID]<0){
        ds[itemID][WL]=ds[itemID-1][WL];
        return;
    }
    //rest of the cells, choose max
    if(WL-(int)weights[itemID]>=0 && ds[itemID-1][WL-(int)weights[itemID]]+(int)values[itemID]>=(int)ds[itemID-1][WL]){
        ds[itemID][WL]=ds[itemID-1][WL-(int)weights[itemID]]+(int)values[itemID];
        return;
    }
    if(WL-(int)weights[itemID]>=0 && ds[itemID-1][WL-(int)weights[itemID]]+(int)values[itemID]<(int)ds[itemID-1][WL]){
        ds[itemID][WL]=ds[itemID-1][WL];
    }

}
void TraceBack(int indeces[5]){//indeces starts with all values at 0.
    int i = 4;
    int j = 20;
    while(ds[i][j]!=0){
        if (ds[i-1][j]<=ds[i-1][j-(int)weights[i]] + values[i]){
            indeces[i]=1;
            j=j-(int)weights[i];
        }
        i=i-1;
    }
}
void selectItems(float values[5], float weights[5], char *strings[], int numStrings){
    for(int i=0;i<5;i++){//initialize ds
        for(int j=0;j<21;j++){
            ds[i][j]=-1;
        }
    }
    for(int i=0;i<5;i++){//compute all values
        for(int j=0;j<21;j++){
            compute_cell(i,j);
        }
    }
    best_value_for_waight = (float)ds[4][19];//static for print in main
    int indeces[5] = {0};
    TraceBack(indeces);//find witch items were choosen
    for(int i=0;i<5;i++){
        if(indeces[i]==0){
            strings[i]="";
        }
    }
}
int main(){
    for(int i;i<5;i++){//take input
        scanf("%255s", names[i]);
        strAdress[i] = names[i];
        scanf("%f",&values[i]);
        scanf("%f",&weights[i]);
    }
    selectItems(values, weights, strAdress, 5);//select the best solution

    for(int i=0;i<5;i++){//print all choosen strings
        if(names[i][0] != '\0'){
            printf("%s",strAdress[i]);
        }
    }
    printf("\nMax sum of values : %d\n", (int)best_value_for_waight);//print the saved static value
    for(int i=0;i<5;i++){
        for(int j=0;j<21;j++){
            printf("%d ",(int)ds[i][j]);
        }
    printf("\n");
    }
    return 0;
}