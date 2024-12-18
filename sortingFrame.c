#include<stdio.h>
#define MAXFRAME 5

struct  Frame
{
    int arrivalTime;
    char data[100];
};


void sortFrame(struct Frame arr[], int n){
    struct Frame temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j].arrivalTime > arr[j + 1].arrivalTime){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    struct Frame buffer[MAXFRAME];
    for(int i=0; i<MAXFRAME; i++){
        printf("Enter the arrival time for frame %d : ", i+1);
        scanf("%d",&buffer[i].arrivalTime);
        printf("Enter the data for frame %d : ", i+1);
        scanf("%s",&buffer[i].data);
    }

    sortFrame(buffer, MAXFRAME);

    for(int i=0; i<MAXFRAME; i++){
        printf("Frame %d : arraival time %d\n", i+1, buffer[i].arrivalTime);
    }
    return 0;
}