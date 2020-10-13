#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

struct timeval tv1, tv2, dtv;
struct timezone tz;

typedef unsigned long long TimeVal;

void time_startG()
{
	gettimeofday(&tv1, &tz);
}

long time_stopG()
{
	gettimeofday(&tv2, &tz);
	dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
	dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
	if(dtv.tv_usec < 0)
	{
		dtv.tv_sec--;
		dtv.tv_usec += 1000000;
	}
	return dtv.tv_sec * 1000 + dtv.tv_usec / 1000;
	
}

static __inline__ TimeVal getticks()
{
	unsigned a, d;
	asm("cpuid");
	asm volatile ("rdtsc" : "=a" (a), "=d" (d));
	return (((TimeVal)a) | (((TimeVal) d) << 32));
}

long double exp_(long double x)
{
	long double eps = 0.000001;
	long double s = 1, n = 1, a = 1;
	while(1)
	{
		a *= x / n;
		if(fabs(a) <= eps)
			break;
		s += a;
		n++;
	}
	return s;    
}


double _clock(long n, double x)
{
	double total;
	clock_t start, stop;
	start = clock(); //Clock
	for(int i = 0; i < n; i++)
    		exp_(x);
	stop = clock(); //clock
	total = (stop - start);
	printf("_clock: %lf\n", total / 1000000);
	return total / 1000000;
}
double _clock1(long n, double x)
{
	double total;
	clock_t start, stop;
	start = clock(); //Clock
	for(int i = 0; i < n; i++)
    		exp_(x);
	stop = clock(); //clock
	total = (stop - start);
	//printf("_clock: %lf\n", total / 1000000);
	return total / 1000000;
}

double _gettime(long n, double x)
{
	time_startG(); //gettimeofday 
	for(int i = 0; i < n; i++)
    		exp_(x);
    printf("_gettime: %lf\n", (time_stopG() / 1000.));
    return time_stopG() / 1000.;
}
double _gettime1(long n, double x)
{
	time_startG(); //gettimeofday 
	for(int i = 0; i < n; i++)
    		exp_(x);
    //printf("_gettime: %lf\n", (time_stopG() / 1000.));
    return time_stopG() / 1000.;
}

double _tsc(long n, double x)
{
	TimeVal tick, tick1, tickh;
    unsigned time = 0;
    tick = getticks(); //tsc
    for(int i = 0; i < n; i++)
    	exp_(x);
    tick1 = getticks(); //tsc_reg
    time = (unsigned)((tick1 - tick) / 1991989);
    printf("_tsc: %lf\n", time / 1000.);
    return time / 1000.;
}
double _tsc1(long n, double x)
{
	TimeVal tick, tick1, tickh;
    unsigned time = 0;
    tick = getticks(); //tsc
    for(int i = 0; i < n; i++)
    	exp_(x);
    tick1 = getticks(); //tsc_reg
    time = (unsigned)((tick1 - tick) / 1991989);
    //printf("_tsc: %lf\n", time / 1000.);
    return time / 1000.;
}

int main()
{
    long n;
    while(n != -1)
    {
    	double pogr1 = 0, pogr2 = 0, pogr3 = 0, x;
    	printf("\nEnter number of cycle operations and countable number:\n");
    	scanf("%ld %lf", &n, &x);
    	for(int i = 0; i < 3; i++)
    	{
    		printf("\nIteracia dlya pogreshnosti: %d\n", i+1);
    		pogr1 += _clock(n, x);
    		pogr2 += _gettime(n, x);
    		pogr3 += _tsc(n, x);
    		
    	}
    	printf("\nAbsolute clock(): %lf ms\n", fabs((pogr1 / 3.) - _clock1(n,x)) * 1000.);
    	printf("Absolute gettimeofday(): %lf ms\n", fabs((pogr2 / 3.) - _gettime1(n,x)) * 1000.);
    	printf("Absolute tsc(): %lf ms\n", fabs((pogr3 / 3.) - _tsc1(n,x)) * 1000.);
    	printf("\nOtnosit clock(): %lf\n", _clock1(n,x) / (pogr1 / 3.));
    	printf("Otnosit gettimeofday(): %lf\n", _gettime1(n,x) / (pogr2 / 3.));
    	printf("Otnosit tsc(): %lf\n", _tsc1(n,x) / (pogr3 / 3.));
    }
    return 0;
}
