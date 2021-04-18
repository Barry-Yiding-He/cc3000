/*
 * Example of using the <algorithm> std::shuffle and seeding a random number generator with either
 * the command-line argument provided seed integer, or the current system time if there is no
 * argument provided. Based off of the example at: 
 *
 *    http://www.cplusplus.com/reference/algorithm/shuffle/
 *
 *  Last updated: 2020-10-06
 *  Copyright 2020 UW. All rights reserved.
 *
 */
 // 
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

void print( std::vector<int> const & v ) {
	for ( int i : v ) std::cout << i << ' ';
	std::cout << std::endl;
}

int main( int argc, char * argv[] ) {
	
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// use a time-based seed for the default seed value
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	
	
	std::default_random_engine rng{1000};

		std::shuffle( v.begin(), v.end(), rng);
		std::shuffle( v1.begin(), v1.end(), rng);
		print(v);		
		print(v1);

	return 0;
} // main
