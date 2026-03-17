/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:59:29 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/17 12:40:45 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


enum
{
	CHAR = 1,
	INT,
	FLOAT,
	DOUBLE
};

int check_char(std::string const &argv)
{
	int argv_size = argv.size();

	if (argv_size == 0)
		return (0);
	if (argv[0] == '\'' && argv_size == 3)
	{
		if (argv[2] == '\'' && std::isprint(argv[1]))
			return (CHAR);
	}
	return (0);
}

int check_int(std::string const &argv)
{
	char *end = NULL;
	long value = strtol((argv).c_str(), &end, 10);
	if (end == argv.c_str())
		return (0);
	if (*end == '\0' && (value >= INT_MIN && value <= INT_MAX))
		return (INT);
	return (0);
}

int check_float(std::string const &argv)
{
	char *end = NULL;
	strtof((argv).c_str(), &end);
	if (end == argv.c_str())
		return (0);
	if (*end == 'f' && *(end + 1) == '\0')
		return (FLOAT);
	return (0);
}

int check_double(std::string const &argv)
{
	char *end = NULL;
	strtod((argv).c_str(), &end);
	if (end == argv.c_str())
		return (0);
	if (*end == '\0')
		return (DOUBLE);
	return (0);
}

int	detect_type(std::string const &argv)
{
	if (argv == "-inff" || argv == "+inff" || argv == "nanf")
    	return (FLOAT);
	if (argv == "-inf" || argv == "+inf" || argv == "nan")
    	return (DOUBLE);
	if (check_char(argv))
		return (CHAR);
	else if (check_int(argv))
		return (INT);
	else if (check_float(argv))
		return (FLOAT);
	else if (check_double(argv))
		return (DOUBLE);
	else
		return (0);
};

int get_precision(std::string const &argv)
{
	int start = argv.find('.');
	if (argv.find('.') == std::string::npos)
		return (1);
	int i = 1;
	while (argv[start + i] && argv[start + i] != 'f')
		i++;
	return (i - 1);
}

void ScalarConverter::convert(std::string const &argv)
{
	char *end = NULL;
	switch (detect_type(argv))
	{
	case CHAR:
	{
		long value = argv[1];
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		std::cout << "int: " << value << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(get_precision(argv)) << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(get_precision(argv)) << static_cast<double>(value) << std::endl;
		break;
	}
	case INT:
	{
		long value = strtol((argv).c_str(), &end, 10);
		if (value < 0 || value > 127)
    		std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(static_cast<int>(value)))
    		std::cout << "char: Non displayable" << std::endl;
		else
    		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		std::cout << "int: " << value << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(get_precision(argv)) << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(get_precision(argv)) << static_cast<double>(value) << std::endl;
		break;
	}
	case FLOAT:
	{
		float value = strtof((argv).c_str(), &end);
		if (std::isnan(value) || std::isinf(value))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << value << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(value) << std::endl;
		}
		else
		{
			if (value < 0 || value > 127)
    			std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(static_cast<int>(value)))
    			std::cout << "char: Non displayable" << std::endl;
			else
    			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
			if (value < static_cast<float>(INT_MIN) || value > static_cast<float>(INT_MAX))
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(value) << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(get_precision(argv)) << static_cast<float>(value) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(get_precision(argv)) << static_cast<double>(value) << std::endl;
		}
		break;
	}
	case DOUBLE:
	{
		double value = strtod((argv).c_str(), &end);
		if (std::isnan(value) || std::isinf(value))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
			std::cout << "double: " << value << std::endl;
		}
		else
		{
			if (value < 0 || value > 127)
    			std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(static_cast<int>(value)))
    			std::cout << "char: Non displayable" << std::endl;
			else
    			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
			if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(value) << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(get_precision(argv)) << static_cast<float>(value) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(get_precision(argv)) << static_cast<double>(value) << std::endl;
		}
		break;
	}
	default:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		break;
	}
	std::cout << std::resetiosflags(std::ios::floatfield);
};
