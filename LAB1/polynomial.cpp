//Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "polynomial.h"

using namespace std;

int main(){	
	srand(time(NULL));
	
	//randomly generated polynomials
	Polynomial poly1;
	Polynomial poly2;
	Polynomial poly3;
	Polynomial poly4;
	
	//polynomials created from arrays
	int arrPoly5[4] = {1, 1, 1, 1};
	int arrPoly6[7] = {14, 20, 13, 12, 5, 17, 18};
	int arrPoly7[6] = {2, 1, 5, 0, 10, 4};
	
	Polynomial poly5(arrPoly5, 4);
	Polynomial poly6(arrPoly6, 7);
	Polynomial poly7(arrPoly7, 6);
	
	//polynomials from files
	Polynomial poly8("poly8.txt");
	Polynomial poly9("poly9.txt");
	Polynomial poly10("poly10.txt");
	
	//3 addition test cases
	cout << "Addition: " << endl << "   ";
	poly1.printData();
	cout << " + ";
	poly5.printData();
	cout << " = ";
	poly1.add(poly5);
	poly1.printData();
	cout << endl << "   ";
	
	poly5.printData();
	cout << " + ";
	poly8.printData();
	cout << " = ";
	poly5.add(poly8);
	poly5.printData();
	cout << endl << "   ";
	
	poly8.printData();
	cout << " + ";
	poly2.printData();
	cout << " = ";
	poly8.add(poly2);
	poly8.printData();
	cout << endl << "   ";
	
	//3 subtraction test cases
	cout << endl << "Subtraction: " << endl << "   ";
	poly2.printData();
	cout << " - ";
	poly6.printData();
	cout << " = ";
	poly2.sub(poly6);
	poly2.printData();
	cout << endl << "   ";
	
	poly6.printData();
	cout << " - ";
	poly9.printData();
	cout << " = ";	
	poly6.sub(poly9);
	poly6.printData();
	cout << endl << "   ";

	poly9.printData();
	cout << " - ";
	poly3.printData();
	cout << " = ";	
	poly9.sub(poly3);
	poly9.printData();
		
	//3 multiplication test cases
	cout << endl << "Multiplication: " << endl << "   ";
	poly3.printData();
	cout << " * ";
	poly7.printData();
	cout << " = ";		
	poly3.mul(poly7);
	poly3.printData();
	cout << endl << "   ";

	poly7.printData();
	cout << " * ";
	poly10.printData();
	cout << " = ";		
	poly7.mul(poly10);
	poly7.printData();
	cout << endl << "   ";

	poly10.printData();
	cout << " * ";
	poly4.printData();
	cout << " = ";		
	poly10.mul(poly4);
	poly10.printData();
		
	return 0;
}

Polynomial::Polynomial() {	
	
	size = rand() % 10;
	
	if (!data)
		data = new int[size];
	
	for (int i = 0; i < size; i++) {
		data[i] = rand() % 10;
	} 
}

Polynomial::Polynomial(int A[], int newSize) {
	size = newSize;
	
	if (!data)
		data = new int[size];
		
	for (int i = 0; i < size; i++){
		data[i] = A[i];
	} 
}

Polynomial::Polynomial(string fileName) {
	ifstream fin(fileName.c_str());
	if(!fin){
		cout << "Could not open file";
		return;
	}
	
	fin >> size;
	
	if (!data)
		data = new int[size];
	
	for( int i = 0; i < size; i++) {
		fin >> data[i];
	}
	
	fin.close();
}

Polynomial::~Polynomial() {
	delete [] data;
}

void Polynomial::add(const Polynomial& second) {
	int sumSize = max(size, second.size);
	int *sum = new int[sumSize];
	
	for (int i = 0; i < sumSize; i++) {
		sum[i] = 0;
	} 
	
	for (int i = 0; i < size; i++) {
		sum[i] = data[i];
	} 
	
	for (int i = 0; i < second.size; i++) {
		sum[i] += second.data[i];
	} 
	
	size = sumSize;
	
	delete [] data;
	data = new int[size];
	
	for (int i = 0; i < size; i++) {
		data[i] = sum[i];
	} 
	delete [] sum;
}

void Polynomial::sub(const Polynomial& second) {
	int sumSize = max(size, second.size);
	int *sum = new int[sumSize];
	
	for (int i = 0; i < sumSize; i++) {
		sum[i] = 0;
	} 
	
	for (int i = 0; i < size; i++) {
		sum[i] = data[i];
	} 
	
	for (int i = 0; i < second.size; i++) {
		sum[i] -= second.data[i];
	} 
	
	size = sumSize;
	
	delete [] data;
	data = new int[size];
	
	for (int i = 0; i < size; i++) {
		data[i] = sum[i];
	} 
	delete [] sum;
}

void Polynomial::mul(const Polynomial& second) {
	int mulSize = size + second.size - 1;
	int *mul = new int[mulSize];
	
	for (int i = 0; i < mulSize; i++) {
		mul[i] = 0;
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < second.size; j++) {
			mul[i + j] += data[i] * second.data[j];
		}
	}
	
	size = mulSize;
	
	delete [] data;
	data = new int[size];
	
	for (int i = 0; i < size; i++) {
		data[i] = mul[i];
	} 
	delete [] mul;
}

void Polynomial::printData() {
	for (int i = size - 1; i > 0 && data; i--) {
		cout << showpos << data[i] << noshowpos << "x^" << i << " ";
	}
	cout << showpos << data[0] << endl << noshowpos; //print last coefficient by itself
}
