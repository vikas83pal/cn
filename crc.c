#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

void xoroperation(char *data, const char *poly, int start) {
    for(int i=0; poly[i] != '\0'; i++){
        data[start + i] = (data[start + i] == poly[i]) ? '0' : '1';
    }
}

void calculateCrc(char *data, const char *poly){
    int dataLen = strlen(data);
    int polyLen = strlen(poly);
    
    for(int i=0; i<= dataLen - polyLen; i++){
        if(data[i] == '1'){
            xoroperation(data, poly, i);
        }
    }
}
int main(){
    char data[MAX_SIZE];
    char poly[MAX_SIZE];

    
    printf("Enter the data string: ");
    scanf("%s", data);
    
    printf("Enter the polynomial: ");
    scanf("%s", poly);
    
    int dataLen = strlen(data);
    int polyLen = strlen(poly);
    for(int i=0;i <polyLen - 1; i++){
        data[dataLen + i] = '0';
    }
    
    data[dataLen + polyLen - 1] = '\0';
    
    calculateCrc(data, poly);
    
    printf("Crc value is : %s\n", &data[dataLen]);
    printf("Transmitted data is %s\n", data);
    return 0;
    
}