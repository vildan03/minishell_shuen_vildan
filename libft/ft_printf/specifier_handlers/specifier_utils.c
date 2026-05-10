	hex_or_int = 10;
	if (data->specifier == 'x' || data->specifier == 'X')
		hex_or_int = 16;
	if (num < 0)
		num *= -1;
	if (num == 0)
		length = 1;
	while (num > 0)
	{
		length++;
		num /= hex_or_int;
	}
	while (data->precision_set == true && (--precision - length) > 0)
		check_flush_insert(data, '0');
}
