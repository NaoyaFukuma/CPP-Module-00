/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:25:29 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/15 16:51:59 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_INDEX 8

class PhoneBook
{
  private:
	Contact contacts[MAX_INDEX];
	int getSearchIndex() const;
	void printContacts() const;

  public:
	PhoneBook();
	~PhoneBook();
	void welcome() const;
	void printUsage() const;
	void printPrompt() const;
	void readCommand(std::string &input) const;
	void addContact();
	void search() const;
	void cmdError(std::string &input) const;
};

#endif
