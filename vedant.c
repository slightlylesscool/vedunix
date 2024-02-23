#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

void getdir(char *dirname){
  DIR *dir = opendir(dirname);
  if(dir == NULL){
   printf("No files exit\n");
  }
  
  struct dirent *entry;
  entry = readdir(dir);
  while(entry != NULL){
   if(entry -> d_name[0]!='.'){
     printf("%s\n",entry -> d_name);
    }
    entry = readdir(dir);
  }
  closedir(dir);
}

void gethdir(){
  DIR *dir = opendir(".");
  if(dir == NULL){
   printf("No files exit\n");
  }
  
  struct dirent *entry;
  entry = readdir(dir);
  while(entry != NULL){
   if(entry -> d_name[0]=='.'){
     printf("%s\n",entry -> d_name);
    }
    entry = readdir(dir);
  }
  closedir(dir);
}

void full()
{
   DIR *dir = opendir(".");
  if(dir == NULL){
   printf("No files exit\n");
  }
  
  struct dirent *entry;
  entry = readdir(dir);
  while(entry != NULL){
   if(entry -> d_name[0]!='.'){
     printf("\n%s \t %d \t %ld \t%ld",entry->d_name,entry->d_type,entry->d_ino,entry->d_off);
    }
    entry = readdir(dir);
  }
  closedir(dir);
    }

int main(int argc, char *argv[]){
 int opt;
 char *direct = ".";
 while((opt = getopt(argc,argv, ":flrsaxF:"))!=-1){
  switch(opt){
    case 'l':
      printf("l flag is used\n");
      getdir(direct);
      break;
      
    case 'a':
      printf("a flag is used\n");
      gethdir();
      break;  
    case 'f':
    printf("f flag is used\n");
      full();
      
    case 'F':
    if(optarg!=NULL){
    printf("F flag is used with directory :%s\n",optarg);
      getdir(optarg);}
      else{
       printf("path name required\n");
      }  
      break;
      
    default: 
      printf("Unhandled option");
  }
 }
 
 return 0;
}
