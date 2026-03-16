/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:50:01 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/16 16:16:33 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

int main(void)
{
	srand(time(NULL));
	Base *base = generate();
	identify(base);
	Base &r_base = *base;
	identify(r_base);
	delete base;
	return (0);
};
