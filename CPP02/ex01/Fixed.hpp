/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <	gkoksal@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:18:30 by gkoksal           #+#    #+#             */
/*   Updated: 2024/10/31 11:19:36 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _frac = 8;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed &operator=(Fixed const &src);

		int getRawBits(void) const;
		void setRawBits(int const bits);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream&, const Fixed& fixed);