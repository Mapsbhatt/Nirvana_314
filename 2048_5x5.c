#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int a[5][5]={0};
int a1[5][5]={0};
int *ptr[25];
int val[2]={0};
int pos[4]={0};
int pt=0;
int i,j, k, l,m, n; 

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
        *posi= rand()%5;
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

    if(i!=k && j!=l)
    {
        a[i][j]= m;          
        a[k][l]= n;
    }
    else if(i==j==k==l)
    {
        a[1][1]= m;          
        a[2][2]= n;
    }
    else
    {
        a[i][j]= m;          
        a[l][k]= n;
    }
}

void points(int point)
{
    pt= pt+ point;
}

void add_up(int ar[5][5])
{
    int score=0;
    for(int y=0; y<5; y++)
    {
        for(int x=0; x<5; x++)
        {
            if(ar[x][y]== ar[x+1][y])
            {
                ar[x][y]= ar[x][y] + ar[x+1][y];
                switch (x)
                {
                    case 0: ar[x+1][y]=ar[x+2][y];
                            ar[x+2][y]=ar[x+3][y];
                            ar[x+3][y]=ar[x+4][y];
                            ar[x+4][y]=0;
                            break;

                    case 1: ar[x+1][y]=ar[x+2][y];
                            ar[x+2][y]=ar[x+3][y];
                            ar[x+3][y]=0;
                            break;

                    case 2: ar[x+1][y]=ar[x+2][y];
                            ar[x+2][y]=0;
                            break;        

                    case 3: ar[x+1][y]=0;
                            break;  
                }    
                score= score + ar[x][y];        
            }
        }    
    }
    points(score);
}

void up(int arr[5][5])
{
    int n=0;
    int m=0;
    int stor[5];
    for(int y=0; y<5; y++)
    {
        for(int x=0; x<5; x++)
        {
            if(arr[x][y]!=0)
            {
                arr[n++][y]= arr[x][y];
            }
            if(x==4)
            {
                stor[m++]= n;
            }
        }
        n=0;
    }
    m=0;
    for(int y=0, m=0 ; y<5; y++, m++)
    {
        while(stor[m]< 5)
        {
          arr[stor[m]++][y]= 0;
        }
    }
    
    add_up(arr);
}


void add_down(int ar[5][5])
{
    int score=0; 
    for(int y=0; y<5; y++)
    {
        for(int x=4; x>0; x--)
        {
            if(ar[x][y]==ar[x-1][y])
            {
                ar[x][y]= ar[x][y] + ar[x-1][y];
                switch (x)
                {
                    case 4: ar[x-1][y]=ar[x-2][y];
                            ar[x-2][y]=ar[x-3][y];
                            ar[x-3][y]=ar[x-4][y];
                            ar[x-4][y]=0;
                            break;

                    case 3: ar[x-1][y]=ar[x-2][y];
                            ar[x-2][y]=ar[x-3][y];
                            ar[x-3][y]=0;
                            break;

                    case 2: ar[x-1][y]=ar[x-2][y];
                            ar[x-2][y]=0;
                            break;        

                    case 1: ar[x-1][y]=0;
                            break;                        
                            
                }
                score= score + ar[x][y];
            }
        }    
    }
    points(score);
}

void down(int arr[5][5])
{
    int n=4;
    int m=0;
    int stor[5];
    for(int y=0; y<5; y++)
    {
        for(int x=4; x>=0; x--)
        {
            if(arr[x][y]!=0)
            {
                arr[n--][y]= arr[x][y];
            }
            if(x==0)
            {
                stor[m++]= n;
            }
        }
        n=4;
    }
    m=0;
    for(int y=0, m=0 ; y<5; y++, m++)
    {
        while(stor[m]>=0)
        {
          arr[stor[m]--][y]= 0;
        }
    }
    
    add_down(arr);
}


void add_left(int ar[5][5])
{
    int score=0;
    for(int x=0; x<5; x++)
    {
        for(int y=0; y<4; y++)
        {
            if(ar[x][y]== ar[x][y+1])
            {
                ar[x][y]= ar[x][y] + ar[x][y+1];
                switch (y)
                {
                    case 0: ar[x][y+1]=ar[x][y+2];
                            ar[x][y+2]=ar[x][y+3];
                            ar[x][y+3]=ar[x][y+4];
                            ar[x][y+4]=0;
                            break;

                    case 1: ar[x][y+1]=ar[x][y+2];
                            ar[x][y+2]=ar[x][y+3];
                            ar[x][y+3]=0;
                            break;

                    case 2: ar[x][y+1]=ar[x][y+2];
                            ar[x][y+2]=0;
                            break;        

                    case 3: ar[x][y+1]=0;
                            break;  
                }  
                score= score + ar[x][y];          
            }
        }    
    }
    points(score);
}


