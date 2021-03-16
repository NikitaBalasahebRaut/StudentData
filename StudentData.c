//  Accept file name, from user and write information of student into the file.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

struct Student
{
	int Rollno;
	char Name[20];
	int marks;
};

void FileWrite(char *name)
{
	int fd = 0,ret = 0,size = 0,i = 0;
	
	struct Student sobj;
	
	fd = open(name,O_WRONLY);
	
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return;
	}
	printf("Enter the no of student\n");
	scanf("%d",&size);
	
	for(i = 1; i <= size; i++)
	{
		printf("Enter roll no \n");
		scanf("%d",&sobj.Rollno);
		printf("Enter the name of student \n");
		scanf("%s",&sobj.Name);
		printf("Enter marks \n");
		scanf("%d",&sobj.marks);
		
		write(fd,&sobj,sizeof(sobj));
	}
	close(fd);
}

void FileRead(char *name)
{
   int fd = 0,ret = 0, size = 0, i = 0;

   struct Student sobj;

    fd = open(name,O_RDONLY);
  
    if(fd == -1)
	{
       printf("unable to open file \n");
       return;
	}

    printf("Data from file is :\n");

    while((ret = read(fd,&sobj,sizeof(sobj))) != 0)
	{
        printf("Roll number is : %d\n", sobj.Rollno);
		printf("Name of student : %s\n",sobj.Name);
		printf("marks : %d\n",sobj.marks);
	}
   
     close(fd);   
}

int main()
{
  char name[20];
  
  printf("Enter file name \n");
  scanf("%s",name);
  
  FileWrite(name);
  
  FileRead(name);
  
  return 0;
}