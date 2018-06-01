/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:38:49 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/01 17:42:05 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_PARAM_H
# define FT_GET_PARAM_H
# include "vm.h"

typedef struct		s_get_param
{
	int		ocp;
	int		(*f_op)(t_info*, t_proc*, int);
}					t_get_param;

struct	s_get_param	tab_ocp[] =
{
	{84, &ft_param_84},
	{88, &ft_param_88},
	{100, &ft_param_100},
	{104, &ft_param_104},
	{116, &ft_param_116},
	{120, &ft_param_120},
	{148, &ft_param_148},
	{164, &ft_param_164},
	{180, &ft_param_180},
	{212, &ft_param_212},
	{228, &ft_param_228},
	{244, &ft_param_244},
};

#endif
