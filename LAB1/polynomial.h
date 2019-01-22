//Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#ifndef polynomial_h
#define polynomial_h

using namespace std;

class Polynomial {
	
	public:
		Polynomial();
		Polynomial(int A[], int size);
		Polynomial(string fileName);
		
		~Polynomial();
		
		void add(const Polynomial& second);
		void sub(const Polynomial& second);
		void mul(const Polynomial& second);
		
		void printData();
		
	private:
		int size;
		int* data = NULL;
		
};

#endif
