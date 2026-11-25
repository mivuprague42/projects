void ft_rev_int_tab(int *tab, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		tab[size - 1 - i] = tab[i];
	}
}
