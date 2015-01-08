#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#define MAXL 1024
int main(int argc,char **argv[])
{
int i,addrsize;////////////////for gen
int sock_udp,sock_tcp;
int b_in;////binding dec
char sn_ip[20];
struct sockaddr_in udpserver,udpclient;
udpserver.sin_family=AF_INET;
udpserver.sin_addr.s_addr=inet_addr("127.0.0.1");
udpserver.sin_port = htons(7000);
char buf[MAXL];////////////////for messaging 
int recive,send;
///////////////////////////////////////////////
sock_udp=socket(AF_INET,SOCK_DGRAM,0);
if(sock_udp==-1)
{
fprintf(stderr,"Could not create socket \n");
}
else
{
fprintf(stderr,"Created !!! \n");
 
}
 
fprintf(stderr,"Binding \n");
sleep(10);
b_in=bind(sock_udp,(struct sockaddr*)&udpserver,sizeof(udpserver));
if(b_in==0)
{
printf("Bind done ... \n");
}
else
{
printf("Could not create bind \n");
}
while(1)
{
addrsize=sizeof(udpclient);
recive=recvfrom(sock_udp,buf,MAXL,0,(struct sockaddr *)&udpclient,&addrsize);
if(recive==-1)
{
printf("Could not recive message \n");
}
else{
printf("MESSAGE=>%s \n",buf);
printf(" > ");
scanf("%s",buf);
send=sendto(sock_udp,buf,strlen(buf)+1,0,(struct sockaddr *)&udpclient,sizeof(udpclient));
if(send==-1)
{
printf("could not send \n");
}
else{
printf("server successfully sent \n");
 
}
}
 
 
}
 
close(sock_udp);
////////////////////////----------------------------//////////////////////////////////
 
return 0;
}
