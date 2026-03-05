/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:16:02 by yurolive          #+#    #+#             */
/*   Updated: 2026/03/03 20:16:02 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data data;

	data.id = 42;
	data.name = "Yuri";
	data.value = 1337.42;

	Data* originalPtr = &data;

	std::cout << "Original pointer: " << originalPtr << std::endl;

	uintptr_t raw = Serializer::serialize(originalPtr);

	std::cout << "Serialized value: " << raw << std::endl;

	Data* deserializedPtr = Serializer::deserialize(raw);

	std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

	if (originalPtr == deserializedPtr)
		std::cout << "✅ Pointers are equal!" << std::endl;
	else
		std::cout << "❌ Pointers are NOT equal!" << std::endl;

	std::cout << "\nAccessing data through deserialized pointer:" << std::endl;
	std::cout << "id: " << deserializedPtr->id << std::endl;
	std::cout << "name: " << deserializedPtr->name << std::endl;
	std::cout << "value: " << deserializedPtr->value << std::endl;

	return 0;
}