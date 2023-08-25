#include <unistd.h>
#include <stdio.h>
#define SIZE 4

int test = 0;

int is_test(int row)
{
    if (row == 2)
        return (0);
    else return (1);
}

int     is_diags_valid(int sol[SIZE][SIZE], int col)
{
    int     i, j;  

    i = -1;
    j = -1;       
    while (++i < SIZE)
    {    
        while (++j <= col)
            if (sol[i][j] >= 0 && j + 1 <= col &&
                    (i + 1 < SIZE && sol[i + 1][j + 1] >= 0 ||
                            i - 1 >= 0 && sol[i - 1][j + 1] >= 0))                        
                                return (0);
        j = -1;
    }            
    return (1);
}

int     is_hor_valid(int sol[SIZE][SIZE], int row, int col)
{   
    int     n;

    n = 0; 
    while (col >= 0)
        if (sol[row][col--] >= 0)            
            if (++n > 1) 
                return (0);
    return (1);
}

int     is_all_valid(int sol[SIZE][SIZE], int col)
{       
    int     i, j;
 
    i = -1;
    j = -1;   
    while (++i < SIZE)       
        if (!is_hor_valid(sol, i, col))
            return (0);  
                 
  //  if (!is_diags_valid(sol, col))
  //      return (0);
  //  return (1);
}

int stop = 0;
double     ft_qrec(int sol[SIZE][SIZE], int row, int col)
{
    int     i, j;        
    int     sol_cp[SIZE][SIZE];
    double     sols;
//printf("in\n");
    i = -1;
    j = -1;
    while (++i < SIZE)
    {
        while (++j < SIZE)                    
            sol_cp[i][j] = sol[i][j];   // use struct
            j = -1;  
    } 
    if (1)
        if (++col < SIZE)
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
            if (stop++ < 257)
            {
                if (is_all_valid(sol_cp, col - 1))
                {
                    i = -1;
                    j = -1;
                    while (++i < SIZE)
                    {
                        while (++j < SIZE)
                            write(1, &(char){sol_cp[i][j] + '0'}, 1);                      
                        j = -1;
                        write(1, "\n", 1);
                    }
                    printf("r:%d, c:%d\n", row, col - 1);
                    printf("\n");
                    return (1);
                }                
            }  
            return (0);
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