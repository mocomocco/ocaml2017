//file operation
//refer the following
//http://www.gnu.org/software/libc/manual/html_node/File-System-Interface.html#File-System-Interface

//S_IREAD
#include <sys/stat.h>
//DIR
#include <dirent.h>
//FILE
#include <stdio.h>
//string
#include <string.h>
#include <errno.h>
//low level io
#include <fcntl.h>
#include <unistd.h>


int open_low_err(char *name, int mode)
{
	int des;
	errno = 0;
	des = open(name, mode);
	//fprintf(stderr, "openerr %s: %s, %d\n", name, strerror(errno), errno);
	return des;
}

void close_low_err(int des) {
	errno = 0;
	close(des);
	//fprintf(stderr, "close %s\n", strerror(errno));
}

int main(void){
  const char* dirn = "dir_test";
  const char* filn = "file_test";

  //make dir
  mkdir(dirn,S_IREAD|S_IWRITE|S_IEXEC);
  //make file
  char filepath[64];
  strcpy(filepath,dirn);
  strcat(filepath,"/");
  strcat(filepath,filn);
  FILE *fp = fopen(filepath,"w+");
  fprintf(fp, "test1234567890\n");
  fclose(fp);

  int des = open_low_err(filepath, O_RDONLY);
  printf("%d\n",des);
  char str[20];
  for (int i = 0; i < 5; i++) {
	  read(des, str, sizeof(char));
	  write(STDOUT_FILENO, str, sizeof(char));
	  read(des, str, sizeof(char));
	  write(STDOUT_FILENO, str, sizeof(char));
	  read(des, str, -sizeof(char));
	  write(STDOUT_FILENO, str, sizeof(char));
  }
  close_low_err(des);

}
