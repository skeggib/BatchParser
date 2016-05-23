#ifndef BATCHPARSER_BATCHSCRIPT_HPP
#define BATCHPARSER_BATCHSCRIPT_HPP

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

#endif // BATCHPARSER_BATCHSCRIPT_HPP
