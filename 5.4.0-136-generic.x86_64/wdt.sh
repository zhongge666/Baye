#!/bin/bash

#ubuntu 18.04  kernel 5.3.0-28

#tar -zxvf WDT_DIO.20200428.tgz

#cd linux/deploy/5.3.0-28-generic.x86_64

sudo insmod wdt_dio.ko

sudo chmod 644 /dev/wdt_dio

sudo cp -f wdt_dio.ko /lib/modules/$(uname -r)/kernel/drivers

sudo depmod -a

sudo modprobe wdt_dio

sudo cp libwdt_dio.so /usr/lib

sudo apt update

sudo apt install make gcc g++ qtchooser -y
sudo apt install libqt4-dev -y

./QtDIO

sudo cp QtDIO /usr/bin/

#QtDIO

#######or sample/QtDIO
#cd /linux/sample/QtDio
 
#sudo ln -s /usr/bin/qmake

#qmake

#make 

#./QtDIO
