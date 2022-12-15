/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:39:01 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/15 17:17:12 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

static int	g_i;

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::welcome() const
{
	std::cout << std::endl;
	std::cout << "\e[33;1mWelcome to the 80s and their unbelievable technology!\nThis is crappy awesome phonebook\e[m" << std::endl;
	std::cout << std::endl;
}

void PhoneBook::addContact()
{
	extern int	g_i;

	contacts[g_i % MAX_INDEX].init();
	++g_i;
}

void PhoneBook::printContacts(void) const
{
	std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
	std::cout << "|     index|     first|      last|  nickname|" << std::endl;
	for (int i = 0; i < MAX_INDEX; ++i)
		contacts[i].view(i);
	std::cout << std::endl;
}

int PhoneBook::getSearchIndex() const
{
	extern int g_i;
	int index = -1;
	bool valid = false;
	do
	{
		std::cout << "Please enter the contact index > " << std::flush;
		std::cin >> index;
		if (std::cin.eof())
			std::exit(EXIT_FAILURE);
		if (std::cin.good() && (0 <= index
				&& index < (g_i < MAX_INDEX ? g_i : MAX_INDEX)))
			valid = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index; please re-enter." << std::endl;
		}
	} while (!valid);
	return (index);
}

void PhoneBook::search(void) const
{
	extern int g_i;

	if (g_i == 0)
	{
		std::cout << "\e[31mcontact is empty\e[m\n" << std::endl;
		return ;
	}
	printContacts();
	int index = getSearchIndex();
	contacts[index].display(index);
}

void PhoneBook::printUsage() const
{
	std::cout << "\n\e[3;2m--------------USAGE---------------" << std::endl;
	std::cout << "There are three types of commands available" << std::endl;
	std::cout << " 1) ADD  \t: To add a contact." << std::endl;
	std::cout << " 2) SEARCH\t: To search for a contact." << std::endl;
	std::cout << " 3) EXIT\t: to quite the PhoneBook." << std::endl;
	std::cout << "----------------------------------\e[m" << std::endl;
}

void PhoneBook::printPrompt() const
{
	std::cout << "\e[32mPlease enter command\n > \e[m" << std::flush;
}

void PhoneBook::readCommand(std::string &input) const
{
	std::cin >> input;
	if (std::cin.eof() || std::cin.bad())
		std::exit(EXIT_FAILURE);
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void PhoneBook::cmdError(std::string &input) const
{
	std::cout << "\e[31m" << input << std::flush;
	std::cout << ": Command not found\e[m" << std::endl;
}
