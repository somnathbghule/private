#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEV_PATH "./chr_dev"
int main(int argc, char *argv[]){
    	printf("userland called\n");
	char buff[3]={'h','i','\0'};
	char rbuf[2048];
    	int fd=open(DEV_PATH,O_RDWR);
	if(fd==-1){
		printf("device open failed %s\n",DEV_PATH);
	}
#if 0
	//printf("ioctl: %d\n",ioctl(fd,1,0));
	printf("write: %d\n",(int)write(fd,buff,2));
	printf("read: %d\n",(int)read(fd,rbuf,2));
	printf("rbuf: %s\n",rbuf);
#endif
/*
 *       SEEK_SET
              The file offset is set to offset bytes.

       SEEK_CUR
              The file offset is set to its current location plus offset bytes.

       SEEK_END
              The file offset is set to the size of the file plus offset bytes.
 * 
 * */
	lseek(fd,2,SEEK_SET);
	printf("read: %d\n",(int)read(fd,rbuf,512));
	printf("rbuf:\n %s\n",rbuf);
	lseek(fd,2,SEEK_CUR);
	printf("read: %d\n",(int)read(fd,rbuf,512));
	printf("rbuf:\n %s\n",rbuf);
	close(fd);
	return (0);
}
