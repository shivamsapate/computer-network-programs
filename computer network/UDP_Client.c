#include<stdio.h> 
#include<string.h> 

#include<arpa/inet.h>  

#include<sys/socket.h>

main() 
{ 
 	int sd,l; 	//sd= socket descriptor, l=socket length
 	char request[1024]="Hello Server",reply[1024]=""; 
 	struct sockaddr_in saddr; 	
	
	saddr.sin_family=AF_INET; 			//Family
 	saddr.sin_port=htons(6000); 			//Server Port
 	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");	//Server Address 
	l=sizeof(struct sockaddr_in);
	
	sd=socket(PF_INET,SOCK_DGRAM,0); 		//SOCKET (PF_INET can be used every where by default)

	printf("Sending your Message:\n");  
	
	sendto( sd,&request,sizeof(request),0,(struct sockaddr *) &saddr,l ); //SEND or WRITE (sizeof or strlen can be used)
 
 	recvfrom( sd,reply,sizeof(reply),0,(struct sockaddr *) &saddr,&l ); 	//RECEIVE or READ//at client side recvfrom last 2 fields can be NULL, NULL
										//(sizeof or strlen can be used)
 	printf("Reply From Server: %s\n", reply); 

 	close(sd); 	//close the Socket
} 
