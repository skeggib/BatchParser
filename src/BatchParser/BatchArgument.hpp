/*
Copyright (c) 2016, Klasa Sebastien
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
*  Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
*  Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
*  Neither the name of Klasa Sebastien nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY KLASA SEBASTIEN ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL KLASA SEBASTIEN BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include <string>
using namespace std;


namespace com {
namespace skeggib {
namespace BatchParser {

/**
 * @brief Argument d'une instruction
 * @details Argument d'une instruction represente par un nom et une valeur, le
 * nom et la valeur peuvent etre vides. Par exemple '-o /home/user/out.txt' :
 * le nom est '-o' et la valeur est '/home/user/out.txt'
 */
class BatchArgument {

private:

	string name;
	string value;

public:

	/**
	 * @brief Constructeur vide
	 * @details Initlialise un argument vide
	 */
	BatchArgument();

	/**
	 * @brief Constructeur par valeur
	 * 
	 * @param name Nom de l'argument
	 * @param value Valeur de l'argument
	 */
	BatchArgument(string name, string value);

	/**
	 * @brief Constructeur par copie
	 * 
	 * @param arg
	 */
	BatchArgument(const BatchArgument & arg);

	~BatchArgument();

	/**
	 * @brief Lire le nom de l'argument
	 * @return Le nom de l'argument
	 */
	string getName();

	/**
	 * @brief Definir le nom de l'argument
	 * 
	 * @param name Nom de l'argument
	 */
	void setName(string name);

	/**
	 * @brief Lire la valeur de l'arguement
	 * @return La valeur de l'argument
	 */
	string getValue();

	/**
	 * @brief Definir la valeur de l'argument
	 * 
	 * @param value Valeur de l'argument
	 */
	void setValue(string value);

	bool equals(BatchArgument arg);

}; // class BatchArgument

} // namespace BatchParser
} // namespace skeggib
} // namespace com