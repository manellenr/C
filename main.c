/*
** Made by Nouar Manelle
** Login <manellenouar@yahoo.fr>
** 
** Started on Thu Jan 24 20:21:33 2020 Thibaut Cornolti
*/

static char	* get_result(char * temps1, char * temps2, int * negative)
{
  if (temps1[0] == '-' && temps2[0] == '-')
    {
      *negative = 1;
      return (my_infin_add(&temps1[1], &temps2[2]));
    }
  else if (temps1[0] == '-' && temps2[0] != '-')
    if (my_infin_cmp(&temps1[1], temps2) > 0)
      {
	*negative = 1;
	return (my_infin_sub(&temps1[1], temps2));
      }
    else
      return (my_infin_sub(temps2, &temps1[1]));
  else if (temps1[0] != '-' && temps2[0] == '-')
      if (my_infin_cmp(temps1, &temps2[1]) < 0)
	{
	  *negative = 1;
	  return (my_infin_sub(&temps2[1], temps1));
	}
      else
	return (my_infin_sub(temps1, &temps2[1]));
  else
    return (my_infin_add(temps1, temps2));
}

char * add(char *nb1, char *nb2)
{
  char * res ;
  char * temps1 ;
  char * temps2 ;
  int negative;

  negative = 0;
  temps1 = my_strdup(nb1);
  temps2 = my_strdup(nb2);
  if (!are_correct_operandes(temps1, temps2))
    return (NULL);
  res = remove_zeros(get_result(temps1, temps2, &negative));
  free(temps1);
  temps1 = 0;
  free(temps2);
  temps2 = 0;
  if (negative)
    {
      my_revstr(res);
      res = (my_strcat(res, my_strdup("-")));
      my_revstr(res);
    }
  return (res);
}