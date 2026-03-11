/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:55:38 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/10 19:42:45 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
	private :
		ScalarConverter();
	public :
		static void convert(std::string const &argv);
};



#endif