

#include "recv.h"
 
int nFd = 0;
int fd = 0;
struct termios stNew;
struct termios stOld;

#define UART1 0
#define UART2 0
#define UART3 0

#define RS485_RECEIVE 1

#if  UART1
	#define dev "/dev/ttyUSB1"
	#define devr "./txtr"
#endif

#if  UART2
	#define dev "/dev/ttyUSB0"
	#define devr "./txtr1"
#endif
#if  UART3
	#define dev "/dev/ttyUSB3"
	#define devr "./txtr2"
#endif
#if  RS485_RECEIVE
	#define dev "/dev/ttyAMA1"
	#define devr "./txt485_receive"
#endif
//Open Port & Set Port
int SerialInit()
{
    nFd = open(dev, O_RDWR|O_NOCTTY|O_NDELAY);
    if(-1 == nFd)
    {
        perror("Open Serial Port Error!\n");
        return -1;
    }
    if( (fcntl(nFd, F_SETFL, 0)) < 0 )
    {
        perror("Fcntl F_SETFL Error!\n");
        return -1;
    }
    if(tcgetattr(nFd, &stOld) != 0)
    {
        perror("tcgetattr error!\n");
        return -1;
    }
 
    stNew = stOld;
    cfmakeraw(&stNew);//将终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
 
    //set speed
    cfsetispeed(&stNew, BAUDRATE);//115200
    cfsetospeed(&stNew, BAUDRATE);
 
    //set databits
    stNew.c_cflag |= (CLOCAL|CREAD);
    stNew.c_cflag &= ~CSIZE;
    stNew.c_cflag |= CS8;
 
    //set parity
    stNew.c_cflag &= ~PARENB;
    stNew.c_iflag &= ~INPCK;
 
    //set stopbits
    stNew.c_cflag &= ~CSTOPB;
    stNew.c_cc[VTIME]=0;    //指定所要读取字符的最小数量
    stNew.c_cc[VMIN]=1; //指定读取第一个字符的等待时间，时间的单位为n*100ms
                //如果设置VTIME=0，则无字符输入时read（）操作无限期的阻塞
    tcflush(nFd,TCIFLUSH);  //清空终端未完成的输入/输出请求及数据。
    if( tcsetattr(nFd,TCSANOW,&stNew) != 0 )
    {
        perror("tcsetattr Error!\n");
        return -1;
    }
 
    return nFd;
}
 
void SaveData(char *buf, int len)
{

	fd = open(devr, O_WRONLY|O_APPEND);
       	if ( fd < 0 )
		perror("open");

	write(fd, buf, len);	
}

int main(int argc, char **argv)
{
    int nRet = 0;
    char buf[SIZE];
    int cnt = 0;
 
    if( SerialInit() == -1 )
    {
        perror("SerialInit Error!\n");
        return -1;
    }
 
    bzero(buf, SIZE);
    while(1)
    {
        nRet = read(nFd, buf, 1);
        if(-1 == nRet)
        {
            perror("Read Data Error!\n");
            break;
        }
        if(0 < nRet)
        {
            printf("Recv Data: 0x%02X\n",buf[0]);
        }
    }
 
    close(nFd);
    return 0;
}

