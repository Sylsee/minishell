/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:07:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 19:31:02 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

/* *** signal *** */
void	signal_on_exec(void);
void	signal_on_input(void);

/* *** env *** */
void	init_env(char **envp);

#endif
