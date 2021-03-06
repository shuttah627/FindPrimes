// FindPrimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	// Define required variables
	std::shared_ptr<std::vector<long>> foundPrimes = std::make_shared<std::vector<long>>();
	long searchLimit = 1000000;
	long multipleLimit = 10;
	bool notPrime;

	auto start = std::chrono::system_clock::now();
	std::cout << "finding primes within 0 -> " <<searchLimit<< "..." << std::endl;
	// Look between 0 -> searchLimit for primes, and look between 0-9 for prime factors
	for (long i = 2; i < searchLimit; i++) {
		notPrime = true;
		for (long j = 1; j <= i; j++) {
			
			if (j != i && j != 1 && notPrime != false) {
				//std::cout << (i%j) << std::endl;
				if (i % j == 0) {
					notPrime = false;
				}
			}

		}
		if (notPrime == true) {
			foundPrimes->push_back(i);
			//std::cout << i << std::endl;
		}
	}
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> timetaken = end - start;
	std::cout << "primes found. " << timetaken.count() << " seconds taken." << std::endl;
	std::cout << (foundPrimes->size() / timetaken.count()) << " primes found per second" << std::endl;
	std::cout << "writing to file..." << std::endl;
	std::fstream file;
	file.open("millionprimes.txt", std::ios::out);

	for (int l = 0; l < foundPrimes->size(); l++) {
		file << foundPrimes->at(l) << std::endl;
	}
	file.close();

	std::cin.get();
	return 0;
}

