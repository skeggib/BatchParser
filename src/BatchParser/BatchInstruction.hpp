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
#include <iostream>

using namespace std;

#include "StrHelper.hpp"
#include "BatchArgument.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

/**
 * @brief Instruction d'un script batch
 * @details Instruction d'un script batch, representee par sa commande et ses
 * arguments sous la forme d'un liste de BatchArgument
 */
class BatchInstruction {

private:

	string text;
	string command;
	vector<BatchArgument> arguments;

	/**
	 * @brief Parser le texte
	 * @details Parse le texte de l'instruction
	 */
	void parseText();

	/**
	 * @brief Generer le texte
	 * @details Genere le texte a partir de la commande et des arguments
	 */
	void generateText();

public:

	/**
	 * @brief Constructeur vide
	 * @details Initlialise une instruction vide
	 */
	BatchInstruction();

	/**
	 * @brief Constructeur par valeur
	 * @details Parse le texte passe en parametre
	 * 
	 * @param text Texte a parser
	 */
	BatchInstruction(string text);

	/**
	 * @brief Constructeur par copie
	 * 
	 * @param i
	 */
	BatchInstruction(const BatchInstruction & inst);

	~BatchInstruction();

	/**
	 * @brief Lire le texte genere
	 * @details Genere le texte a partir de la commande et des arguments
	 * @return Texte genere de l'instruction
	 */
	string getText() const;

	/**
	 * @brief Parser un texte
	 * 
	 * @param text Texte a parser
	 */
	void setText(string text);

	/**
	 * @brief Lire la commande
	 * @return La commande de l'instruction
	 */
	string getCommand() const;

	/**
	 * @brief Changer la commande de l'instruction
	 * 
	 * @param command Nouvelle commande
	 */
	void setCommand(string command);

	/**
	 * @brief Nombre d'arguments de l'instruction
	 * @return Le nombre d'arguments de l'instruction
	 */
	int argumentsCount() const;

	/**
	 * @brief Lire un argument
	 * 
	 * @param index Index de l'argument a lire
	 * @return L'argument a l'index specifie
	 */
	BatchArgument * getArgument(int index);

	/**
	 * @brief Chercher un argument d'apres son nom
	 * 
	 * @param name Nom de l'argument
	 * @return L'argument correspondant ou NULL s'il n'a pas ete trouve
	 */
	BatchArgument * getArgumentByName(string name);

	/**
	 * @brief Ajouter un argument
	 * @details Ajoute un argument a la fin de la commande
	 * 
	 * @param argument Argument a ajouter
	 */
	void addArgument(BatchArgument & argument);

	/**
	 * @brief Retirer un argument
	 * 
	 * @param index Index de l'argument a retirer
	 */
	void removeArgument(int index);

	/**
	 * @brief Retirer un argument
	 * 
	 * @param argument Argument a retirer
	 */
	void removeArgument(BatchArgument & argument);

	/*!
	 * Verifier si l'instruction contient une chaine de caracteres
	 * @param  str Chaine de caracteres a chercher
	 * @return     True si la chaine de caracteres a ete trouvee
	 */
	bool has(string str);

	/**
	 * @brief Lire la position d'un argument
	 * 
	 * @param arg Argument
	 * @return La position de l'argument
	 */
	int indexOf(const BatchArgument * arg);

}; // class BatchInstruction

} // namespace BatchParser
} // namespace skeggib
} // namespace com