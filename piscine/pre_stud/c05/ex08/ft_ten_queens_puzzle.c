#include <unistd.h>
#include <stdio.h>
#define SIZE 4

int test = 0;
int     is_valid(int sol[SIZE][SIZE], int row, int col)
{
    /*
    int     i;
    int     j;

    i = 0;
    j = col;
    while (j-- >= 0)
    {
        //printf(".%d\n", j);
         if (col - i >= 0 && sol[row][col - i] >= 0)
                                return (1);
        if (row - (i + 1) >= 0 && col - (i + 1) >= 0 &&
                sol[row - (i + 1)][col - (i + 1)] >= 0 ||
                    row + (i + 1) < SIZE && col - (i + 1) >= 0 &&
                        sol[row + (i + 1)][col - (i + 1)] >= 0)
                        {
                           
                            
                                return (0);
                        }
        i++;
    }
    //printf("\n");
    return (1);
    */
   /*
 if (test == 0)
    {
        test = 1;
        return 1;
    }*/
  //  int     j;
 // printf("ici:%d:%d\n", row, col);
   // if (col > 0)  
   /*   
    j = col;
    while (j > 0)
    {
      // printf("la:%d:%d\n", row, col);
        
        if (sol[row][col] >= 0)
        { 
            printf("return 0: %d: %d:%d\n", sol[row][col], row, col);
            return (0);

        }
         
        col--;  
        j--;    
    }
    printf("\n");
    return (1);
    */
    /*
    if (row == 0)
        return (0);
    else 
        return (1);
    */
   return (1);
}

int stop = 0;
double     ft_qrec(int sol[SIZE][SIZE], int row, int col)
{
    int     i, j;        
    int     sol_cp[SIZE][SIZE];
    double     sols;
printf("in\n");
    i = -1;
    j = -1;
    while (++i < SIZE)
    {
        while (++j < SIZE)                    
            sol_cp[i][j] = sol[i][j];   // use struct
            j = -1;  
    } 
    if (is_valid(sol_cp, row, ++col))
        if (col < SIZE)
        {       
            i = 0;
            row = 0;
            sols = 0;
            while (i++ < SIZE)       
            {            
                sol_cp[row][col] = row;                
                sols +=  ft_qrec(sol_cp, row, col);   
                sol_cp[row++][col] = -1;   
            }        
            // printf("%d\n", row);
            return (sols);
        }
        else 
        {
            if (stop < 257)
            {
            i = -1;
            j = -1;
            while (++i < SIZE)
            {
                while (++j < SIZE)
                    write(1, &(char){sol[i][j] + '0'}, 1);
                j = -1;
                write(1, "\n", 1);
            }
            write(1, "\n", 1); 
            stop++;
            }  
            return (1);
        }
    else return (0);
}

int     ft_ten_queens_puzzle(void)
{    
    write(1, "kikoo\n", 6); 
    int sol[SIZE][SIZE];
    int     col, row;
    int     i, j;

    col = -1;
    row = 0;
    i = -1;
    j = -1;
    while (++i < SIZE)
    {
        while (++j < SIZE)           
            sol[i][j] = -1;  
        j = -1;    
    }       
    printf("%f\n", ft_qrec(sol, row, col));
    write(1, "qikoo\n", 6);
}