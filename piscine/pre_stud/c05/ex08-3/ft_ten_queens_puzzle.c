#include <unistd.h>
#include <stdio.h>
#define SIZE 10

typedef struct 
{        
    int sol[SIZE][SIZE];
} mysol;

int     ft_is_diags_valid(mysol sol, int col)
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
                if (sol.sol[i][j] >= 0 && j + diag <= col &&
                        (i + diag < SIZE && sol.sol[i + diag][j + diag] >= 0 ||
                            i - diag >= 0 && sol.sol[i - diag][j + diag] >= 0))                        
                                return (0);
            diag = 0;
        }
        j = -1;
    }            
    return (1);
}

int     ft_is_hor_valid(mysol sol, int row, int col)
{   
    int     n;

    n = 0; 
    while (col >= 0)
        if (sol.sol[row][col--] >= 0)            
            if (++n > 1) 
                return (0);
    return (1);
}

int     ft_is_all_valid(mysol sol, int col)
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

int     ft_qrec(mysol sol, int col)
{
    int     i, j;
    int     row;  
    int     sols;
   
    if (ft_is_all_valid(sol, ++col - 1))
        if (col < SIZE)
        {       
            i = 0;
            row = 0;
            sols = 0;
            while (i++ < SIZE)       
            {            
                sol.sol[row][col] = row;                
                sols += ft_qrec(sol, col);   
                sol.sol[row++][col] = -1;   
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
                    if (sol.sol[i][j] != -1)
                        write(1, &(char){sol.sol[i][j] + '0'}, 1);
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
    mysol sol;

    col = -1;
    i = -1;
    j = -1;
    while (++i < SIZE)
    {
        while (++j < SIZE)           
            sol.sol[i][j] = -1;  
        j = -1;    
    }       
    printf("%d\n", ft_qrec(sol, col)); 
}