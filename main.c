#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/ioctl.h>
#include<netinet/in.h>
#include<net/if.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	struct ifreq ifr;

	ifr.ifr_addr.sa_family = AF_INET;
	strcpy(ifr.ifr_name, "eth0");

	ioctl(fd, SIOCGIFADDR, &ifr);
	close(fd);

	struct sockaddr_in *sa = (struct sockaddr_in *)&ifr.ifr_addr;
	char *ip_addr = (char *)inet_ntoa(sa->sin_addr);

	printf("IP Address is: %s\n", ip_addr);
	return 0;
}
