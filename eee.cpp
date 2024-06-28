#include <stdio.h>
#include <string.h>

void bitStuffing(char *data) {
    int originalLen = strlen(data);
    int stuffedLen = 0;
    char stuffedData[100];  // Assuming a maximum size for stuffed data
    int count = 0;  // Counter to track consecutive '1's
    
    for (int i = 0; i < originalLen; i++) {
        stuffedData[stuffedLen++] = data[i];  // Copy each bit from original data
        
        if (data[i] == '1') {
            count++;  // Increment count if current bit is '1'
        } else {
            count = 0;  // Reset count if current bit is '0'
        }
        
        if (count == 5) {
            stuffedData[stuffedLen++] = '0';  // Stuff a '0' after five consecutive '1's
            count = 0;  // Reset count after stuffing
        }
    }
    
    stuffedData[stuffedLen] = '\0';  // Null terminate the stuffed data
    printf("Original Data: %s\n", data);
    printf("Stuffed Data : %s\n", stuffedData);
}

int main() {
    char data[] = "1011111100110";  // Example original data to be stuffed
    
    bitStuffing(data);
    
    return 0;
}

