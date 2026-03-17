/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:36:08 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/17 13:36:52 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <typeinfo>

class Base
{
	public:
		virtual ~Base();
};
Base *generate(void);
void identify(Base *p);
void identify(Base &p);
#endif