/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:45:48 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/20 15:54:35 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_image {
	int		pbits;
	int		lbytes;
	int		endian;
	char	*buffer;
	char	*dst;
	int		color;
	int		whigs;
	int		htigs;
}				t_image;

typedef struct s_fdf {
	int		larg;
	int		haut;
	int		**vz;
	int		**color;
	int		isomet;
	int		whscrn;
	int		htscrn;
	int		zoom;
	int		elevat;
	double	anglex;
	double	angley;
	int		shiftx;
	int		shifty;
	void	*mlx;
	void	*win;
	void	*img;
	t_image	*igs;
}				t_fdf;

typedef struct s_vect3
{
	float	x;
	float	y;
	int		z;
	int		color;
}				t_vect3;

typedef struct s_pixel {
	float	dltx;
	float	dlty;
	int		pxls;
	float	pxlx;
	float	pxly;
}				t_pixel;

int		**ft_freemem(int **data, int index);
void	ft_freememx(void **data, int index);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
int		ft_strchrbis(char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int		parsemap(t_fdf *data, char *nfile);
void	isometric(float *x, float *y, int z, t_fdf *map);
void	addvect(t_vect3 *v, float x, float y, int color);
void	zoom(t_vect3 *v, t_vect3 *v1, t_fdf *map);
void	shifting(t_vect3 *v, t_vect3 *v1, t_fdf *map);
void	ft_imagemodif(t_fdf *map);
int		key_release(int key, t_fdf *map);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	reimg(t_fdf *map);
int		getnbrline(char *namefile, t_fdf *map);
int		getnbrword(char *lns);
int		closes(t_fdf *map);
int		ft_atoi(const char *str);
void	menudraw(t_fdf *map);

#endif
