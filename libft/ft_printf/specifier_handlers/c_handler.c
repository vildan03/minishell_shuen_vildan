	{
		while (data->left_align == false && --(width) > 1)
			check_flush_insert(data, ' ');
		check_flush_insert(data, c);
		while (data->left_align == true && --(width) > 1)
			check_flush_insert(data, ' ');
	}
	else
		check_flush_insert(data, c);
}
