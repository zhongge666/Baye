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

int a = 0;

printf("请输入数字运行Demo\n1.打开全部DO:\n2.打开全部DI:\n");

if(scanf("%d",&a)){

switch (a){
case 1:
    printf("打开2秒后关闭DO\n");
    DOWritePort(1);   //打开全部的DO Port
    sleep(2);
	DOWritePort(0);  //关闭全部DO Port
    printf("close DO ALL\n");
    return 0;
    break;

case 2:
    printf("Input DI state: \n");

    WORD __cdecl DIReadPort(void);

    int count = 0;

    while (1) {
        int state = DIReadPort();
        sleep(1);
        
        count++;
        printf("Loop count: %d\n" "Input DI: %d\n", count,state);

        switch (state) {
            case 65521:
                printf("DI_ch0=1\n");
                break;
            case 65522:
                printf("DI_ch1=1\n");
                break;
            case 65524:
                printf("DI_ch2=1\n");
                break;
            case 65528:
                printf("DI_ch3=1\n");
                break;
            default:
                printf("DI=0L\n");
                break;
        }
        
    }

    return 0;

default:
    printf("输入不正确");
    break;
    }
};
return 0;
}