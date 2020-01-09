#include<stdio.h>
#include<math.h>

void main()
{
	int ip1[4],ip[4],ip2[4],i;
	long int a,p,n;
	printf("\n\t\tenter the ip Address : ");
	scanf("%d%d%d%d",&ip1[0],&ip1[1],&ip1[2],&ip1[3]);
	printf("\n\tentred ip is : ");
	printf("%d.%d.%d.%d",ip1[0],ip1[1],ip1[2],ip1[3]);
	printf("\n\tEnter the number Number of Subnet");
      scanf("%ld",&n);
					
		if(ip1[0]<=127)
		         {
		    printf("\n\t\tthe entred ip is in class A\n");
		    printf("\n\tthe value n in class is 8");
		    p=pow(2,8);
		    printf("\n\tThe number of ips :- %ld",p);
		    a=p/n;
		    printf("\n\tthe number of the ip address allocated to each subnet %ld ",a);
		    	    
		    ip[0]=255,ip[1]=0,ip[2]=0,ip[3]=0;
		printf("\n\tthe subnet mask is :");
		printf("%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);		         
		         }
		  
		  if(ip1[0]>127&&ip1[0]<=191)
		         {
		    printf("\n\t\tthe entred ip is in class B\n");
	 	     printf("\n\tthe value n in class is 16");
	 	    p=pow(2,16); 
		    a=p/n;
		    printf("\n\tThe number of ips :- %ld",p);
		    printf("\n\tthe number of the ip address allocated to each subnet %ld ",a);
	 	     ip[0]=255,ip[1]=255,ip[2]=0,ip[3]=0;
				printf("\n\tthe subnet mask is :");
				printf("%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);		         
		       }
		
		  if(ip1[0]>191&&ip1[0]<=224)
		         { 
		    printf("\n\t\tthe entred ip is in class C\n");
	                 printf("\n\tthe value n in class is 24");
	                 ip[0]=255,ip[1]=255,ip[2]=255,ip[3]=0;
	      		printf("\n\tthe subnet mask is :");
				printf("%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);		         
		         p=pow(2,24); 
		    a=p/n;
		    printf("\n\tThe number of ips :- %ld",p);
		    printf("\n\tthe number of the ip address allocated to each subnet %ld ",a);
		         }
		  
		  
		  if(ip1[0]>224&&ip1[0]<=239)
		         {
		    printf("\n\t\tthe entred ip in class D\n");
		     printf("\n\tthe value n in class is 32");
		   ip[0]=225,ip[1]=255,ip[2]=255,ip[3]=255;
		printf("\n\tthe subnet mask is :");
		printf("%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);		         
		p=pow(2,32); 
		    a=p/n;
		    printf("\n\tThe number of ips :- %ld",p);
		    printf("\n\tthe number of the ip address allocated to each subnet %ld ",a);	   
			   }	

		         
	printf("\n\n\t\tThe frist ip adderess is:- ");	         	         
	for(i=0;i<4;i++)
	{
	if(ip1[i]<ip[i])
		{
			ip2[i]=ip1[i];
		}
	else
		{
			ip2[i]=ip[i];
		}
     printf("%d",ip2[i]);
     printf(".");     
      }
      
      
      printf("\n\n\t\tThe last ip adderess is:- ");  
 	         	         
	for(i=0;i<4;i++)
	{
	if(ip1[i]>ip[i])
	
		{
			ip2[i]=ip1[i];
		}
	else
		{
			ip2[i]=ip[i];
		}
        			
        printf("%d",ip2[i]);
        printf(".");
      }
      
     
      

 
 
 }
