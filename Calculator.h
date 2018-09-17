#pragma once
#ifndef Caclculator_H
#define Calculator_H


#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;
class Calculator {
	private:
		float a;
		float b;
	protected:
		int op;
	public:
		Calculator();
		~Calculator();
		void menu();
		void getInputs();
		virtual void operationChoice();
		void checkForEnter();
		void doCalculations();
};
Calculator::Calculator() {
	a = 0;
	b = 0;
}
Calculator::~Calculator() {

}
void Calculator::menu() {
	cout << "1.Addition\n2.Subrtraction\n3.Multiplication\n4.Division\n5.Future Value\n6.Scientific\n7.Exit" << endl;
	cout << "What would you like to do?" << endl;
	cin >> op;
}
void Calculator::getInputs() {
	cout << "Please enter two numbers, seperated by a space:  ";
	cin >> a >> b;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Wrong Entry. Enter numeric values: ";
		cin >> a >> b;
	}
}

void Calculator::operationChoice() {
	switch (op)
	{
	case 1:
		getInputs();
		cout << a + b << endl;
		break;
	case 2:
		getInputs();
		cout << a - b << endl;
		break;
	case 3:
		getInputs();
		cout << a * b << endl;
		break;
	case 4:
		getInputs();
		if (isinf(a / b)) {
			cout << "Infinity" << endl;
		}
		else {
			cout << a / b << endl;
		}
		break;
	case 7:
		cout << "Thank you for using Johns' Caculator";
		exit(0);
		break;
	default:
		cout << "Improper command. Please retry!\n";
	}
}
void Calculator::checkForEnter() {
	cout << "Press the enter key to continue..." << endl;
	if (!cin) cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}
void Calculator::doCalculations() {
	while (op != 7) {
		menu();
		operationChoice();
		checkForEnter();
	}
}
#endif // !Caclculator_H