#include <unistd.h>
#include <stdio.h>
#define SIZE 10

int     is_valid(int sol[SIZE][SIZE], int col, int row)
{ /*
    if  (row - 1 >= 0 && col - 1 >= 0 &&
        row - 2 >= 0 && col - 2 >= 0 &&

        sol[row - 1][col - 1] >= 0 &&
            sol[row - 2][col - 2] < 0 ||

                row + 1 < SIZE && col - 1 &&
                row + 2 < SIZE && col - 2 &&

                sol[row + 1][col - 1] >= 0 &&
                    sol[row + 2][col - 2] < 0)
                        return (0);
    else return (1); */ return (1);
}

int stop = 0;
double     ft_qrec(int sol[SIZE][SIZE], int col, int row)
{
    int     i, j;        
    int     sol_cp[SIZE][SIZE];
    double     sols;

  
    if (is_valid(sol, col, row))
        if (++col < SIZE)
        {
            /**/
            i = -1;
            j = -1;
            while (++i < SIZE)
            {
                while (++j < SIZE)                    
                    sol_cp[i][j] = sol[i][j];
                j = -1;  
            }                
            i = 0;
            row = 0;
            sols = 0;
            while (i++ < SIZE)       
            {            
                sol_cp[row][col] = row;                
                sols +=  ft_qrec(sol_cp, col, row);   
                sol_cp[row++][col] = -1;   
            }        
            // printf("%d\n", row);
            return (sols);
        }
        else 
        {
            if (stop < 100)
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
    printf("%f\n", ft_qrec(sol, col, row));
}