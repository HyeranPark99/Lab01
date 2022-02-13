// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code! 

/* Homework Objective: fix this program to match the requirements listed: 
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category 
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std; 

int main() {

  // define variables
  string sku, brand, category, year, price; 
  vector<int>vSKU;
  vector<string>vBrand;
  vector<string>vCategory;
  vector<int>vYear;
  vector<float>vPrice;

  ofstream myfile;
  myfile.open ("result.txt");
  ifstream in_stream;
  in_stream.open("./Resource File/data2.csv"); //opening the file.
  int count =0; 

  if (!in_stream.fail()) { //if the file is open

    string line;

	    while (in_stream) { //while the end of file is NOT reached
		
	    	//if(in_stream.eof())break;
	     // Fields: sku,brand,category,year,price
			count ++;
	     getline(in_stream, sku, ',');
	     stringstream ssku(sku); 
	     int iSKU = 0;
	     ssku >> iSKU;
	     vSKU.push_back(iSKU);
	
	     getline(in_stream, brand, ',');
	     vBrand.push_back(brand);
	
	     getline(in_stream, category, ',');
	     vCategory.push_back(category);
	
	     getline(in_stream, year, ','); 
	     stringstream syear(year);
	     int iYear;
	     syear >> iYear;
	     vYear.push_back(iYear);
	
	     getline(in_stream, price, '\n'); 
	     stringstream sprice(price);
	     float fPrice;
	     sprice >> fPrice;
	     vPrice.push_back(fPrice);
	     
	    }

    in_stream.close(); //closing the file cout << "Number of entries: " << i-1 << endl;
    

   } else {
    cout << "Unable to open file "; 
   }
 
  //output values 
  //cout << "Vector Size" << vSKU.size() << endl;
  //cout << count<< endl;
  cout << "SKU" << "\t" << "Brand" << "\t" << "Catego" << "\t"<< "Year"<< "\t" << "Price" << endl; 
  myfile << "SKU\t Brand\t Catego\t Year\t Price\n" ; 
	
  for (int j = 1; j < vSKU.size()-1; j++) {
    cout << vSKU[j] << "\t" << vBrand[j] << "\t" << vCategory[j] << "\t" << vYear[j] << "\t"   << vPrice[j]<< endl;  
    myfile << vSKU[j] << "\t  " << vBrand[j] << "\t  " << vCategory[j] << "\t\t" << vYear[j] << "\t  "   << vPrice[j] << "\n"; 
  }
  
  vector<int>vBrandId;
  vector<int>vBrandId2;
  for(int i = 0; i < vBrand.size()-1; i++) {
	  if(vBrand[i] == "ABC"){
		   vBrandId.push_back(i); 
	  }else if(vBrand[i] == "XYZ"){
		  vBrandId2.push_back(i);
	  }else continue;
  }
  
  float totalAbc=0.0;
  float totalXYZ=0.0;
  
  cout << " " << endl;
  myfile << "\n" ;
  
  
  for(int i =0; i < vBrandId.size(); i++){
		totalAbc += vPrice[vBrandId[i]];
  }
  
  int totalBran1 = vBrandId.size();
  float aveBrand1 = totalAbc/totalBran1;
  
  for(int i =0; i < vBrandId2.size(); i++){
  		totalXYZ += vPrice[vBrandId2[i]];
    }
  int totalBran2 = vBrandId2.size();
  float aveBrand2 = totalXYZ/totalBran2;
  
  cout <<"ABC Brand's average price is " << aveBrand1 << endl;
  cout <<"XYZ Brand's average price is " << aveBrand2 << endl;
  
  myfile <<"ABC Brand's average price is " << aveBrand1 << "\n";
  myfile <<"XYZ Brand's average price is " << aveBrand2 << "\n";
  
  
  vector<int>vCategoA;
  vector<int>vCategoB;
  vector<int>vCategoC;
  float totalA=0.0, totalB = 0.0, totalC =0.0;
  
  for(int i = 0; i < vCategory.size(); i++){
	  if(vCategory[i] == "A"){
		  vCategoA.push_back(i);
	  }else if(vCategory[i] == "B"){
		  vCategoB.push_back(i);
	  }else if(vCategory[i] == "C"){
		  vCategoC.push_back(i);	  
	  }else continue;
  }
  
	for(int i =0; i < vCategoA.size(); i++){
		totalA += vPrice[vCategoA[i]];
	}
	int aN = vCategoA.size();
	float aveA = totalA/aN;
	
	for(int i =0; i < vCategoB.size(); i++){
			totalB += vPrice[vCategoB[i]];
	}
	int bN = vCategoB.size();
	float aveB = totalB/bN;
	
	for(int i =0; i < vCategoC.size(); i++){
			totalC += vPrice[vCategoC[i]];
	}
	int cN = vCategoC.size();
	float aveC = totalC/cN;
	
	cout <<"A category's average price is " << aveA << endl;
	cout <<"B category's average price is " << aveB << endl;
	cout <<"C category's average price is " << aveC << endl;
  
	myfile <<"A category's average price is " << aveA << "\n" ;
	myfile <<"B category's average price is " << aveB << "\n";
	myfile <<"C category's average price is " << aveC << "\n";
	myfile << "\n" ;
	
	//SKU per a year
	 vector<int>v2000;
	 vector<int>v2010;
	 vector<int>v2020;
	  for(int i = 0; i < vYear.size(); i++){
		  if(vYear[i] == 2000){
			  v2000.push_back(i);
		  }else if(vYear[i] == 2010){
			  v2010.push_back(i);
		  }else if(vYear[i] == 2020){
			  v2020.push_back(i);	  
		  }else continue;
	  }
	
	  myfile << "2000 (" << v2000.size() <<") : ";
	  for(int i =0; i < v2000.size(); i++){
		  if( i == v2000.size()-1) {myfile << vSKU[v2000[i]]<< "\n";}
		  else{
		  
		  myfile << vSKU[v2000[i]]<< ", ";
		  }
	  	}
	  
	  myfile << "2010 (" << v2010.size() <<") : ";
	  	  for(int i =0; i < v2010.size(); i++){
	  		  if( i == v2010.size()-1) {myfile << vSKU[v2010[i]]<< "\n";}
	  		  else{
	  		  
	  		  myfile << vSKU[v2010[i]]<< ", ";
	  		  }
	  	  	}
	  	  
	  	 myfile << "2020 (" << v2020.size()-1 <<") : ";
	  		  	  for(int i =0; i < v2020.size()-1; i++){
	  		  		  if( i == v2020.size()-2) {myfile << vSKU[v2020[i]]<< "\n";}
	  		  		  else{
	  		  		  
	  		  		  myfile << vSKU[v2020[i]]<< ", ";
	  		  		  }
	  	}	  
	  

  cout << endl;
  myfile.close();

}