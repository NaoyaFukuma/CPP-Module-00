/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:40:14 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/15 17:20:29 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getInput(std::string str) const
{
	std::string input = "";
	bool valid = false;
	do
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.bad())
			std::exit(EXIT_FAILURE);
		if (std::cin.good() && !input.empty())
			valid = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input; please try again." << std::endl;
		}
	} while (!valid);
	return (input);
}

void Contact::init()
{
	std::cin.ignore();
	std::cout << "--- Please fill in the contact form. ---" << std::endl;
	firstName = 	getInput("first name     >>> ");
	lastName = 		getInput("last name      >>> ");
	nickname = 		getInput("nickname       >>> ");
	phoneNumber = 	getInput("phone number   >>> ");
	darkestSecret = getInput("darkest secret >>> ");
	std::cout << std::endl;
}

std::string Contact::printLen(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}


void Contact::view(int index) const
{
	if (firstName.empty() || lastName.empty() || nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << std::right << printLen(firstName) << std::flush;
	std::cout << "|" << std::setw(10) << std::right << printLen(lastName) << std::flush;
	std::cout << "|" << std::setw(10) << std::right << printLen(nickname) << std::flush;
	std::cout << "|" << std::endl;
}

void Contact::display(int index) const
{
	if (firstName.empty() || lastName.empty() || nickname.empty())
		return ;
	std::cout << std::endl;
	std::cout << "---->> CONTACT [#" << index << "] <<----" << std::endl;
	std::cout << "First Name    : " << firstName << std::endl;
	std::cout << "Last Name     : " << lastName << std::endl;
	std::cout << "Nickname      : " << nickname << std::endl;
	std::cout << "phoneNumber   : " << phoneNumber << std::endl;
	std::cout << "darkestSecret : " << darkestSecret << std::endl;
	std::cout << std::endl;
}
