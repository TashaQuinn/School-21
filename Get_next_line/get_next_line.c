/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbania <jbania@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:20:08 by jbania            #+#    #+#             */
/*   Updated: 2021/11/07 09:38:36 by jbania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd)
{
    char    buf[1];
    char    **line;

    read(fd, buf, 1);
    *line  = ft_strdup(buf);
    return (0);
}

#include <stdio.h>
int main(void)
{
    char *line;
    int fd;

    fd = open("text.txt", O_RDONLY);
    printf("%s\n", line);
}