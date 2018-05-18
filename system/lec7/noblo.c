#include <stdio.h>
#include<unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char const* argv[])
{
  	struct termios save_settings;
	struct termios settings;
	char c;

      	tcgetattr(0,&save_settings);
	settings = save_settings;

	settings.c_lflag &= ~(ECHO|ICANON);  /* 入力をエコーバックしない、バッファリングしない */
  	settings.c_cc[VTIME] = 0;
	settings.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&settings);
	fcntl(0,F_SETFL,O_NONBLOCK);				/* 標準入力からの読み込むときブロックしないようにする */

	while(1){
		printf("\033[02K");
		if((c = getchar()) == EOF){
			printf("\rNO_INPUT ");
		}else if (c == 'q'){
			break;
		}else{
			printf("\rINPUT -> %c ",c);
		}
		fflush(stdout);
		sleep(1);
	}

		tcsetattr(0,TCSANOW,&save_settings);
	return 0;
}
