#include<stdio.h>
void main()
{
int i=0,j,fsize,k=0,n=1,r=0;
char s_data[50],r_data[50],stuff[50],s_frame[50],data[50];
printf("enter frame size : ");
scanf("%d",&fsize);
printf("enter data : ");
scanf("%s",data);
while(data[i]!='\0')
{     
	n=1;
        s_frame[0]='S';
     
	for(j=1;j<fsize-1;j++)
        {
           if(data[i]!='\0')
           {
             s_frame[n]=data[i];
             i++;
             n++;
           }
   
        }
        s_frame[n]='E';
     
	for(j=0;j<n+1;j++)
        {
         stuff[k]=s_frame[j];
         k++; 
        }
     
}
 stuff[k]='\0';
printf("after stuffing : %s",stuff);


//at recieving side 

for(j=0;stuff[j]!='\0';j++)
{
      	
	if(stuff[j]!='S'&&stuff[j]!='E')
	{ 
          r_data[r]=stuff[j];
          r++;
	}
	
   r_data[r]='\0';
}
printf("\ndata at recieving side: %s",r_data);
}  




       
