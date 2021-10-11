#include "types.h"
#include "stat.h"
#include "user.h"

int fact(int x)
{
	if (x==0) return 1;
	else return x * fact(x-1);
}

int
main(int argc, char *argv[])
{
    int i, j;
	int count = atoi(argv[1]);
	int nice = 20; 
	int sum = 0;
	int t0, t1;

	if (argc < 2) {
		printf(1, "Usage: loop count [nice, default=20] \n");
		exit();
	}
	if (argv[2]) nice = atoi(argv[2]);

	printf(1, "loop count: %d \n", count);

	t0 = uptime();
	setnice(getpid(), nice);

	for (i=sum=0; i<count; i++) {
		if(i == 10 && (getnice(getpid()) == 20)){
			setnice(getpid(), 40);
		}
		for (j=0; j<5000; j++){
			sum += fact(j);
		}
	}
	printf(1, "sum: %d \n", sum);

	t1 = uptime();

	printf(1, "\nNice: %d => Elapsed time: %d\n", getnice(getpid()), t1-t0);

	exit();
}
