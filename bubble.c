#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
void bubble_sort(int , int []);                                                               
int main()		                                                      
{   
	   char str1[30],str2[30];
	   char *a1[30]={str2,"NULL"};
	   int arr[30];                                                        
         int i,size,status; 
	   pid_t pid;  
	   do
	   {                                               
      	 printf("Enter total no. of elements : ");
 	  	 scanf("%d",&size);
 	   	 printf("Enter the array\n ");
	 	 for(i=0; i<size; i++)
	 	 {
 	 		 printf("Enter %d element : ",i+1);
  	 		 scanf("%d",&arr[i]);
		 }                                                                          
      	bubble_sort(size, arr);                                        
       	printf("after sorting\n");                        
       	for(i = 0; i<size;i++)
		{
			sprintf(str1,"%d",arr[i]); 
			//String Print. Instead of printing on console it stores output on char buffer                         	
			strcat(str1," ");
			strcat(str2,str1);		
		} 
		printf("%s",str2);                            
       	printf("\n");
		//vfork creates new process,Child process suspends execution of parent process until
		//child process completes its execution as both processes share the same address space.
		if((pid=vfork())<0)
		{
			perror("fork"); //prints error mesg
			exit(0); //exited program, successful termination 
		}
		if(pid==0)
		{

			execve("./binary",a1,NULL);   
			perror("str3");
			exit(1); //unsuccessful termination of program
		}
	   }while(wait(&status)!=pid);    // wait func will suspend execution of calling thread until status info for one of its terminated child process 
						    //is available.                                   
	   printf("\n");
	   return 0;
}                                                       
   
void bubble_sort(int n, int arr[])
{                                                           
       int i,j,t;                                                                                                           
       for(i=0;i< n-1;i++)                               
          for(j=0;j<n-i-1;j++)                             
             if(arr[j]>arr[j+1])                                
             {
                t =arr[j];                                    
                arr[j]=arr[j+1];                                 
                arr[j+1] = t;                                      
             }                                                 
}                                                           
          
