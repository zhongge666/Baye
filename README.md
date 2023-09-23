
#这是Neousys产品Linux 下控制 DO 全部通道的代码
#后续我会再进行优化让它变的更灵活
\n                            

do.c 是一个单通道DO demo 编译后运行代码./do 0 1   //打开CH0通道 （ch0-ch15） ，//第二位1代表打开该通道，0=关闭该通道通道，
                                                        
DI_All.c 打开全部DI通道Demo 等待读取数据 DI=0 代表低电压L  DI_CH1 1 代表 通道1 来了一个高电压H   L: 0-1.5V  H: 5-24V

#2023/2/16 更新的test_dio.c 包含了 DO DI 测试，注意都只写了4个DO DI通道。
![2023-02-16 14-20-30 的屏幕截图](https://user-images.githubusercontent.com/118422636/219284726-a58f1795-28d3-459f-959d-76fd7d059ab2.png) 

Input DI = 65520 代表0L 低电压 65521-65529 代表不同机型的DI高电压通道，我测试的机型是Nuvo-5100VTC 所以test_dio.c 是适配Nuvo-5100VTC

![2023-02-16 14-23-38 的屏幕截图](https://user-images.githubusercontent.com/118422636/219285294-8829f973-4329-45ad-b01e-6879e9fb3d14.png)


驱动安装步骤：
STEP 1: UNPACK
=======================

    Decompress the WDT_DIO.YYYYMMDD.tgz :

    $ tar xvzf WDT_DIO.YYYYMMDD.tgz

    where 'YYYYMMDD' is the release number of this library core.

    This will extract the 'WDT_DIO/linux/' directory with the following subdirectories:
    --------------------------------------------------------------------------------------
    deploy/     contains the device modules (wdt_dio.ko) and shared library (libwdt_dio.so)
    driver/     contains the driver source code (*)
    sample/     contains some sample programs with source code
    include/    contains the header file used for samples
    manual/     documentation

    (*) The driver source code may not be contained in some release packages.

    Additionally special kernel supported :

    $ tar xvzf $(uname -r).$(uname -m).tgz -C ./WDT_DIO/linux/deploy/


STEP 2: INSTALL DRIVER
=======================

    2.1
    Load the kernel modules on linux systems :

    $ sudo insmod ./WDT_DIO/linux/deploy/$(uname -r).$(uname -m)/wdt_dio.ko

    Displaying the loaded WDT-DIO kernel modules :

    $ sudo lsmod | grep wdt_dio

    2.2
    This is an example if you want the driver that has -rw-r--r-- permissions, then

    $ sudo chmod 644 /dev/wdt_dio

    Therefore, add above commands into "rc.local" in order to setup when linux system start.

    Ubuntu : /etc/rcS.d/S90rc.local
    Fedora : /etc/rc.d/rc.local

    CentOS : /etc/rc.d/rc.local
    Please note that you must run 'chmod +x /etc/rc.d/rc.local' to ensure that this script will be executed during boot.

    2.3
    The kernel modules and the configuration files are stored in your /lib/modules/$(uname -r) directory.

    $ sudo cp -f ./WDT_DIO/linux/deploy/$(uname -r).$(uname -m)/wdt_dio.ko /lib/modules/$(uname -r)/kernel/drivers

    Automatically loading when linux system start :

    Ubuntu :
    $ echo 'wdt_dio' | sudo tee -a /etc/modules

    Fedora :
    $ echo 'wdt_dio' > /etc/modules-load.d/wdt_dio.conf

    Sometimes you could try these commands when not automatically loading :

    $ sudo depmod -a
    $ sudo modprobe wdt_dio


STEP 3: INSTALL LIBRARY
=======================

    This library is provided as a shared library.
    To install this library into linux system, type the following command :

    Ubuntu :
    $ sudo cp ./WDT_DIO/linux/deploy/$(uname -r).$(uname -m)/libwdt_dio.so /usr/lib

    Fedora x64 :
    $ sudo cp ./WDT_DIO/linux/deploy/$(uname -r).$(uname -m)/libwdt_dio.so /usr/lib64

    There are one or two internal serial ports used in this library, usually be the last one or two.

    $ dmesg | grep ttyS*

    In addition, you could modify proper permissions of these internal serial ports used in this library.
    It is an easy way :

    POC-120 serious :
    $ sudo chmod 666 /dev/ttyS3

    POC-300, Nuvo-2500 serious :
    $ sudo chmod 666 /dev/ttyS4
    $ sudo chmod 666 /dev/ttyS5

    Nuvo-5000 + D220/D230 :
    $ sudo chmod 666 /dev/ttyS3

    Nuvo-5100VTC :
    $ sudo chmod 666 /dev/ttyS3
    $ sudo chmod 666 /dev/ttyUSB0

    Nuvo-7000 serious :
    $ sudo chmod 666 /dev/ttyS4
    $ sudo chmod 666 /dev/ttyS5

    iVIS-200 :
    $ sudo chmod 666 /dev/ttyS5

    Therefore, add above commands into "rc.local" in order to setup when linux system start.

    Remark :
    Sometimes, you need to enable more than 4 serial ports by adding "8250.nr_uarts=8" into kernel command line.
    For some distributions, the ModemManager crashes on special serial ports. It is an fast way by removing ModemManager packages.


STEP 4: SAMPLES
=======================

    The WDT_DIO function reference of linux system is the same with windows system.
    You could download the lastest WDT_DIO windows driver package and extract the file named "ApplicationNote_WDT_DIO_v#.#.#.pdf".

    4.1 Console samples ( text mode only )

    test_wdt : watch dog sample program
    test_dio : digital input/output sample program
    test_cos : change-of-state sample program

    4.2 Qt samples ( development with Qt support )

    QtDIO : digital input/output sample program
    QtCAN : can bus sample program

X   Error: BadAccess (attempt to access private resource denied) 10
    Extension:    130 (MIT-SHM)

    sudo QT_X11_NO_MITSHM=1 ./QtDIO

BUILD 1: DRIVER
=======================

    Change to the directory which contain WDT-DIO driver source code.

    $ cd ./WDT_DIO/linux/driver

    Always clean the project at first.

    $ make clean

    Then build it.

    $ make

    Copy the binary file into system.

    $ make install

    Manually install the module.

    $ make insmod

    Displaying the loaded information about WDT-DIO kernel module.

    $ make lsmod


BUILD 2: LIBRARY
=======================

    Change to the directory which contain this library source code.

    $ cd ./WDT_DIO

    Always clean the project at first.

    $ make clean

    Then build it.

    $ make

    Copy the binary file into system.

    $ make install

    Copy the binary file into deploy directory.

    $ make deploy
