
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	//used for exit() function

#include<arpa/inet.h>//header makes available the type in_port_t and the type in_addr_t as defined in the description of <netinet/in.h>

#include<sys/socket.h>//The header file socket.h includes a number of definitions of structures needed for sockets. 

main()
{
	int sd,newsd,l;		//sd= socket descriptor, l=socket length

	char received[1024]="",reply[1024]=" Thank You";

	struct sockaddr_in saddr,caddr;	//A sockaddr_in is a structure containing an internet address. 
					//This structure is defined in <netinet/in.h>.
	
//This structure has four fields. The first field is short sin_family, which contains a code for the address family.
 	
	saddr.sin_family=AF_INET; //Family// It should always be set to the symbolic constant AF_INET.
 
//The second field of serv_addr is unsigned short sin_port , which contain the port number. 
//However, instead of simply copying the port number to this field, it is necessary to convert this to network byte order 
//using the function htons() which converts a port number in host byte order to a port number in network byte order.

 	saddr.sin_port=htons(5000); //Server Port

//The third field of sockaddr_in is a structure of type struct in_addr which contains only a single field unsigned long s_addr. 
//This field contains the IP address of the host. For server code, this will always be the IP address of the machine on which the server is running, and there is a symbolic constant INADDR_ANY which gets this address.  	

	saddr.sin_addr.s_addr=htonl(INADDR_ANY); //Server Address or saddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	l=sizeof(struct sockaddr_in);

	sd=socket(PF_INET,SOCK_STREAM,0); //three args: 1st arg is the socket() system call creates a new socket.The address domain of the socket.
					  //2nd arg stream socket in which characters are read in a continuous stream
					  //3 arg is the protocol. If this argument is zero

 	bind( sd,(struct sockaddr *) &saddr,sizeof(saddr) ); //BIND or replace sizeof(saddr) with l
	printf("TCP SERVER Running\n");

	listen(sd,5);	//LISTEN at the port number for connect requests

	while(1)
	{
		printf("Server ready to Accept Connections:\n");		
		newsd=accept( sd,(struct sockaddr *)&caddr,(socklen_t *) &l );	//ACCEPT
		printf("Server Accepted CLIENT Connection\n");
		
		switch( fork() )	//Handle the Client Request, which is done by using fork call

//The purpose of fork() is to create a new process, which becomes the child process of the caller.
		{
			case 0:	//Executed by child process 
				close(sd);
				printf("Iam Child Process:\n");
				read( newsd,&received,sizeof(received) );	//READ
				printf("Message From CLIENT:%s\n",received);

				sleep(2);	//Wait before replying to client // logic to be performed by SERVER

				write( newsd,reply,sizeof(reply) );	//WRITE
				printf("Reply Send to CLIENT\n");

				close(newsd);	//close the newly created socked
				exit(0);	//exit must be used to exit the forked process (<stdlib.h>) 

			default:printf("\n");	//executed when non of the cases is true
		}
	 }
}
