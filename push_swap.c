/*
** push_swap.c for push_swap in /home/jacqui_p/rendu/CPE_2015_Pushswap/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Sat Nov 21 23:21:16 2015 Pierre-Emmanuel Jacquier
** Last update Sun Nov 22 22:42:35 2015 Pierre-Emmanuel Jacquier
*/

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int	push_swap(int *l_a, int count)
{
  int	pos_min;
  int	ra_count;

  ra_count = 0;
  pos_min = find_lowest_number(l_a, count);
  while (ra_count <= pos_min)
    {
      rotate(l_a, count);
      ra_count++;
    }
  print_ra(pos_min);
  if (count == 0)
    return (0);
  write(1, "pb ", 3);
  push_swap(l_a, count - 1);
  return (0);
}

int	print_ra(int min)
{
  int	i;

  i = 0;
  while (i < min)
    {
      write(1, "ra", 2);
      write(1, " ", 1);
      i++;
    }
  return (0);
}

void	pa(int ac)
{
  int	i;

  i = 0;
  while (i < ac)
    {
      write(1, "pa", 2);
      if (i < ac -1)
	write(1, " ", 1);
     i++;
    }
  write(1, "\n", 1);
}

int	no_tri(int *l_a, int count)
{
  int	i;

  i = 0;
  while (i < count - 1)
    {
      if (l_a[i] > l_a[i + 1])
	{
	  return (0);
	}
      i++;
    }
  return (-1);
}

int	main(int ac, char **av)
{
  int	*l_a;
  int	count;

  count = 0;
  l_a = malloc(sizeof(int) * ac);
  while (count < (ac - 1))
    {
      l_a[count] = (my_getnbr(av[count + 1]));
      count++;
    }
  if (no_tri(l_a, ac -1) == -1)
    {
      write(1, "\n", 1);
      return (0);
    }
  push_swap(l_a, ac - 1);
  pa(ac - 1);
  free(l_a);
  return (0);
}
