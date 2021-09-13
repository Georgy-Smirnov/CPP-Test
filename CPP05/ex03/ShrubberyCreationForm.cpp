#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& tmp) : Form("ShrubberyCreationForm", 145, 137), target(tmp.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& tmp)
{
	if (this == &tmp)
		return (*this);
	*this = tmp;
	return (*this);
}

void ShrubberyCreationForm::action() const
{
	std::ofstream file;

	file.open(target + "_shrubbery");
	file << "	          .     .  .      +     .      .          .\n";
	file <<"     .       .      .     #       .           .\n";
	file <<"        .      .         ###            .      .      .\n";
	file <<"      .      .   *#:. .:##*##:. .:#*  .      .\n";
	file <<"          .      . *####*###*####*  .\n";
	file <<"       .     *#:.    .:#*###*#:.    .:#*  .        .       .\n";
	file <<"  .             *#########*#########*        .        .\n";
	file <<"        .    *#:.  *####*###*####*  .:#*   .       .\n";
	file <<"     .     .  *#######**##*##**#######*                  .\n";
	file <<"                .*##*#####*#####*##*           .      .\n";
	file <<"    .   *#:. ...  .:##*###*###*##:.  ... .:#*     .\n";
	file <<"      .     *#######*##*#####*##*#######*      .     .\n";
	file <<"    .    .     *#####**#######**#####*    .      .\n";
	file <<"            .     *      000      *    .     .\n";
	file <<"       .         .   .   000     .        .       .\n";
	file <<"........................O000O........................\n";
}