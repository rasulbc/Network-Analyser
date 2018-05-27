#include <iostream>
#include "Address.h"
#pragma once
using namespace std;


class Netfinder{
public:
	Netfinder() {
		int i;
		cout << "Size for IPs: ";
		cin >> size;
		users = new Address[size];
		cout << "User IPs: " << endl;
		for (i = 0; i < size; i++) {
			--users[i];
		}
		subnet = new Address[size];
		cout << "Subnet IPs: " << endl;
		for (i = 0; i < size; i++) {
			--subnet[i];
		}
		actual = new Address[size];
		actuator();
		printer();
	}
	void operator=(const Netfinder& b) {
		this->users = b.users;
		this->subnet = b.subnet;
		this->actual = b.actual;
	}
	Netfinder(const Netfinder& b) {
		this->users = b.users;
		this->subnet = b.subnet;
		this->actual = b.actual;
	}
	~Netfinder() {
		 delete(users);
		 delete(subnet);
		 delete(actual);
	 }
	void actuator() {
		int i;
		for (i = 0; i < size; i++) {
			actual[i] = users[i] * subnet[i];
		}
	}
	void printer() {
		int i;
		cout << "User's  IPs:\n";
		for (i = 0; i < size; i++) {
			++users[i];
		}
		cout << "Subnet's  IPs:\n";
		for (i = 0; i < size; i++) {
			++subnet[i];
		}
		cout << "Obtained's  IPs:\n";
		for (i = 0; i < size; i++) {
			++actual[i];
		}

	}
	
private:
	int size;
	Address *users;
	Address *subnet;
	Address *actual;
};