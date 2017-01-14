#pragma once
#include "BinLattice.h"
#include "BinModel.h"

class Option
{
private:
	int N; 
public:
	void SetN(int N_) { N = N_; }
	int GetN() { return N; }
	virtual double Payoff(double z) = 0;
};

class EurOption : public virtual Option
{
public:
	double PriceByCRR(BinModel Model, BinLattice<double>&Delta, BinLattice<double>&MoneyPosition, BinLattice<double>&EuroPrice);
};

class AmOption : public virtual Option
{
public:
	double PriceBySnell(BinModel Model, BinLattice<double>& PriceTree, BinLattice<bool>& StoppingTree);
};

class Call : public EurOption, public AmOption
{
private:
	double K; 
public:
	void SetK(double K_) { K = K_; }
	int GetInputData();
	double Payoff(double z);
};

class Put : public EurOption, public AmOption
{
private:
	double K; 
public:
	void SetK(double K_) { K = K_; }
	int GetInputData();
	double Payoff(double z);
};

