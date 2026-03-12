/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:19:25 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/11 18:31:10 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *new_data = new Data();
	new_data->nbr = 42;
	std::cout << new_data << std::endl;
	uintptr_t raw = Serializer::serialize(new_data);
	std::cout << raw << std::endl;
	Data *recovered = Serializer::deserialize(raw);
	std::cout << recovered << std::endl;
	if (new_data == recovered)
		std::cout << "Success : pointeurs are equals!" << std::endl;
	else
		std::cout << "Failur!" << std::endl;
	delete new_data;
	return (0);
};
