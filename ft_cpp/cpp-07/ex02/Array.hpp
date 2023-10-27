/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:36:55 by aaguiler          #+#    #+#             */
/*   Updated: 2023/02/04 17:48:14 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template<typename T = int>
class Array {
public:
	Array<T>(void){
		_data = NULL;
		_size = 0;
	}

	Array<T>(unsigned int n){
		_data = new T[n]();
		_size = n;
	}

	Array<T>(Array<T> const &src){
		this->_size = src._size;
		this->_data = new T[this->_size]();	
		for (unsigned int i = 0; i < this->_size; i++){
			this->_data[i] =  src._data[i];
		}
	}

	Array<T>	&operator=(Array<T> const &rhs)
	{
		this->_size = rhs._size;
		this->_data = new T[this->_size]();
		for (unsigned int i = 0; i < this->_size; i++){
			this->_data[i] =  rhs._data[i];
		}
		return (*this);
	}

	~Array<T>(void){
		delete [] _data;
	}

	T	&operator[](int index)
	{
		if (index < 0 || (unsigned int) index >= this->_size)
			throw std::exception();
		return this->_data[index];
	}

	unsigned int size(void){
		return _size;
	}
private:
	T *_data;
	unsigned int _size;
};
