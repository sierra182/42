#include <unistd.h>
#include <stdio.h>
#define SIZE 10

int     ft_is_diags_valid(int sol[SIZE][SIZE], int col)
{
    int     i, j;  
    int     diag;

    i = -1;
    j = -1; 
    diag = 0;      
    while (++i < SIZE)
    {    
        while (++j <= col)
        {
            while (i + ++diag < SIZE || i - diag >= 0 || j + diag <= 0)
                if (sol[i][j] >= 0 && j + diag <= col &&
                        (i + diag < SIZE && sol[i + diag][j + diag] >= 0 ||
                            i - diag >= 0 && sol[i - diag][j + diag] >= 0))                        
                                return (0);
            diag = 0;
        }
        j = -1;
    }            
    return (1);
}

int     ft_is_hor_valid(int sol[SIZE][SIZE], int row, int col)
{   
    int     n;

    n = 0; 
    while (col >= 0)
        if (sol[row][col--] >= 0)            
            if (++n > 1) 
                return (0);
    return (1);
}

int     ft_is_all_valid(int sol[SIZE][SIZE], int col)
{       
    int     i, j;
 
    i = -1;
    j = -1;   
    while (++i < SIZE)       
        if (!ft_is_hor_valid(sol, i, col)) 
            return (0);                   
    if (!ft_is_diags_valid(sol, col))
       return (0);
    return (1);
}

int     ft_qrec(int sol[SIZE][SIZE], int col)
{
    int     i, j;
    int     row;        
    int     sol_cp[SIZE][SIZE];
    int     sols;

    i = -1;
    j = -1;
    while (++i < SIZE)
    {
        while (++j < SIZE)                    
            sol_cp[i][j] = sol[i][j];   // use struct
        j = -1;  
    } 
    if (ft_is_all_valid(sol_cp, ++col - 1))
        if (col < SIZE)
        {       
            i = 0;
            row = 0;
            sols = 0;
            while (i++ < SIZE)       
            {            
                sol_cp[row][col] = row;                
                sols += ft_qrec(sol_cp, col);   
                sol_cp[row++][col] = -1;   
            }   
            return (sols);
        }
        else 
        {            
            i = -1;
            j = -1;
            while (++j < SIZE)
            {
                while (++i < SIZE)
                    if (sol[i][j] != -1)
                        write(1, &(char){sol[i][j] + '0'}, 1);
                i = -1;              
            }
            write(1, "\n", 1); 
            return (1);
        }
    else return (0);
}

int     ft_ten_queens_puzzle(void)
{       
    int     col;
    int     i, j;
    int sol[SIZE][SIZE];

    col = -1;
    i = -1;
    j = -1;
    while (++i < SIZE)
    {
        while (++j < SIZE)           
            sol[i][j] = -1;  
        j = -1;    
    }       
    printf("%d\n", ft_qrec(sol, col)); 
}