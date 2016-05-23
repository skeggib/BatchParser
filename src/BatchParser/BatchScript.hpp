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
#include <vector>

using namespace std;

#include "BatchInstruction.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

/**
 * @brief Script batch
 * @details Represente un script batch, contient les instructions du script
 */
class BatchScript {

private:

	vector<BatchInstruction> instructions;

	/**
	 * @brief Parse un script
	 * 
	 * @param script Script a parser
	 */
	void parse(const string & script);

public:

	/**
	 * @brief Constructeur vide
	 * @details Initialise un script vide
	 */
	BatchScript();

	/**
	 * @brief Constructeur par valeur
	 * @details Parse le script passe en parametre
	 * 
	 * @param script Script a parser
	 */
	BatchScript(const string & script);

	/**
	 * @brief Constructeur par copie
	 * 
	 * @param script
	 */
	BatchScript(const BatchScript & script);

	~BatchScript();

	vector<BatchInstruction*> search(string str);

	/**
	 * @brief Nombre d'instructions du script
	 * @return Le nombre d'instructions du script
	 */
	int instructionsCount();

	/**
	 * @brief Lire une instruction
	 * 
	 * @param index Index de l'instruction a lire
	 * @return L'instruction a l'index specifie
	 */
	BatchInstruction * getInstruction(int index);

	/**
	 * @brief Lire le script
	 * @details Genere le script a partir des instructions, le script retourne
	 * peut differer du script donne en parametre a setScript ou au constructeur
	 * @return Le script genere
	 */
	string getScript();

	/**
	 * @brief Paser un script
	 * 
	 * @param script Script a parser
	 */
	void setScript(string script);

}; // class BatchScript

} // namespace BatchParser
} // namespace skeggib
} // namespace com