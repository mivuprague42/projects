int my_sqrt(int nb, int l, int r)
{
	int	mid;

	if (l > r)
		return (0);
	mid = l + (r - l) / 2;
	if (mid == nb / mid && nb % mid == 0)
		return (mid);
	if (mid > nb / mid)
		r = mid - 1;
	else
		l = mid + 1;
	return my_sqrt(nb, l, r);
}

int	ft_sqrt(int nb)
{
	return my_sqrt(nb, 1, nb);
}
