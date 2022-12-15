/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:10:24 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/15 16:56:55 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int main() {
	PhoneBook book;
	std::string	input = "";
	book.welcome();
	while (1)
	{
		book.printUsage();
		book.printPrompt();
		book.readCommand(input);
		if (input.compare("ADD") == 0)
			book.addContact();
        else if (input.compare("SEARCH") == 0)
			book.search();
		else if (input.compare("EXIT") == 0)
			break;
		else
			book.cmdError(input);
	}
}
