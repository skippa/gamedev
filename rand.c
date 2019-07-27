#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    float random;
    float color;
    int i;
    float currentTime;

    currentTime = time(NULL);

    printf("%h", currentTime);
    printf("\n");

    /*
    srand(time(NULL));
    for(i=0; i<10; i++){
        random = ((rand() % 99)+1)/100;
        //color = random/100;
        //printf("%f  ", random);
        printf("%f", color);
        printf("\n");
    } */

}
