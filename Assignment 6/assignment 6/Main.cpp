

#include "BinLattice.h"
#include "BinModel.h"
#include "Options.h"
#include <iostream>
using namespace std;
int main()
{
	BinModel Model;
	if (Model.GetInputData() == 1) return 1;
	BinLattice<double> PriceTree;
	BinLattice<bool> StoppingTree;
	BinLattice<double> Delta;
	BinLattice<double> MoneyPosition;
	BinLattice<double> EuroPrice;
    
	Call Option1;
	Option1.GetInputData();
	Option1.PriceByCRR(Model, Delta, MoneyPosition,EuroPrice);
	cout << "call: Stock positions in replicating strategy: " << endl << endl;
	Delta.Display();
	cout << "call: Money market account positions in replicating strategy: " << endl << endl;
	MoneyPosition.Display();
    
	Put Option2;
	Option2.GetInputData();
	Option2.PriceByCRR(Model, Delta, MoneyPosition,EuroPrice);
	cout << "put: Stock positions in replicating strategy: " << endl<<endl;
	Delta.Display();
	cout << "put: Money market account positions in replicating strategy: " << endl << endl;
	MoneyPosition.Display();

	return 0;
}
