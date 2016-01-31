/*
** my_getnbr.c for get_nbr in /home/jacqui_p/rendu/CPE_2015_Pushswap/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Sun Nov 22 16:36:02 2015 Pierre-Emmanuel Jacquier
** Last update Sun Nov 22 16:36:08 2015 Pierre-Emmanuel Jacquier
*/

int	my_mix(int pos, int len, char *str, int sign)
{
  int		i;
  int		n;
  unsigned int	tmp;

  i = pos;
  n = 0;
  if (len < 10 || (len < 11 && str[pos] < '3'))
    {
      while (i < len + pos)
	{
	  tmp = n * 10 + (str[i] - '0');
	  if (sign > 0 && tmp > 2147483647)
	      return (0);
	  else if (sign < 0 && tmp > 2147483648)
	      return (0);
	  else
	    {
	      n = tmp;
	    }
	  i = i + 1;
	}
      return (sign * n);
    }
  return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	pos;
  int	len;
  int	sign;

  sign = 0;
  i = 0;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    {
      if (str[i] == '-')
	sign = sign + 1;
      i = i + 1;
    }
  pos = i;
  if (sign % 2 == 1)
    sign = -1;
  else
    sign = 1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      i = i + 1;
    }
  len = i - pos;
  return (my_mix(pos, len, str, sign));
}
