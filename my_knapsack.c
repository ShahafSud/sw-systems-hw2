#include <stdio.h>
#define numItem 5 
#define WhightLim 20 

static int ds [numItem][WhightLim+1] = {0};
static int values[numItem];
static int weights[numItem];
char names[numItem][20];
char *strAdress[numItem];
static int best_value_for_waight = 0;

void compute_cell(int itemID, int WL){//mostly if statmants
    if(WL==0){
        ds[itemID][WL]=0;
        return;
    }
    if(ds[itemID][WL]!=-1){
        return;
    }
    //first row
    if(itemID==0 && WL-weights[itemID]<0){
        ds[itemID][WL]=0;
        return;
    }
    if(itemID==0 && WL-weights[itemID]>=0){
        ds[itemID][WL]=values[itemID];
        return;
    }
    //early columns
    if(WL-weights[itemID]<0){
        ds[itemID][WL]=ds[itemID-1][WL];
        return;
    }
    //rest of the cells, choose max
    if(WL-weights[itemID]>=0 && ds[itemID-1][WL-weights[itemID]]+values[itemID]>=ds[itemID-1][WL]){
        ds[itemID][WL]=ds[itemID-1][WL-weights[itemID]]+values[itemID];
        return;
    }
    if(WL-weights[itemID]>=0 && ds[itemID-1][WL-weights[itemID]]+values[itemID]<ds[itemID-1][WL]){
        ds[itemID][WL]=ds[itemID-1][WL];
    }

}
void TraceBack(int indeces[numItem]){//indeces starts with all values at 0.
    int i = numItem-1;
    int j = WhightLim; 
;
    while(ds[i][j]!=0){
        if (ds[i-1][j]<=ds[i-1][j-weights[i]] + values[i]){
            indeces[i]=1;
            j=j-weights[i];
        }
        i=i-1;
    }
}
void selectItems(int values[numItem], int weights[numItem], int selected_bool[numItem]){
    for(int i=0;i<numItem;i++){//initialize ds
        for(int j=0;j<WhightLim+1;j++){
            ds[i][j]=-1;
        }
    }
    for(int i=0;i<numItem;i++){//compute all values
        for(int j=0;j<WhightLim+1;j++){
            compute_cell(i,j);
        }
    }
    best_value_for_waight = ds[numItem-1][WhightLim];//static for print in main
    
    TraceBack(selected_bool);//find witch items were choosen
    for(int i=0;i<numItem;i++){
        if(selected_bool[i]==0){
            strAdress[i]="";
        }
    }
}
int main(){
    for(int i;i<numItem;i++){//take input
        scanf("%20s", names[i]);
        strAdress[i] = names[i];
        scanf("%d",&values[i]);
        scanf("%d",&weights[i]);
    }
    int indeces[numItem] = {0};
    selectItems(values, weights, indeces);//select the best solution
    printf("Maximum profit: %d\n", best_value_for_waight);//print the saved static value
    printf("Selected items:");
    for(int i=0;i<numItem;i++){//print all choosen strings
        if(names[i][0] != '\0'){
            if(strAdress[i][0] != '\0'){
                printf(" %s",strAdress[i]);
            }
        }
    }
    printf("\n");
    return 0;
}