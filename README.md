#2023/2/8  我写了第一个代码 
#这是Neousys产品Linux 下控制 DO 全部通道的代码
#后续我会再进行优化让它变的更灵活
\n                            

do.c 是一个单通道DO demo 

运行代码./test_dio 0 1    第一个0代表通道，第二个1代表打开通道 
                                                        
DI_All.c 打开全部DI通道Demo 等待读取数据 DI=0 代表低电压L  DI_CH1 1 代表 通道1 来了一个高电压H   L: 0-1.5V  H: 5-24V

#2023/2/16 更新的test_dio.c 包含了 DO DI 测试，注意都只写了4个DO DI通道。
![2023-02-16 14-20-30 的屏幕截图](https://user-images.githubusercontent.com/118422636/219284726-a58f1795-28d3-459f-959d-76fd7d059ab2.png) 

Input DI = 65520 代表0L 低电压 65521-65529 代表不同机型的DI高电压通道，我测试的机型是Nuvo-5100VTC 所以test_dio.c 是适配Nuvo-5100VTC

![2023-02-16 14-23-38 的屏幕截图](https://user-images.githubusercontent.com/118422636/219285294-8829f973-4329-45ad-b01e-6879e9fb3d14.png)
