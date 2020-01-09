
#include<stdio.h>
#include<string.h>

#include<arpa/inet.h>

#include<sys/socket.h>

main()
{
	int sd;		//sd= socket descriptor, l=socket length
	char request[1024]="Happy DAY",reply[1024]="";	//request contains your Message to send..
	struct sockaddr_in saddr;

	saddr.sin_family=AF_INET; 			//Family
 	saddr.sin_port=htons(13); 		//Server Port
 	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");	//Server Address 

	sd=socket(PF_INET,SOCK_STREAM,0); 		//SOCKET (AF_INET can be used every where by default)

	printf("Establishing Connection To SERVER\n");	
	connect( sd,(struct sockaddr *)&saddr,sizeof(saddr) );	//CONNECT

	printf("Sending your Message: %s\n",request);
	write( sd,request,sizeof(request) );	//WRITE

     	read( sd,&reply,sizeof(reply) );	//READ
	printf("Reply From SERVER: %s\n",reply);
	
	close(sd);		//CLOSE
}
