#ifndef BATCHPARSER_BATCHINSTRUCTION_H
#define BATCHPARSER_BATCHINSTRUCTION_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#include "BatchArgument.hpp"


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

	// TODO Move split & trim to another class
	vector<string> split(string str, string delimiter) const;
	string trim(string str) const;

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

}; // class BatchInstruction

} // namespace BatchParser

#endif // BATCHPARSER_BATCHINSTRUCTION_H
