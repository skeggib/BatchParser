#ifndef BATCHPARSER_BATCHARGUMENT_H
#define BATCHPARSER_BATCHARGUMENT_H

#include <string>

using namespace std;


namespace BatchParser {

/**
 * @brief Argument d'une instruction
 * @details Argument d'une instruction represente par un nom et une valeur, le
 * nom et la valeur peuvent etre vides. Par exemple '-o /home/user/out.txt' :
 * le nom est '-o' et la valeur est '/home/user/out.txt'
 * 
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

#endif // BATCHPARSER_BATCHARGUMENT_H