#include <stdio.h>
#include <string.h>
#define MAX 100

void xorOperation(char *data, const char *poly, int start) {
    for (int i = 0; i < strlen(poly); i++) {
        data[start + i] = (data[start + i] == poly[i]) ? '0' : '1';
    }
}

void crc(char *data, const char *poly) {
    int dataLen = strlen(data);
    int polyLen = strlen(poly);
    
    // Perform the CRC calculation
    for (int i = 0; i <= dataLen - polyLen; i++) {
        if (data[i] == '1') {
            xorOperation(data, poly, i);
        }
    }
}

int main() {
    char data[MAX], poly[MAX], crcV[MAX], originalData[MAX];
    
    printf("Enter the character data string: ");
    scanf("%s", data);
    
    printf("Enter the polynomial in the binary form: ");
    scanf("%s", poly);
    
    int dataLen = strlen(data);
    int polyLen = strlen(poly);
    
    // Store the original data
    strcpy(originalData, data);
    
    // Append zeros to the data for CRC calculation
    for (int i = 0; i < polyLen - 1; i++) {
        data[dataLen + i] = '0';
    }
    data[dataLen + polyLen - 1] = '\0'; // Null-terminate the string
    
    // Perform CRC calculation
    crc(data, poly);
    
    // Extract the CRC value from the modified data
    strncpy(crcV, &data[dataLen], polyLen - 1);
    crcV[polyLen - 1] = '\0'; // Null-terminate the CRC value
    
    printf("Crc value is : %s\n", crcV);
    
    // Prepare the transmitted data by appending the CRC value to the original data
    strcat(originalData, crcV); // Append CRC value to the original data
    
    printf("Transmitted data is : %s\n", originalData);
    
    return 0;
}
