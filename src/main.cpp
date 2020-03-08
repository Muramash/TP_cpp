#include <iostream>
#include <vector>
using namespace std;

void showAdress(string addr){
	cout << &addr << endl;
}

void showaddr(string addr){
	cout << addr << endl;
}

void exchange(string addr1, string addr2){
	string tempaddr = *&addr1;
	addr1 = *&addr2;
	addr2 = *&tempaddr;
	cout << "addr 1 : " << addr1 << "| addr2 : " << addr2 << endl;
}

void getMinMax(int tab[], int number, int min, int max){
	int i = 0;
	do{
		if(tab[i] < min){
			*&min = *&tab[i];
		}
		if(tab[i] > max){
			*&max = *&tab[i];
		}
		i++;
	}while(i < number);

	cout << "minTab  = " << min << " | maxTab = " << max << endl;
	cout << "Tab : " << *&tab << endl;
}

void setTab(int tab[]){
	int i = 1;
	do{
		cout << "Entrez l'input numero " << *&i << " du tableau" << endl;
		cin >> tab[i];
		i++;
	}while(i < 6);

	i = 1;

	do{
		cout << "Iteration num " << i << " = " << tab[i] << endl;
		i++;
	}while(i < 6);
}

int main(int argc, char *argv[]) {

	float testNumber1 = 6, testNumber2 = 3;

	showAdress("Hello");

	string someaddr = "Hello World";
	string someaddr2 = "World hello";

	showaddr(someaddr);
	exchange(someaddr, someaddr2);
	showaddr(someaddr);

	cout << "_________________ \n";

	int number = 5, min = 100, max = -100;
	int tab[number];
	tab[0] = 4;
	tab[1] = 5;
	tab[2] = 3;
	tab[3] = -1;
	tab[4] = 1;
	getMinMax(tab, number, min, max);

	int tabEmpty[number];
	setTab(tabEmpty);
}