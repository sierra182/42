#include <stdlib.h>
#include <unistd.h>

void    print_alloc_error()
{
    char    *err;
    err = "allocation error!\n";
    write(1, err, 18);
}   

void    free_sol_in_malloc_err(char ***sol_heap, int t, int i, int mat_size)
{
    while (t >= 0)
    {   
        i--;
        while (i >= 0)
        {
            free(sol_heap[t][i]);
            i--;
        }
        i = mat_size;
        free(sol_heap[t]);
        t--;
    }
    free(sol_heap);
}

void    free_sol(char ***sol_heap, int n_tetrim, int mat_size)
{   
    int     t;
    int     i;

    t = 0;       
    while (t < n_tetrim)
    {
        i = 0;
        while (i < mat_size)
        {
            free(sol_heap[t][i]);
            i++;
        }
        free(sol_heap[t]);
        t++;
    }
    free(sol_heap);
}

int     main(void)
{
    //char    sol_stack[3][4][4];
    char    ***sol_heap;
    int     n_tetrim;
    int     mat_size;
    int     t;
    int     i;

    n_tetrim = 3;
    mat_size = 4;
    sol_heap = (char ***) malloc(sizeof (char **) * n_tetrim);
    if (!sol_heap)
    {
        print_alloc_error();
        return (1);
    }
    t = 0;   
    while (t < n_tetrim)
    {
        sol_heap[t] = (char **) malloc(sizeof (char *) * mat_size);       
        if (!sol_heap[t])
        {   
            print_alloc_error();
            t--;
            i = mat_size;
            free_sol_in_malloc_err(sol_heap, t, i, mat_size);          
            return (1);
        }
        i = 0;
        while (i < mat_size)
        {
            sol_heap[t][i] = (char *) malloc(sizeof (char) * mat_size);
            if (!sol_heap[t][i])
            {
                print_alloc_error();
                free_sol_in_malloc_err(sol_heap, t, i, mat_size);               
                return (1);
            }
            i++;
        }
        i = 0;
        t++;
    }

    //init sol
    

    free_sol(sol_heap, n_tetrim, mat_size);
    return (0);
}