void left(int arr[5][5])
{
    int n=0;
    int m=0;
    int stor[5];
    for(int x=0; x<5; x++)
    {
        for(int y=0; y<5; y++)
        {
            if(arr[x][y]!=0)
            {
                arr[x][n++]= arr[x][y];
            }
            if(y==4)
            {
                stor[m++]= n;
            }
        }
        n=0;
    }
    m=0;
    for(int x=0, m=0 ; x<5; x++, m++)
    {
        while(stor[m]< 5)
        {
          arr[x][stor[m]++]= 0;
        }
    }
    
    add_left(arr);
}


void add_right(int ar[5][5])
{
    int score= 0; 
    for(int x=0; x<5; x++)
    {
        for(int y=4; y>0; y--)
        {
            if(ar[x][y]==ar[x][y-1])
            {
                ar[x][y]= ar[x][y] + ar[x][y-1];
                switch (y)
                {
                    case 4: ar[x][y-1]=ar[x][y-2];
                            ar[x][y-2]=ar[x][y-3];
                            ar[x][y-3]=ar[x][y-4];
                            ar[x][y-4]=0;
                            break;

                    case 3: ar[x][y-1]=ar[x][y-2];
                            ar[x][y-2]=ar[x][y-3];
                            ar[x][y-3]=0;
                            break;

                    case 2: ar[x][y-1]=ar[x][y-2];
                            ar[x][y-2]=0;
                            break;        

                    case 1: ar[x][y-1]=0;
                            break;                        
                            
                }
                score= score + ar[x][y];
            }
        }    
    }
    points(score);
}

void right(int arr[5][5])
{
    int n=4;
    int m=0;
    int stor[5];
    for(int x=0; x<5; x++)
    {
        for(int y=4; y>=0; y--)
        {
            if(arr[x][y]!=0)
            {
                arr[x][n--]= arr[x][y];
            }
            if(y==0)
            {
                stor[m++]= n;
            }
        }
        n=4;
    }
    m=0;
    for(int x=0, m=0 ; x<5; x++, m++)
    {
        while(stor[m]>=0)
        {
          arr[x][stor[m]--]= 0;
        }
    }
    
    add_right(arr);
}


void key()
{
    fflush(stdin);
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

void assign()
{
    for(int x=0; x<5; x++)
    {
        for(int y =0; y<5; y++)
        {
            a1[x][y]=a[x][y];
        }
    }
}

void addran()
{
    srand(time(NULL));
    int m=0; 
    int c[25];
    int b[25];
    for(int x=0; x<5; x++)
    {
     for(int y=0; y<5; y++)    
       {
        if(a[x][y]==0)
        { 
             b[m]= x;
             c[m++]= y;
        }
       }
    }
    
    int valv_ran = rand()%(m);
    a[b[valv_ran]][c[valv_ran]]= (rand()%10<5)?2:4;
    
}


int checkprev(int arr[5][5], int arr1[5][5])
{
    for(int x=0; x<5; x++)
    {
        for(int y=0; y<5; y++)
        {
            if(arr1[x][y]!=arr[x][y])
            {
                return 0;
            }
        }
    }
}

int main()
{
    int count;
    initpos();


    printf("\tTHE 2048 GAME \n\n\n");


    for(int x= 0; x<5; x++)
    {
        printf("|");
        for(int y=0; y<5; y++)
        {
          printf("\t%d\t", a[x][y]);
        }
        printf("|\n");
    }


    while(1)             
    {
        assign();
        key();
        if(checkprev(a, a1)==0)
        {
            addran();
        }

        for(int x= 0; x<5; x++)
        {
            printf("|");
            for(int y=0; y<5; y++)
            {
            printf("\t%d\t", a[x][y]);
            }
            printf("|\n");
        }

        printf("POINTS:- %d\n\n", pt);


        if(pt>= 2048)
        {
            printf("YOU WON!!!!!!!!!!");
            break;
        }

        count=0;
        for(int x=0; x<5; x++)
        {
            for(int y=0; y<5; y++)
            {
                if(a[x][y]==0)
                {
                    count++;
                }
            }
        }
        if(count==25)
        {
            printf("GAME OVER!!!!");
            break;
        }
        
    }

}