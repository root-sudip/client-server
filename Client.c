#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXL 10
 
int main(int argc,char **argv[])
{
int udpsocket;
int returnstatus,addrlen;
struct sockaddr_in udpclient,udpserver;
char buf[MAXL];
udpsocket=socket(AF_INET,SOCK_DGRAM,0);
if(udpsocket==-1)
{
printf("could not creat socket \n");
}
else
{
 
printf("socket create successfully \n");
}
udpclient.sin_family=AF_INET;
udpclient.sin_addr.s_addr=inet_addr("127.0.0.1");
udpclient.sin_port = htons(7000);
printf("Binding ...\n");
returnstatus=bind(udpsocket,(struct sockaddr *)&udpclient,sizeof(udpclient));
if(returnstatus==0)
{
printf("Bind done \n");
}
else
{
printf("could not bind \n");
}
while(1){
printf(" > ");
scanf("%s",buf);
if(buf[1]=='x')
{
exit(0);
 
}
else{
udpserver.sin_family=AF_INET;
udpserver.sin_addr.s_addr=inet_addr("127.0.0.1");;
udpserver.sin_port=htons(7000);
returnstatus=sendto(udpsocket,buf,strlen(buf)+1,0,(struct sockaddr*)&udpserver,sizeof(udpserver));
if
(returnstatus==-1)
{
printf("could not sent \n");
}
else
{
printf("Message sent \n");
addrlen=sizeof(udpserver);
returnstatus=recvfrom(udpsocket,buf,MAXL,0,(struct sockaddr *)&udpserver,&addrlen);
if(returnstatus==-1)
{
printf("did not recive confirmation \n");
}
else{
buf[returnstatus]=0;
printf("Received= %s \n",buf);
}
}
}
}
close(udpsocket);
 
return 0;
}
