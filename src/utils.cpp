#include "utils.h"
#include <iostream>
#include <smmintrin.h>


void print_hostname() {
    char hostname[1024];
    hostname[1023] = '\0';
#ifndef _WIN32
    gethostname(hostname, 1023);
#endif
    printf("[%s]: ", hostname);
}

void print_command_line(int argc, char* argv[]) {
	//print command line
	printf("command executed with command line: ");
	char **currentArgv = argv;
	for (int i = 0; i < argc; i ++) {
		printf("%s ", *currentArgv); /* %s instead of %c and drop [i]. */
		currentArgv++; /* Next arg. */
	}
	printf("\n");
}

int rot(int64_t key, int i)
{
    return (key << i)| (key) >>(64-i);
}

inline uint64 CityHash64WithSeed(int64_t key, uint64_t seed)
{
 return CityHash64WithSeed((const char *)&key,8,seed);
}

int hashg(int64_t key, int i, int s)
{
       uint64_t  val0;
       uint64_t  val1;
       uint64_t   val;
       int ss=s;

       val0=CityHash64WithSeed(key,3015) % ss;
       val1=CityHash64WithSeed(key,7793) % ss;
       if (val1==val0) {
           val1 = (val1 +1) % ss;
       }
       if (i==0) val=val0;
       if (i==1) val=val1;
       if (i>1)  val=CityHash64WithSeed(key+i,37*i) % ss;
       return (val %ss);
}

// calculate computing time
void simtime(time_t* starttime_ptr) {
    time_t endtime = time(NULL);
    struct tm * timeinfo=localtime(starttime_ptr);
    double second = difftime(endtime,*starttime_ptr);
    printf("simulation started @: %s \n", asctime(timeinfo));
    timeinfo=localtime(&endtime);
    printf("simulation ended   @: %s \n",asctime(timeinfo));
    printf("simulation time: %f sec \n",second);
}

