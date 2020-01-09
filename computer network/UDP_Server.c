
#include<stdio.h> 
#include<string.h> 

#include<arpa/inet.h>  

#include<sys/socket.h>

main() 
{
	int sd,l; 	//sd= socket descriptor, l=socket length
 	char received[1024]="", reply[1024]="I Received your request"; 
 	struct sockaddr_in saddr,caddr; 	
	
	saddr.sin_family=AF_INET; 			//Family
 	saddr.sin_port=htons(6000); 			//Server Port or use saddr.sin_port=htons(SERV_PORT);
 	saddr.sin_addr.s_addr=htonl(INADDR_ANY);	//Server Address or saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 	l=sizeof(struct sockaddr_in); 

	sd=socket(PF_INET,SOCK_DGRAM,0); 		//SOCKET (AF_INET can be used every where by default)

 	bind( sd,(struct sockaddr *) &saddr,sizeof(saddr) ); //BIND or replace sizeof(saddr) with l

 	printf("UDP Server Running\n");

	while(1) 
 	{ 
 		recvfrom( sd,received,sizeof(received),0,(struct sockaddr *) &caddr,&l ); //RECEIVE or READ, (sizeof or strlen can be used)	
 		printf("MESSAGE FROM CLIENT: %s\n",received);	//recvfrom requires address of variable storing length of client address

 		sleep(2);	//Wait before replying to client // logic to be performed by SERVER

 		sendto( sd,&reply,sizeof(reply),0,(struct sockaddr *) &caddr,l ); //SEND or WRITE (sizeof or strlen can be used)
 		printf("Reply send to CLIENT\n");  
 	} 
} 
