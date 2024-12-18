#include<stdio.h>
#include<unistd.h>

#define MAX_CAPACITY 10
#define LEAK_RATE 1
#define INCOMING_RATE 1

int bucket = 0;

void leak(){
    if(bucket > 0){
        bucket--;
        printf("Bucket leaked, Bucket level: %d\n", bucket);
    }
}

void incomingPacket(){
    if(bucket < MAX_CAPACITY){
        bucket++;
        printf("Packet added, Bucket level: %d\n", bucket);
    }else{
        printf("Bucket is full, packet discarded\n");
    }
}

int main(){
    int time = 0;
    
    // Loop to simulate for 10 seconds
    while(time < 10){
        printf("\nTime: %d second\n", time);

        // Simulate incoming packet and leak process
        incomingPacket();
        leak();
         
        // Wait for 1 second (to simulate real time)
        sleep(1);

        // Increment time for next iteration
        time++;
    }

    return 0;
}
