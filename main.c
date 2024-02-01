#include <stdio.h>
#include "my_mat.h"
int main() {
    int mat[10][10] = {0};
    char command='S';
    while(command!='D'){
        scanf("%c", &command);
        if(command=='A'){
            get_mat_from_usr(mat);
        }
        if(command=='B'){
            print_is_path();
        }
        if(command=='C'){
            print_path();
        }
    }
    return 0;
}