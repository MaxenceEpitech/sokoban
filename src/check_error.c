/*
** check_error.c for check_error in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed May 10 13:26:15 2017 fourrier maxence
** Last update Sat May 13 15:30:53 2017 fourrier maxence
*/

#include "my.h"

int		check_player(char **tab)
{
  int		y;
  int		x;
  int		p;

  y = 0;
  p = 0;
  while (tab[y])
    {
      x = 0;
      while (tab[y][x])
	{
	  if (tab[y][x] == 'P')
	    p++;
	  x++;
	}
      y++;
    }
  if (p != 1)
    return (1);
  return (0);
}

int		check_contains(char **tab)
{
  int		y;
  int		x;
  int		box;
  int		hole;

  box = 0;
  hole = 0;
  y = 0;
  while (tab[y])
    {
      x = 0;
      while (tab[y][x])
	{
	  if (tab[y][x] == 'O')
	    hole++;
	  if (tab[y][x] == 'X')
	    box++;
	  x++;
	}
      y++;
    }
  if (box != hole)
    return (1);
  return (0);
}

void		check_dim(char **tab)
{
  int		max_width;
  int		max_height;

  max_width = get_max_width(tab);
  max_height = get_max_height(tab);
  while (max_height >= LINES || max_width >= COLS)
    {
      if (getch() == 410)
	{
	  max_height = get_max_height(tab);
	  max_width = get_max_width(tab);
	}
      clear();
      mvprintw(LINES / 2, (COLS / 2) - 10 , "Enlarge the terminal.");
      refresh();
    }
  clear();
}

void		check_error(char **tab)
{
  if (check_contains(tab))
    {
      free(tab);
      my_putstr_error("The map contains ");
      my_putstr_error("not the same number of box and holes.\n");
      exit(84);
    }
  if (check_player(tab))
    {
      free(tab);
      my_putstr_error("Player problem.\n");
      exit(84);
    }
}
