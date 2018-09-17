#pragma once
#include "Calculator.h"
#ifndef FinancialCaclculator_H
#define FinancialCalculator_H

class FinancialCalculator : public Calculator {
	private:
		double monthlyInterestRate;
		int months;
		int years;
		double fValue = 0.0;
		double monthlyInvestment;
	public:
		FinancialCalculator();
		void futureValue();
		void operationChoice();
		void askForValues();
};
FinancialCalculator::FinancialCalculator() {
	
	
}
void  FinancialCalculator::operationChoice() {
	switch (op)
	{
	case 5:
		askForValues();
		futureValue();
		break;
	default:
		cout << "Improper command. Please retry!\n";
	}
}
void FinancialCalculator::futureValue() {
	for (int i = 1; i <= months; i++) {
		fValue = (fValue + monthlyInvestment) * (1 + monthlyInterestRate);
		cout << "%d\n" << fValue;
	}
}
void FinancialCalculator::askForValues() {
	cout << "Enter months, years, monthly interest rate, and monthly investment(followed by spaces): ";
	cin >> months >> years >> monthlyInterestRate >> monthlyInvestment;
}


#endif