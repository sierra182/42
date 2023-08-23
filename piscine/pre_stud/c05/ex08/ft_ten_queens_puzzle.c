#include <unistd.h>
#include <stdio.h>
#define SIZE 10

int     is_valid(int sol[SIZE][SIZE], int col, int row)
{
    if ( sol[row - 1][col - 1 == 1 &&
            sol[row - 2][col - 2 == 0]] ||
                sol[row + 1][col - 1] == 1 &&
                    sol[row + 2][col - 2] == 0 )
                        return (0);
    else    return (1);
}

double     ft_qrec(int sol[SIZE][SIZE], int col, int row)
{
    int     i;
    double     sols;
    
    if (is_valid(sol, col, row))
        if (col++ <= 9)
        {
            i = 0;
            row = 0;
            sols = 0;
            while (i++ <= 9)
                sols += ft_qrec(sol[row][col] = 1, col, row++);   
            return (sols);
        }
        else return (1);
    else return (0);
}

int     ft_ten_queens_puzzle(void)
{    
    write(1, "kikoo\n", 6); 
    int sol[SIZE][SIZE];
    int     col, row;
    int     i, j;

    col = 0;
    row = 0;
    i = 0;
    j = 0;
    while (i++ <= SIZE)
        while (j++ <= SIZE)
            sol[i][j] = 0;            
    printf("%f\n", ft_qrec(sol, col, row));
}