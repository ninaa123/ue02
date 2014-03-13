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

void rand_checker(const char* const filename, int (*rand_function)(void)) 
{
    FILE *f;
    int x=0;                                    //x_i
    int y=0;                                    //x_{i+1}
    double chisq=0;                             //chi quadrat
    int e=samples/10;                           //E from chi^2
    int zaehler=0;                            
    int naenner=0;                           
    double autoCorrelation=0;          
    double avg=1.0/2.0*RAND_MAX;
    int n[10][10];
    
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
            n[i][j]=0;
    }
    
    f=fopen(filename,"w");                      //error checking for null pointer
    if(f==NULL) 
    {
        return;                         
    }
       
    x=(rand_function()%10);
    
    for(int i=1;i<(samples+1);++i)
    {
        y=rand_function()%10;
        fprintf(f,"%d %d\n",x,y);
        n[x][y]+=1;
        x=y;
        
/*
        chisq+=pow((x-e),2)/e;                  //calc chi^2
        
        if(i<samples)                           //for calculating autocorrelation
            zaehler+=(x-avg)*(y-avg);
        
        naenner+=pow((x-avg),2);
*/
    }
        
    fprintf(f,"\n");
    int sum[10]={0,0,0,0,0,0,0,0,0,0};
    int sum2[10]={0,0,0,0,0,0,0,0,0,0};

    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            fprintf(f,"%7d ",n[i][j]);
            sum[i]+=n[j][i];
            sum2[i]+=n[i][j];
        }
        fprintf(f," | %5d \n",sum2[i]);
        
        if(i==9)
        {
            fprintf(f,"----------------------------------------------------------------------------------\n");
            for(int k=0;k<10;++k)
            {
                fprintf(f,"%8d",sum[k]);
            }
        }
    }
     
/*
    fprintf(f,"\n");    
    autoCorrelation=(double)(zaehler/naenner);
    fprintf(f,"%lf\n",avg);
    fprintf(f,"%lf\n",chisq);
    fprintf(f,"%lf",autoCorrelation);
*/
    
    fclose(f);  
}

int main(int argc, char** argv) 
{    
    int rand(void);
            
    rand_checker("test.txt", rand);

    return (EXIT_SUCCESS);
}

