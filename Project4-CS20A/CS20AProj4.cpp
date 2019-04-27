//============================================================================
// Name        : CS20AProj4.cpp
// Author      : 
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};


/*
 * Part 1 - a
 */
int longestPath(Node* root) {

	// Your code here
	
		return 0;
}

/*
 * Part 1 - b
 */
void setSize(Node* root) {
	
	// Your code here
	
}

/*
 * Part 1 - c
 */
void flip(Node* root) {
	
	// Your code here
	
}

/*
 * Part 2
 */
void printFrequentNames(string filename, int threshold) {
		
	// Your code here
	fstream studentsFile;
	string first;

	studentsFile.open(filename);
	if (!studentsFile.is_open())
		cerr << "Error opening file." << endl;
	
	map<string, int> nameCounts;
	map<string, int>::iterator itr;
	string line, firstName;

	while (!studentsFile.eof()) {
		getline(studentsFile, line);
		firstName = line.substr(0, line.find(' '));

		itr = nameCounts.find(firstName);
		if (itr != nameCounts.end()) {// if name is found, increment counter
			itr->second++;
		}
		else
			nameCounts.insert(pair<string, int>(firstName, 1));
	}
	ofstream output("firstName_and_Counts.txt");
	for (itr = nameCounts.begin(); itr != nameCounts.end(); itr++) {
		if (itr->second <= threshold) {
			output << itr->first;

			for (int i = 0; i < 20 - (itr->first).length(); i++)
				output << " ";
			output << itr->second << endl;
		}

	}

	output.close();
	studentsFile.close();
}

int main() {

  /*
	 * This code is here just as an example.
	 *
	 * Test your code well.
	 * You can leave that code in the main but I will not use that or grade you on it.
	 * I will test your classes with my own driver code.
	 */


	//		    1
	//	     / \
	//      2   3
	//     /   / \
	//    4   5   6
	//		     \
	//		     7

  // Test your code by building manually a tree like above, by linking nodes.
  //
  // Easiest way to verify what tree you've built or that your flip and setSize 
  // functions work correctly is by doing a preOrder traversal.
  
	// Node a(1);
	// make other nodes and link them
	// ...

	// cout << "Longest path " << longestPath(&a) << endl;

	// flip(&a);
	
	// setSize(&a);
	

	cout << "Most frequent first names:" << endl;
	printFrequentNames("uc_students.txt", 300);
	
	return 0;
}
