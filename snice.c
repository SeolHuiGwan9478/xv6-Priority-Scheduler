#include "types.h"
#include "stat.h"
#include "user.h"


int myatoi(char str[])
{
	if (str[0]=='-') {
		return -1*atoi(&str[1]);
	}
	else return atoi(str);
}

int main(int argc, char* argv[]){

	int pid; 
	int rv;
	int val;

	if(argc != 3){
		printf(1,"Usage : snice PID NICE\n");
		exit();
	}

	pid = myatoi(argv[1]); 
	val = myatoi(argv[2]);

	if((rv = setnice(pid, val)) == 0)
		printf(1, "Nice of PID <%d> is set to %d\n", pid, val);
	else if (rv == -1) {
		printf(2, "Error: PID <%d> NOT found! \n", pid);
	}
	else if (rv == -2) {
		printf(2, "Error: Invalide Nice valude: <%d> \n", val);
	}
	exit();
}
