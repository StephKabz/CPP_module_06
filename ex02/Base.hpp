/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:36:08 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/16 15:48:26 by kingstephan      ###   ########.fr       */
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

class Base
{
	public:
		virtual ~Base();
};
Base *generate(void);
void identify(Base *p);
void identify(Base &p);
#endif