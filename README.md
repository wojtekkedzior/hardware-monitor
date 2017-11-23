This is my attempt at writting a C/C++ based hardware monitor on Ubuntu 16.04 LTS.  I'm running an Asus R4BE motherboard which comes with many sensors, all of which i'm trying to get a read out for. This motherboard is paired with an 4930K, which has it's own group of sensors to report CPU and Package temperature.   

Yes, I'm totally re-inventing the over-invented wheel in hardware monitoring tools, but this is the best project I could come up with to get into the world of C++ on Linux. The intention is to get somewhat familiar with C++, QT and the Linux environment.  With emphysis on C++. None of this code is doing any magical optimsations nor is it solving any problems that have not already been solved. If it appears to do so, then I can assure you it's just a fluke. 

I've taken some inspiration from https://github.com/karelzak/util-linux/blob/master/sys-utils/lscpu.c especially around the area of locating the correct files that hold the sensor data. 

