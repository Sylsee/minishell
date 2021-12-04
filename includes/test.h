/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 02:56:59 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/03 02:58:27 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

char	**until(char **args, char *c, t_area test);
char	**after(char **args, char *c, t_area test);
t_node	ast(char *s, t_area test);

#endif
