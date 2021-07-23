#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int	Account::getNbAccounts(void)
{
	return(_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return(_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	time_t t1 = time(0); 
	struct tm * now = localtime( &t1);
	std::cout << "[" << (now->tm_year + 1900) << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << \
	std::setfill('0') << std::setw(2) <<  now->tm_mday << "_" << std::setfill('0') << std::setw(2) << \
	now->tm_hour << std::setfill('0') << std::setw(2) << now->tm_min << std::setfill('0') << std::setw(2) << \
	now->tm_sec << "]";
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals <<std::endl;
}

Account::Account(int initial_deposit)
{
	time_t t1 = time(0); 
	struct tm * now = localtime( &t1);
	std::cout << "[" << (now->tm_year + 1900) << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << \
	std::setfill('0') << std::setw(2) <<  now->tm_mday << "_" << std::setfill('0') << std::setw(2) << \
	now->tm_hour << std::setfill('0') << std::setw(2) << now->tm_min << std::setfill('0') << std::setw(2) << \
	now->tm_sec << "]";
	std::cout << "index:" << _nbAccounts << ";";
	std::cout << "amount:" << initial_deposit << ";created" << std::endl;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
}

Account::~Account(void)
{
	time_t t1 = time(0); 
	struct tm * now = localtime( &t1);
	std::cout << "[" << (now->tm_year + 1900) << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << \
	std::setfill('0') << std::setw(2) <<  now->tm_mday << "_" << std::setfill('0') << std::setw(2) << \
	now->tm_hour << std::setfill('0') << std::setw(2) << now->tm_min << std::setfill('0') << std::setw(2) << \
	now->tm_sec << "]";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	time_t t1 = time(0); 
	struct tm * now = localtime( &t1);
	std::cout << "[" << (now->tm_year + 1900) << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << \
	std::setfill('0') << std::setw(2) <<  now->tm_mday << "_" << std::setfill('0') << std::setw(2) << \
	now->tm_hour << std::setfill('0') << std::setw(2) << now->tm_min << std::setfill('0') << std::setw(2) << \
	now->tm_sec << "]";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";deposit" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	time_t t1 = time(0); 
	struct tm * now = localtime( &t1);
	std::cout << "[" << (now->tm_year + 1900) << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << \
	std::setfill('0') << std::setw(2) <<  now->tm_mday << "_" << std::setfill('0') << std::setw(2) << \
	now->tm_hour << std::setfill('0') << std::setw(2) << now->tm_min << std::setfill('0') << std::setw(2) << \
	now->tm_sec << "]";
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";";
	if (_amount < withdrawal)
		std::cout << "withdrawal:refused" << std::endl;
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";amount:";
		std::cout << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	}

	return(0);
}

int		Account::checkAmount(void) const
{
	time_t t1 = time(0); 
	struct tm * now = localtime( &t1);
	std::cout << "[" << (now->tm_year + 1900) << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << \
	std::setfill('0') << std::setw(2) <<  now->tm_mday << "_" << std::setfill('0') << std::setw(2) << \
	now->tm_hour << std::setfill('0') << std::setw(2) << now->tm_min << std::setfill('0') << std::setw(2) << \
	now->tm_sec << "]";
	std::cout << "QWERTY";
	return (1);
}

void	Account::displayStatus(void) const
{
	time_t t1 = time(0); 
	struct tm * now = localtime( &t1);
	std::cout << "[" << (now->tm_year + 1900) << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << \
	std::setfill('0') << std::setw(2) <<  now->tm_mday << "_" << std::setfill('0') << std::setw(2) << \
	now->tm_hour << std::setfill('0') << std::setw(2) << now->tm_min << std::setfill('0') << std::setw(2) << \
	now->tm_sec << "]";
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals <<std::endl;
}