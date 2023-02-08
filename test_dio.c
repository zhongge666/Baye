
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "wdt_dio.h"

int main(int argc, char *argv[]){

   
    WORD  data = 0;

    if ( ! InitDIO() ) 
    {
        printf("InitDIO <-- ERROR\n");
        return -1;


    }	


            DOWritePort(1);   //打开全部的DO Port
            sleep(2);
            data = DIReadPort();
            printf("DIReadPort = 0x%hx\n", ~data);
	        DOWritePort(0);  //关闭全部DO Port
            printf("close DO ALL\n");
    


    return 0;
 }
