
#include <iostream>
using namespace std;


class Address {
public:
	Address() {
		int i,j;
		for (i = 0; i < 4; i++) {
			ipDec[i] = 0;
		}
		for (i = 0; i < 4; i++) {
			for(j=0;j<8;j++) ipBin[i][j] = 0;
			
		}
		settype();
	}

	void settype() {
		if (ipBin[0][0] == 0) { type = 1; } //A
		if (ipBin[0][0] == 1 && ipBin[0][1]==0 ) type = 2; //B
		if (ipBin[0][0] == 1 && ipBin[0][1] == 1 && ipBin[0][2]==0) type = 3; //C
	}
	void operator~() {
		cout << "type: " << type << endl;
	}
	Address operator + (const Address& b) {
		Address *res=new Address();
		int i, j,conv;
		for (i = 0; i < 4; i++) {
			conv = 0;
			for (j = 0; j < 8; j++) {
				if (this->ipBin[i][j] == 1 || b.ipBin[i][j] == 1) {
					res->ipBin[i][j] = 1;
					
					conv = conv + pow(2, 7-j);
				}
				else res->ipBin[i][j] = 0;
			}
			res->ipDec[i] = conv;
		}
		return *res;
	}
	Address operator * (const Address& b) {
		Address res;
		int i, j,conv;
		for (i = 0; i < 4; i++) {
			conv = 0;
			for (j = 0; j < 8; j++) {
				if (this->ipBin[i][j] == 0 || b.ipBin[i][j] == 0) {
					res.ipBin[i][j] = 0; 
					
				}
				else {
					res.ipBin[i][j] = 1;
					conv = conv + pow(2, 7-j); 
				}
			}
			res.ipDec[i] = conv;
		}
		return res;
	}
	Address operator - (const Address& b) {
		Address res;
		int i, j,conv;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 8; j++) {
				conv = 0;
				if (this->ipBin[i][j] == 1 && b.ipBin[i][j] == 1) res.ipBin[i][j] = 0;
				else {
					conv = conv + pow(2, 7 - j);
					res.ipBin[i][j] = 1;
				}
			}
			res.ipDec[i] = conv;
		}
		return res;
	}
	Address operator / (const Address& b) {
		Address res;
		int i, j,conv;
		for (i = 0; i < 4; i++) {
			conv = 0;
			for (j = 0; j < 8; j++) {
				if (this->ipBin[i][j] == 1 && b.ipBin[i][j] == 1) res.ipBin[i][j] = 0;
				else {
					conv = conv + pow(2, 7 - j);
					res.ipBin[i][j] = 1;
				}
				res.ipDec[i] = conv;
			}
		}
		return res;
	}
	Address operator % (const Address& b) {
		Address res;
		int i, j,conv;
		for (i = 0; i < 4; i++) {
			conv = 0;
			for (j = 0; j < 8; j++) {
				if (this->ipBin[i][j] == b.ipBin[i][j]) res.ipBin[i][j] = 0;
				else {
					conv = conv + pow(2, 7 - j);
					res.ipBin[i][j] = 1;
				}
				res.ipDec[i] = conv;
			}

		}
		return res;
	}
	Address operator ^ (const Address& b) {
		Address res;
		int i, j,conv;
		for (i = 0; i < 4; i++) {
			conv = 0;
			for (j = 0; j < 8; j++) {
				if (this->ipBin[i][j] == b.ipBin[i][j]) {
					conv = conv + pow(2, 7 - j);
					res.ipBin[i][j] = 1;
				}
				else res.ipBin[i][j] = 0;
			}
			res.ipDec[i] = conv;
		}
		return res;
	}
	Address operator = (const Address& b) {
		Address res;
		int i, j;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 8; j++) {
				this->ipBin[i][j] = b.ipBin[i][j];
			}
			this->ipDec[i] = b.ipDec[i];
		}
		return res;
	}
	bool operator == (const Address& b) {
		Address res;
		bool check = true;
		int i, j;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 8; j++) {
				if (this->ipBin[i][j] != b.ipBin[i][j]) check = false;
			}
		}
		if (check == 1) cout << "Equal!" << endl;
		return check;
	}
	bool operator != (const Address& b) {
		Address res;
		bool check = false;
		int i, j;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 8; j++) {
				if (this->ipBin[i][j] != b.ipBin[i][j]) check = true;
			}
		}
		if (check == 1) cout << "Equal!" << endl;
		return check;
	}
	void operator++() {  //replaced << with ++ here due to error
		int i, j;
		cout << "	Decimal :" << ipDec[0] << "." << ipDec[1] << "." << ipDec[2] << "." << ipDec[3] << endl;
		cout << "	Binary :";
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 8; j++) {
				cout << ipBin[i][j];
			}
			if (i != 3) cout << ".";
		}
		cout << endl;

	}
	void operator--() { //replaced >> with -- here due to error
		int i = 0, conv;
		cout << "Enter the IP Address:\nOctal 1: ";
		cin >> this->ipDec[0];
		conv = ipDec[0];
		for (i = 7; i >= 0; i--) {
			if ((conv - pow(2, i)) >= 0){
				conv = conv - pow(2, i);
				ipBin[0][7-i] = 1;
			}
			else ipBin[0][7-i] = 0;
		}
		cout << "Octal 2: ";
		cin >> this->ipDec[1];
		conv = ipDec[1];
		for (i = 7; i >= 0; i--) {
			if ((conv - pow(2, i)) >= 0) {
				conv = conv - pow(2, i);
				ipBin[1][7 - i] = 1;
			}
			else ipBin[1][7 - i] = 0;
		}
		cout << "Octal 3: ";
		cin >> this->ipDec[2];
		conv = ipDec[2];
		for (i = 7; i >= 0; i--) {
			if ((conv - pow(2, i)) >= 0) {
				conv = conv - pow(2, i);
				ipBin[2][7 - i] = 1;
			}
			else ipBin[2][7 - i] = 0;
		}
		cout << "Octal 4: ";
		cin >> this->ipDec[3];
		conv = ipDec[3];
		for (i = 7; i >= 0; i--) {
			if ((conv - pow(2, i)) >= 0) {
				conv = conv - pow(2, i);
				ipBin[3][7 - i] = 1;
			}
			else ipBin[3][7 - i] = 0;
		}
	}
private:
	int ipDec[4];
	int ipBin[4][8];
	int type;
};