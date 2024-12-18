#include<stdio.h>
#define MAX_LENGTH 100

void encrypted(char *data, int shift){
    for(int i=0; data[i] != '\0'; i++){
        if(data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = (data[i] - 'A' + shift) % 26 + 'A';
        }
        if(data[i] >= 'a' && data[i] <= 'z') {
            data[i] = (data[i] - 'a'  + shift) % 26 + 'a';
        }
    }
}
void decrypted(char *data, int shift){
    for(int i=0; data[i] != '\0'; i++){
        if(data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = (data[i] - 'A'  - shift) % 26 + 'A';
        }
        if(data[i] >= 'a' && data[i] <= 'z') {
            data[i] = (data[i] - 'a'  - shift) % 26 + 'a';
        }
    }
}

int main(){
    char data[MAX_LENGTH];
    int shift;

    printf("Enter the data string:");
    fgets(data, MAX_LENGTH, stdin);

    printf("Enter the shift value : ");
    scanf("%d", &shift);

    encrypted(data, shift);
    printf("Encypted data is: %s", data);

    
    decrypted(data, shift);
    printf("decypted data is: %s", data);


    return 0;
}