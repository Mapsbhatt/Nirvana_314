#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int a[4][4]={0};
int *ptr[16];
int val[2]={0};
int pos[4]={0};
int i,j, k, l,m, n; 

void assign()
{
    int c=0;
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            ptr[c]= &a[x][y];
            c++;
        }
    }
}

void ranvalue(int *valv)
{
    srand(time(NULL));
    if((rand()%10)<5)
    {
        *valv= 2;
        *(valv+1)=2;
    }
    else
    {
        *valv= 2;
        *(valv+1)=4;
    }
}

void ranpos(int *posi)
{
    srand(time(NULL));
    for(int x=0; x<4; x++)
    {
        *posi= rand()%4;
        posi++;
    }
}

void initpos()
{
    ranpos(&pos[0]);
    ranvalue(&val[0]);
    i= pos[0];
    j= pos[1];
    k= pos[2];
    l= pos[3];
    m= val[0];
    n= val[1];

    a[i][j]= m;          // What if i=k and j=l, for that try and write if-else statement.
    a[k][l]= n;
}


void up(int arr[4][4])
{   printf("");
    for(int y=0; y<4; y++)
    {
        for(int x= 3;x>=0; x-- )
        {
            if(arr[x][y]!=0)
            {   

                if(arr[x][y]== arr[x-1][y])
                {
                    arr[x-1][y]= arr[x-1][y]+arr[x][y];
                    arr[x][y]=0;
                    if(arr[x-1][y]== arr[x-2][y])
                    {
                        break;

                    }
                   
                }
                if(arr[x-1][y]==0)
                {
                   arr[x-1][y]= arr[x-1][y]+arr[x][y];
                   arr[x][y]=0; 
                }
                if(arr[x][y]!= arr[x-1][y])
                {continue;}

            }
            if(arr[x][y]==0)
                {continue;}
        }
    }
}  


void down(int arr[4][4])
{  
    for(int y=0; y<4; y++)
    {   //printf("12");
        for(int x=3 ;x>1 ; x-- )
        {
            if(arr[x][y]!=0)
            {   

                if(arr[x][y]== arr[x-1][y])
                {
                    arr[x][y]= arr[x-1][y]+arr[x][y];
                    arr[x-1][y]=arr[x-2][y];
                    arr[x-2][y]=0;
                    /*if(arr[x-1][y]== arr[x-2][y] && arr[x-1][y]!=0  && arr[x-2][y]!=0 )
                    {
                        break;

                    }*/
                   
                }
                if(arr[x-1][y]==0)
                {
                   arr[x-1][y]= arr[x-2][y];
                   arr[x-2][y]=0; 
                }
                if(arr[x][y]!= arr[x-1][y])
                {continue;}

            }
            if(arr[x][y]==0)
            {
                if(arr[x][y]==0 && arr[x-1][y]==0 )
                {
                    arr[x][y]=arr[x-2][y];
                    arr[x-2][y]=0;
                }
                if(arr[x-1][y]!=0)
                {
                    if(arr[x-2][y]== arr[x-1][y])
                    {
                        arr[x][y]= arr[x-2][y] + arr[x-1][y];
                        arr[x-1][y]=arr[x-2][y]=0;
                    }
                    else
                    {
                        arr[x][y]=arr[x-1][y];
                        arr[x-1][y]=arr[x-2][y];
                        arr[x-2][y]=0;
                    }
                }
            }
        }
    }
}  


void left(int arr[4][4])
{   printf("");
    for(int x=0; x<4; x++)
    {
        for(int y= 3;y>0; y--)
        {
            if(arr[x][y]!=0)
            {   

                if(arr[x][y]== arr[x][y-1])
                {
                    arr[x][y-1]= arr[x][y-1]+arr[x][y];
                    arr[x][y]=0;
                    if(arr[x][y-1]== arr[x][y-2])
                    {
                        break;

                    }
                   
                }
                if(arr[x][y-1]==0)
                {
                   arr[x][y-1]= arr[x][y-1]+arr[x][y];
                   arr[x][y]=0; 
                }
                if(arr[x][y]!= arr[x][y-1])
                {continue;}

            }
            if(arr[x][y]==0)
                {
                if(arr[x][y-1]==arr[x][y-2])
                {
                   arr[x][y-2]= arr[x][y-2]+arr[x][y-1];      
                   arr[x][y-1]=0; 
                }
                }
        }
    }
}  


void right(int arr[4][4])
{   printf("");
    for(int x=0; x<4; x++)
    {
        for(int y=0 ;y<3; y++)
        {
            if(arr[x][y]!=0)
            {   

                if(arr[x][y]== arr[x][y+1])
                {
                    arr[x][y+1]= arr[x][y+1]+arr[x][y];
                    arr[x][y]=0;
                    if(arr[x][y+1]== arr[x][y+2])
                    {
                        break;

                    }
                   
                }
                if(arr[x][y+1]==0)
                {
                   arr[x][y+1]= arr[x][y+1]+arr[x][y];
                   arr[x][y]=0; 
                }
                if(arr[x][y]!= arr[x][y+1])
                {continue;}

            }
            if(arr[x][y]==0)
                {
                if(arr[x][y+1]==arr[x][y+2])
                {
                   arr[x][y+2]= arr[x][y+2]+arr[x][y+1];      
                   arr[x][y+1]=0; 
                }
                }
        }
    }
}  

void key()
{
    char c= getchar();

    if(c== 'w')
    {
        up(a);
    }

    if(c== 's')
    {
        down(a);
    }
    
    if(c== 'a')
    {
        left(a);
    }

    if(c== 'd')
    {
        right(a);
    }

}

void addran()
{
    assign();

    srand(time(NULL));
    int m=0; 
    int b[16];
    for(int x=0; x<16; x++)
    {
       if(*ptr[x]==0)
       {
           b[m]= x;
           m++; 
       }
    }
    int n= rand()%(m+1);
    *ptr[b[n]]= (rand()%10<5)?2:4;
    
}


int main()
{

    initpos();
    for(int x= 0; x<4; x++)
    {
        printf("|");
        for(int y=0; y<4; y++)
        {
          printf("  %d  ", a[x][y]);
        }
        printf("|\n");
    }

    while(1)
    {
        key();
    
        for(int x= 0; x<4; x++)
    {
        printf("|");
        for(int y=0; y<4; y++)
        {
          printf("  %d  ", a[x][y]);
        }
        printf("|\n");
    }
        //score();
        addran();

        if(*ptr[0]!=0 && *ptr[1]!=0 && *ptr[2]!=0 && *ptr[3]!=0 && *ptr[4]!=0 && *ptr[5]!=0 && *ptr[6]!=0 && *ptr[7]!=0 && *ptr[8]!=0 && *ptr[9]!=0 && *ptr[10]!=0 && *ptr[11]!=0 && *ptr[12]!=0 && *ptr[13]!=0 && *ptr[14]!=0 && *ptr[15]!=0) 
        {
            printf("Game Over");
            break;
        }     

        
    }

}