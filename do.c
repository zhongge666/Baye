
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

void __cdecl DOWriteLine(BYTE ch, BOOL TRUE);



int a,i;


{

    if (argc != 3) {
        printf("Usage: %s <cH> <TRUE>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    i = atoi(argv[2]);
//DOWriteLine(0,1);  //第一个0代表通道1,第二个1代表打开通道
//DOWriteLine(1,0);  //1代表通道2,0代表关闭通道，通道以此类推
{
    printf("DOWriteLine(%d, %d)\n", a, i);
}

    DOWriteLine(a, i); //程序外赋值 a , i    比如./test_dio 0 1   打开0通道
}
    return 0;

}

