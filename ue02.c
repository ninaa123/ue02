/* 
 * File:   ue02_bsp01.c
 * Author: nina
 *
 * Created on 12. März 2014, 18:34
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_BINS 10        //Number of bins
#define N_SAMPLES 10000  //Number of total samples

const unsigned int BIN_WIDTH=RAND_MAX/N_BINS;
const double       N_EXPECT  = (double)N_SAMPLES/(double)N_BINS;

void rand_checker(const char* const filename, const char* const filename2, int (*rand_function)(void)) 
{
    FILE *f;
    FILE *fc;
    int x=0; 
    int y=0;
    int counter[10]={0,0,0,0,0,0,0,0,0,0};
    double chisq=0;
    const double avg=1.0/2.0*RAND_MAX;
    double zaehler=0;
    double naenner=0;
    
    f=fopen(filename,"w");                      //error checking for null pointer
    if(f==NULL) 
    {
        return;                         
    }
    
    fc=fopen(filename2,"w");                    //error checking for null pointer
    if(fc==NULL) 
    {
        return;                         
    }
        
    for(int i=0;i<N_SAMPLES/2;++i)
    {
        x=rand_function();
        
        if(i>0 && i<(N_SAMPLES/2-1))
        {
            zaehler+=(y-avg)*(x-avg);
        }
        if(i>0)
            naenner+=pow((y-avg),2);
        
        fprintf(f,"%d ",x);  
        
        chisq+=(double)(pow((x-N_EXPECT),2)/N_EXPECT);
        
        counter[(int)(x/BIN_WIDTH)]+=1;         //count how many numbers in one bin
        if(i%2!=0)
            fprintf(f,"\n");
        y=x;
    }
    
    fprintf(f,"\n");
    fprintf(f,"avg: %lf\n",avg);
    fprintf(f,"chi**2: %lf\n",chisq);
    fprintf(f,"rk: %lf\n",zaehler/naenner);
    
    for(int i=0;i<10;++i)
    {
        fprintf(fc,"%d %d\n",i,counter[i]);
    }
        
    if(f!=0)
        fclose(f);
    
    if(fc!=0)
        fclose(fc);
}

int main(int argc, char** argv) 
{    
    int rand();
    
    rand_checker("dat.txt","counter.txt",rand);
            
    return (EXIT_SUCCESS);
}

