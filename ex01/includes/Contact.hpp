/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:40:30 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/15 17:13:59 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTHPP
# define CONTACTHPP

# include <iomanip>
# include <iostream>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::string printLen(std::string str) const;
	std::string getInput(std::string str) const;

  public:
	Contact();
	~Contact();
	void init();
	void view(int index) const;
	void display(int index) const;
};

#endif
