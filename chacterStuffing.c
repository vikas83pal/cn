#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
#define FLAG "FLAG"
#define ESC "ESC"

void chacterStuffing(char arr[], int n){
    char stuffedArr[MAX_SIZE * 2];
    int i = 0, j = 0;

    while(i < n){
        if(strncmp(&arr[i], FLAG, strlen(FLAG)) == 0 || strncmp(&arr[i], ESC, strlen(ESC)) == 0){
            strcpy(&stuffedArr[j], ESC);
            j += strlen(ESC);
        }
        stuffedArr[j] = arr[i];
        i++;
        j++;
    }

    stuffedArr[j] = '\0';
    printf("Stuffed array is %s\n", stuffedArr);
}

int main(){
    char arr[MAX_SIZE];

    printf("Enter the data:\n");
    scanf("%[^\n]", &arr);

    int n = strlen(arr);

    chacterStuffing(arr, n);
    return 0;
}