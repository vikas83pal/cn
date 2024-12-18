#include<stdio.h>
#define MAX_SIZE 100

void bitStuffing(int arr[], int n){
    int i = 0,j = 0, cnt = 0;
    int stuffedArr[MAX_SIZE];

    while(i < n){
        stuffedArr[j] = arr[i];

        if(arr[i] == 1) {
            cnt++;
        }else{
            cnt = 0;
        }

        if(cnt == 5){
            j++;
            stuffedArr[j] = 0;
            cnt = 0;
        }

        i++;
        j++;
    }

    printf("\nStuffed array is\n");
    for(int k=0; k<j; k++){
        printf("%d ", stuffedArr[k]);
    }
}

int main(){
    int n;
    int arr[MAX_SIZE];
    printf("Enter the length of the array\n");
    scanf("%d", &n);

    printf("Enter the bits in binary form:\n");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("The array before stuffing is:\n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    bitStuffing(arr, n);
}