#include <cstdint> // include this header for uint64_t
#include <cstring>
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <unistd.h>
#include "city.h"
#ifdef __SSE4_2__
#include "citycrc.h"
#endif


#define verprintf(...) if (verbose > 0)  {printf("In file %s, function %s(), line %d: ",__FILE__,__FUNCTION__,__LINE__); printf(__VA_ARGS__);}
void print_command_line(int argc, char* argv[]);
void print_hostname();

int rot(int64_t key, int i);
int hashg(int64_t key, int i, int s);

void simtime(time_t* starttime_ptr);

