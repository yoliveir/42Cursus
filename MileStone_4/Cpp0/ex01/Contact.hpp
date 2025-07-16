/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:09:19 by yurolive          #+#    #+#             */
/*   Updated: 2025/07/16 15:52:12 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string phoneNumber;
		std::string darkSecret;
		std::string nickname;

	public:
		void setContact(const std::string &, const std::string &, const std::string &
						, const std::string &, const std::string &);
		std::string getField(int index) const;
		void displayFull() const;
		bool isEmpty() const;
};

#endif // CONTACT_HPP
