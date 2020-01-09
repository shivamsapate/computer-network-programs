#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
int s_count=0,r_count=0,i,j=0,k=0;
char s_str[50],stuff[50],r_str[50];
printf("enter data : ");
scanf("%s",s_str);
for(i=0;s_str[i]!='\0';i++)
{ 
  stuff[j]=s_str[i];
  j++;
  if(s_str[i]=='1')
  {
    s_count++;
      if(s_count==5)
       {
         stuff[j]='0';
          j++;
          s_count=0;
       }
   }
   else
   {
     s_count=0;
   }
}
printf("\nafter stuffing s_string become:  ");
printf("%s",stuff);
	   
   
 //at recieving side
 
for(i=0;stuff[i]!='\0';i++)
{
     if(stuff[i]=='1')
     {
       r_count++;
         r_str[k]=stuff[i];
         k++;
          if(r_count==5)
          {
            i++;
            r_count=0;
          }
     }
     else
     {
          r_count=0;
          r_str[k]=stuff[i];
          k++;
      }
 }
 r_str[k]='\0';
 printf("\nat reciever end : ");
 printf("%s\n",r_str);
 } 
        				
       
       
         
