int	find_newline_symbol(char *line)
{
	int	i;

	i = 0;
	if (!(line))
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_newline(char *str)
{
	if (str[0] == '\n')
		return (1);
	return (0);
}

char	*ft_fill_theline(char *remainer)
{
	int		i;
	char	*filled_line;

	i = 0;
	if (!(remainer) || !(remainer[0])) // если остатка нет и нет нулевого элемента, то нулл
		return (NULL);
	while (remainer[i] && remainer[i] != '\n') // узнаем длину остатка для маллока
		i++;
	i += ft_is_newline(&remainer[i]); 
	/* а если нулевой элемент есть и он состоит только из символа новой строки, то мы, 
	так как i = 0, добавляем единицу ??????????????? сдвигаем на одну ячейку вперед?
	*/
	filled_line = malloc(sizeof(char) * (i + 1));//распред память + 1 для символа конц стр
	if (!(filled_line))
		return (NULL);
	i = 0;
	while (remainer[i] && remainer[i] != '\n') //записываем в строку символы после распред памяти
	{
		filled_line[i] = remainer[i];
		i++;
	}
	if (remainer[i] == '\n')
	/* из сабджекта - возвр знач должно инклюдить \n, исключение - конец файла,
	когда \n нет
	*/
	{
		filled_line[i] = remainer[i];
		i++;
	}
	filled_line[i] = '\0';
	/* самостоятельно устанавливаем в конец строки '\0' */
	return (filled_line);
}

char	*after_newline(char *remainer)
{
	int		i;
	int		j;
	char	*after_newline;

	i = 0;
	j = 0;
	if (!(remainer))
		return (NULL);
	while (remainer[i] && remainer[i] != '\n')
		i++;
	if (remainer[i] == '\0')
        free(remainer);
	i = i + ft_is_newline(&remainer[i]);
	after_newline = malloc(sizeof(char) * (ft_strlen(remainer) - i + 1));
	if (!(after_newline))
		return (0);
	while (remainer[i])
		after_newline[j++] = remainer[i++];
	after_newline[j] = '\0';
	/* самостоятельно устанавливаем в конец строки '\0' */
	free(remainer);
	remainer = NULL;
	return (after_newline);
}


char	*check_remainer(char *remainer, char *current_line)
{
	char	*ptr_to_newline_symbol; 

	ptr_to_newline_symbol = NULL;
	if (remainer)
		if ((ptr_to_newline_symbol = ft_strchr(remainer, '\n')))
		{
			*ptr_to_newline_symbol = '\0';
			current_line = ft_strdup(remainer);
			ft_strcpy(remainer, ++ptr_to_newline_symbol);
		}
		else
		{
			current_line = ft_strdup(remainer);
			ft_strclr(remainer);
		}
	else
		current_line = ft_strnew(1);
	return (ptr_to_newline_symbol);
}


char *get_next_line(int fd)
{
    static char *remainer[OPEN_MAX]; 
	/* remainer - то, что осталось в буфере прочитанное, но не записанное, и нужно 
	сохранить, чтобы в следующий раз эту часть приклеить к началу новой строки, 
	его нужно положить в лайн туда до того, как мы что-то прочитаем

	статическая переменная нужна, чтобы прочитанный остаток сохранился в переменной, пока
	мы не вызовем функцию во второй раз, так как все автоматические переменные сразу 
	удаляются */
    char        buffer; // +1 для нуля
	/* buffer - память, в которую будем записывать
	buffer_size - количество символов, которые будем считывать за раз */
    char        *current_line; 
    /* переменная, куда мы складываем промежучный результат соединения
    текущей строки и буффера (в него мы записываем сколько мы считали на данный момент) */
    int         num_of_symbols_was_read; //число считанных символов (1024 или меньше)
    
    if (fd < 0 || BUFFER_SIZE <= 0) // из сабджекта: если ошибка чтения ???
        return (NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!(buffer))
        return (NULL);
    while (!(find_newline_symbol(remainer[fd])) && num_of_symbols_was_read != 0)
    {
        num_of_symbols_was_read = read(fd, buffer, BUFFER_SIZE); 
		/* read не устанавливает в конце строки '\0', а он необходим +
		read не только записывает в буфер количество, которые мы просим, 
		но и возвращает количество считаных байтов */
	   	if (num_of_symbols_was_read <= 0)
            free(buffer);
        buffer[num_of_symbols_was_read] = '\0'; 
		/* самостоятельно устанавливаем в конец строки, индекс элемента 
		которой нам вернул read, '\0' */
        remainer[fd] = ft_strjoin(remainer[fd], buffer);
    }
    free(buffer);
    current_line = ft_fill_theline(remainer[fd]);
    remainer[fd] = after_newline(remainer[fd]);
    return(current_line);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)) > 0)
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
	}
	else
		printf("\n");
	return (0);
}
