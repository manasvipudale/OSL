//Name: Utkarsha Kakade
//PRN NO: 72293279M

#include<fcntl.h> //file control options, define req and arguments for use by func fcntl and open
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>

#define MAX_BUFFER 1024

int main()
{
  int fd,fd1,wr;
  char *avfifo="avfifo";
  char *avfifo1="avfifo1";
  char buff[MAX_BUFFER],str[MAX_BUFFER];
  int words=1,len=0,i=0,line=1,c=0;
  FILE *fp;
  
  /*Create the FIFO(named pipe)*/
  mkfifo(avfifo1,0666);
  mkfifo(avfifo,0666);

  /*open,read and display the message from the FIFO*/
  fd=open(avfifo,O_RDWR);

  printf("\n\nEnter a sentence ending with 0:\n"); 
  while(str[i]!='0')
   {
	i++;
	scanf("%c",&str[i]);
   }

  write(fd,str,sizeof(str));
  i=0;

  read(fd,buff,MAX_BUFFER);
  printf("\nFirst Message recieved: %s \n",buff);
  while(buff[i]!='0')
  {
  	 if(buff[i]==' ' || buff[i]=='\n')
  	 {
		words++;
		if(buff[i]=='\n')
		    line++;
   	 }
	 else
		c++;
   	i++;
  }

  printf("\n total characters=%d\n",c);
  printf("\n total words=%d\n",words);
  printf("\n total lines=%d\n",line);

  fp=fopen("test.txt","w+");
  fprintf(fp,"\n total characters=%d\n",c);
  fprintf(fp,"\n total words=%d\n",words);
  fprintf(fp,"\n total lines=%d\n",line);
  fputs("This is testing for fputs...\n",fp);
  fclose(fp);
  close(fd);
  
  fd1=open(avfifo1,O_RDWR);
  wr=write(fd1,&c,sizeof(c));
  wr=write(fd1,&words,sizeof(words));
  wr=write(fd1,&line,sizeof(line));
  if(wr==-1)
  {
	printf("\nError writing in second pipe..!\n");
	return 0;
  }
  else
	printf("\nSuccessful writing in second pipe..!\n");
  close(fd1);

  return 0;
}


