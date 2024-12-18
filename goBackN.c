#include<stdio.h>
#define TOTALFRAME 10
#define WINDOWSIZE 4

int main(){
    int totalFram = TOTALFRAME;
    int windowSize = WINDOWSIZE;
    int currentFrame = 0;

    while(currentFrame < totalFram){
        printf("Sending frame \n");
        for(int i=0; i<currentFrame + windowSize && i<totalFram; i++){
            printf("%d ", i);
        }
        printf("\n");

        int ack;
        printf("Enter the last acknowledge %d: ", currentFrame);
        scanf("%d", &ack);

        if(ack >= currentFrame + windowSize - 1 && ack == totalFram - 1){
            currentFrame = ack + 1;
            printf("ALl frames are upto %d acknowledge\n", ack);
        }else{
            printf("Error resending the frame: %d \n", ack + 1);
            currentFrame = ack + 1;
        }

    }


    return 0;

}