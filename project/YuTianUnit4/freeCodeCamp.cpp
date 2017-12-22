/*

o Programmer name:	Yu Tian
o Course number:1748
o Date: 10/1
o Purpose:summer freeCodeCamp
o Input:
o Output:
                                             
   ad88                                      
  d8"                                        
  88                                         
MM88MMM  8b,dPPYba,   ,adPPYba,   ,adPPYba,  
  88     88P'   "Y8  a8P_____88  a8P_____88  
  88     88          8PP"""""""  8PP"""""""  
  88     88          "8b,   ,aa  "8b,   ,aa  
  88     88           `"Ybbd8"'   `"Ybbd8"'  
                                             
                                                      
  ,ad8888ba,                         88              
 d8"'    `"8b                        88              
d8'                                  88              
88              ,adPPYba,    ,adPPYb,88   ,adPPYba,  
88             a8"     "8a  a8"    `Y88  a8P_____88  
Y8,            8b       d8  8b       88  8PP"""""""  
 Y8a.    .a8P  "8a,   ,a8"  "8a,   ,d88  "8b,   ,aa  
  `"Y8888Y"'    `"YbbdP"'    `"8bbdP"Y8   `"Ybbd8"'  

                                                             
  ,ad8888ba,                                                
 d8"'    `"8b                                               
d8'                                                         
88             ,adPPYYba,  88,dPYba,,adPYba,   8b,dPPYba,   
88             ""     `Y8  88P'   "88"    "8a  88P'    "8a  
Y8,            ,adPPPPP88  88      88      88  88       d8  
 Y8a.    .a8P  88,    ,88  88      88      88  88b,   ,a8"  
  `"Y8888Y"'   `"8bbdP"Y8  88      88      88  88`YbbdP"'   
                                               88           
                                               88            
											 
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
	ifstream readFreeCodeCamp("freeCodeCamp.txt");
	if (!readFreeCodeCamp) {
		cout << "Error opening file" << endl;
		cin.get();
		return -1;
	}
	else {
		char letter;
		for (int i = 0; !readFreeCodeCamp.eof(); i++) {
			readFreeCodeCamp.get(letter);
			cout << letter;
		}
		cout << endl;
		readFreeCodeCamp.close();
		cin.get();
		return 0;
	}
}