#include <stdio.h>
#include <string.h> //hdlc
int main(){
    char data[100], stuffed[200], destuffed[200];
    int i, j = 0, count = 0;
    int k, d = 0;
    printf("Enter the data in bits: ");
    scanf("%s", data);
    printf("\nHDLC Flag: 01111110");
    for (i = 0; data[i]!= '\0'; i++){
        stuffed[j++] = data[i];
        if (data[i] == '1'){
            count++;
            if (count == 5) {
                stuffed[j++] = '0';
                count = 0;
            }
        }
        else{
            count = 0;
        }
    }
    stuffed[j] = '\0';
    printf("\nStuffed Data: %s", stuffed);
    printf("\nHDLC Frame: 01111110 %s 01111110", stuffed);
    count = 0;
    for (i = 0; stuffed[i]!= '\0'; i++) {
        destuffed[d++] = stuffed[i];
        if (stuffed[i] == '1'){
            count++;
            if (count == 5) {
                i++;
                count = 0;
            }
        }
        else{
            count = 0;
        }
    }
    destuffed[d] = '\0';
    printf("\nDestuffed Data: %s", destuffed);
    printf("\nReceived Data: %s\n", destuffed);
    return 0;
}
