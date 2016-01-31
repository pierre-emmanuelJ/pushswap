/*
** lower_number_found.c for lower_number_found in /home/jacqui_p/rendu/CPE_2015_Pushswap/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Fri Nov 20 17:55:09 2015 Pierre-Emmanuel Jacquier
** Last update Sun Nov 22 22:38:08 2015 Pierre-Emmanuel Jacquier
*/

#include "push_swap.h"

int	find_lowest_number(int *l_a, int ac)
{
  int	i;
  int	min;
  int	pos_min;

  i = 0;
  pos_min = 0;
  min = l_a[0];
  while (i < ac)
    {
      if (min > l_a[i])
	{
	  min = l_a[i];
	  pos_min = i;
	}
      i++;
    }
  return (pos_min);
}

void	rotate(int *l_a, int count)
{
  int	i;
  int	save;

  if (count < 2)
    return ;
  i = 0;
  save = l_a[0];
  while (i < count - 1)
    {
      l_a[i] = l_a[i + 1];
      i++;
    }
  l_a[count - 1] = save;
}
