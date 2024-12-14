/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:30:54 by gkoksal           #+#    #+#             */
/*   Updated: 2024/10/30 14:59:30 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int _frac = 8;
	public:
		Fixed(void);
		~Fixed();
		Fixed(const Fixed& other);
		Fixed &operator=(Fixed const &src);
		int getRawBits(void) const;
		void setRawBits(int const bits);
};
