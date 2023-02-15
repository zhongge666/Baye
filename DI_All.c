#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "wdt_dio.h"


int main(int argc, char *argv[]){


    if ( ! InitDIO() ) 
    {
        printf("InitDIO <-- ERROR\n");
        return -1;
    }	

printf("Input DI state: \n");

WORD __cdecl DIReadPort(void);

    int count = 0;

    while (1) {
        int state = DIReadPort();
        sleep(1);

        switch (state) {
            case 65521:
                printf("DI_CH1=1\n");
                break;
            case 65522:
                printf("DI_CH2=1\n");
                break;
            case 65523:
                printf("DI_CH3=1\n");
                break;
            case 65524:
                printf("DI_CH4=1\n");
                break;
            default:
                printf("DI=0\n");
                break;
        }

        count++;
        printf("Loop count: %d\n", count);
    }

    return 0;


}



/*     int count = 0;
    while (1) {
    int state = DIReadPort();
    //printf("Input state: %d\n",state);
    sleep(1);  // 延迟 1 秒

    //DI_CH0 state
        if( state == 65521){
            printf("DI_CH0=1\n");
        }
       
    //DI_CH1 state
        if( state == 65522){
            printf("DI_CH1=1\n");
        }
    //DI_CH2 state
        if( state == 65523){
            printf("DI_CH2=1\n");
        }
    //DI_CH3 state
        if( state == 65524){
            printf("DI_CH3=1\n");
        }
//        else{
//            printf("DI=0\n");
//        }

        count++;
        printf("Loop count: %d\n",count);
                   
  }
    
    return 0;
 } */