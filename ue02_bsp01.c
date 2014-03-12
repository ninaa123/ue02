/* 
 * File:   ue02_bsp01.c
 * Author: nina
 *
 * Created on 12. März 2014, 18:34
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define samples 10000
#define samplesHalf 5000

void rand_checker(const char* const filename, int (*rand_function)(void)) 
{
    FILE *f;
    int x=0;                                    //x_i
    int y=0;                                    //x_{i+1}
    double chisq=0;                             //chi quadrat
    int e=samples/10;                                    //E from chi^2
    double avg=1/2*RAND_MAX;                       //check return value (type) of rand_max
    int zaehler=0;                           //check 
    int naenner=0;                           //check
    double autoCorrelation=0;                                        
    
    f=fopen(filename,"w");                      //error checking for null pointer
    if(f==NULL) 
    {
        return;                         
    }
    
    for(int i=1;i<(samplesHalf+1);++i)
    {
        x=(rand_function()%10);                 //oder %11? 
        y=(rand_function()%10);         
        fprintf(f,"%d %d | %d %d\n",i,x,i+1,y);
        chisq+=pow((x-e),2)/e;                  // what is e?!
        
        if(i<=(samplesHalf-1))                  //for calculating autocorrelation
            zaehler+=(x-avg)*(y-avg);
        
        naenner+=pow((x-avg),2);
        
    }
    
    autoCorrelation=(double)(zaehler/naenner);
    
    fclose(f);
    
}

int main(int argc, char** argv) 
{
    
    int rand(void);
    
    rand_checker("test.txt", rand());


    return (EXIT_SUCCESS);
}

