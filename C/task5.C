#include <stdio.h>

int main()
{
    const int m {5}; 
    const int n {7};
    bool nonepar = true;

    int matrix[m][n];

    for (int i=0;i<m;i++){
        bool nepar = true;
        for (int j=0;j<n;j++){
            if (matrix[i][j]%2==0){
                nepar = false; break;
            }
        }

        if (nepar){
            printf("neparniy riadok: %f\n", i);
            nonepar = false;
        }
        else {
            for(int j=0;j<n/2;j++){
                int vremennoe = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = vremennoe; 
            }
        }
    }
    if (nonepar){
        printf("nemae neparnyh riadkiv");
    }
}

