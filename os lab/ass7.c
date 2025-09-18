#include <stdio.h>
#include <stdbool.h>

int main(){
    int n, m; 
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m];
    int need[n][m], finish[n], safeSeq[n];

    printf("Enter allocation matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("\n");

    printf("Enter max matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &max[i][j]);
        }
    }
    printf("\n");

    printf("Enter available resources:\n");
    for(int i = 0; i < m; i++){
        printf("Enter element [%d]: ", i);
        scanf("%d", &avail[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Need Matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < n; i++) finish[i] = 0;

    int count = 0;
    while(count < n){
        bool found = false;
        for(int i = 0; i < n; i++){
            if(finish[i] == 0){
                bool possible = true;
                for(int j = 0; j < m; j++){
                    if(need[i][j] > avail[j]){
                        possible = false;
                        break;
                    }
                }
                if(possible){
                    finish[i] = 1;
                    safeSeq[count++] = i;
                    for(int j = 0; j < m; j++){
                        avail[j] += alloc[i][j];
                    }
                    found = true;
                }
            }
        }
        if(!found){
            printf("System is not in safe state\n");
            return 0;
        }
    }
    printf("System is in safe state\n");
    printf("Safe sequence: ");
    for(int i = 0; i < n; i++){
        printf("%d ", safeSeq[i]);
    }
    printf("\n");
    return 0;
}