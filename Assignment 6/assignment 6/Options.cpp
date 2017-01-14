#include "Options.h"
#include "BinModel.h"
#include "BinLattice.h"
#include <iostream>
#include <cmath>
using namespace std;

double EurOption::PriceByCRR(BinModel Model, BinLattice<double>&Delta, BinLattice<double>&MoneyPosition, BinLattice<double>&EuroPrice)
{
	int N = GetN();
	double q = Model.RiskNeutProb();
    
	vector<double> Price(N + 1);
    
	Delta.SetN(N);
	MoneyPosition.SetN(N);
	EuroPrice.SetN(N);
    
    for (int i = 0; i <= N; i++){
		EuroPrice.SetNode(N, i, Payoff(Model.S(N, i)));
	}
    
    for (int n = N - 1; n >= 1; --n){
        for (int i = n ; i >= 0; --i){
			double ContVal = (q*EuroPrice.GetNode(n + 1, i + 1) + (1 - q)*EuroPrice.GetNode(n + 1, i)) / (1 + Model.GetR());
			EuroPrice.SetNode(n, i, ContVal);
		}
	}
    
    for (int i = 0; i <= N - 1; ++i){
		double X = (Payoff(Model.S(N, i + 1)) - Payoff(Model.S(N, i))) / (Model.S(N, i + 1) - Model.S(N, i));
		double Y = (Payoff(Model.S(N, i)) - X*Model.S(N, i)) / pow(1 + Model.GetR(), N);
		Delta.SetNode(N, i, X);
		MoneyPosition.SetNode(N, i, Y);
    }
    
    for (int n = N-1; n >= 1; --n){
        for (int i = n-1; i >= 0; --i){
			double X = (EuroPrice.GetNode(n,i+1) - EuroPrice.GetNode(n, i )) / (Model.S(n, i + 1) - Model.S(n, i));
			double Y = (EuroPrice.GetNode(n, i) - X*Model.S(n, i)) / pow(1 + Model.GetR(), n);
			Delta.SetNode(n, i, X);
	    	MoneyPosition.SetNode(n, i, Y);
		}
	}
	return 0.0;
}

double AmOption::PriceBySnell(BinModel Model, BinLattice<double>& PriceTree, BinLattice<bool>& StoppingTree)
{
	double q = Model.RiskNeutProb();
	int N = GetN();
	double ContVal;
	PriceTree.SetN(N);
	StoppingTree.SetN(N);
	for (int i = 0; i <= N; i++)
	{
		PriceTree.SetNode(N, i, Payoff(Model.S(N, i)));
		StoppingTree.SetNode(N, i, 1);
	}
	for (int n = N - 1; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			ContVal = (q*PriceTree.GetNode(n + 1, i + 1) + (1 - q)*PriceTree.GetNode(n + 1, i)) / (1 + Model.GetR());
			PriceTree.SetNode(n, i, Payoff(Model.S(n, i)));
			StoppingTree.SetNode(n, i, 1);
			if (ContVal > PriceTree.GetNode(n, i))
			{
				PriceTree.SetNode(n, i, ContVal);
				StoppingTree.SetNode(n, i, 0);
			}
			else if (PriceTree.GetNode(n, i) == 0.0)
			{
				StoppingTree.SetNode(n, i, 0);
			}
		}
	}
	return PriceTree.GetNode(0, 0);
}

int Call::GetInputData()
{
	cout << "Enter call option data:" << endl;  int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	cout << "Enter strike price K:    "; cin >> K;
	cout << endl;
	return 0;

}

double Call::Payoff(double z)
{
	if (z>K) return z - K;
	return 0.0;
}

int Put::GetInputData()
{
	cout << "Enter put option data:" << endl;  int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	cout << "Enter strike price K:    "; cin >> K;
	cout << endl;
	return 0;
}

double Put::Payoff(double z)
{
	if (z<K) return K - z;
	return 0.0;
}



