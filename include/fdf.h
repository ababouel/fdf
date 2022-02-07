/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:36:15 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/04 00:15:24 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../mini/mlx.h"
# include <fcntl.h>

typedef struct t_fdf {
	int		larg;
	int		haut;
	int		**vz;
	int		zoom;
	int		shiftx;
	int		shifty;
	float	angle;	
	void	*mlx;
	void	*win;
	void	*img;
	int		color;
}				t_fdf;

int		**ft_freemem(int **data, int index);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	parsemap(t_fdf *data, char *nfile);
void	drawingmap(t_fdf *map);
void	isometric(float *x, float *y, int z,double angle);

#endif
