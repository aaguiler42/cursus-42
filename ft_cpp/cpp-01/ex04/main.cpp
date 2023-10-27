/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:41:08 by aaguiler          #+#    #+#             */
/*   Updated: 2022/10/30 19:47:11 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

void ft_check_args(int argc)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		exit(1);
	}
}

std::string ft_get_content(std::string filename)
{
	std::ifstream original_file;

	original_file.open(filename);
	if (!original_file.is_open())
	{
		std::cout << "Error: file could not be opened" << std::endl;
		exit (1);
	}

	std::stringstream content;
	content << original_file.rdbuf();
	original_file.close();

	return (content.str());
}

void ft_replace(std::string filename, std::string content, std::string s1, std::string s2)
{
	std::ofstream			out_file;
	int	n;
	int	start;

	out_file.open(filename + ".replace");
	if (!out_file.is_open())
	{
		std::cout << "Error: file could not be created" << std::endl;
		exit (-1);
	}

	start = 0;
	n = content.find(s1);
	while (n != -1)
	{
		out_file << content.substr(start, n - start);
		out_file << s2;
		start = n + s1.size();
		n = content.find(s1, start);
	}

	out_file << content.substr(start);
	out_file.close();
}

int main(int argc, char **argv) {
	ft_check_args(argc);

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	std::string content = ft_get_content(filename);

	ft_replace(filename, content, s1, s2);

	std::cout << content << std::endl;
}
