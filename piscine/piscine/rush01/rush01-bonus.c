#include <unistd.h>

int	 main()
{
	int	max_row = 3;
	int 	max_col = 5;
	int	row = 0;
	int	col = 0;
	char 	first_char;
	char	middle_char;
	char	last_char;
	
	while(row < max_row)
	{
		if (row == 0)
		{
			first_char = 'A';
			last_char = 'C';
			middle_char = 'B';
		}
		else if (row == max_row - 1)
		{
			first_char = 'C';
                        last_char = 'A';	
                        middle_char = 'B';
		}	
		else 
		{
			first_char = 'B';
                        last_char = 'B';
                        middle_char = ' ';
		}

		while(col < max_col)
		{
			if (col == 0)
			{
				write(1, &first_char, 1);	
			}
			else if(col == max_col - 1)
			{
				write(1, &last_char, 1);
			}
			else 
			{
				write(1, &middle_char, 1);
			}			
			col++;		
		}
		col = 0;
		row++;
		write(1, "\n", 1);
	}

}
