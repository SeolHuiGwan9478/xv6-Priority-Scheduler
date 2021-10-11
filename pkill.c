#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argv, char* argc[]){

	int rst = kill(atoi(argc[1]));

	if(!rst){
		printf(1,"PID# %d is killed\n",atoi(argc[1]));
		exit();
	}
	else{
		printf(1,"PID# %d is wrong\n",atoi(argc[1]));
		exit();
	}

}
