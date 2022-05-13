#include "News.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include <sstream>
#include <algorithm>
using namespace std; 

News::News() {
	Rate = 0;
	count=0;

}

vector<Details>News::ReadNews() {
	ifstream input;
	input.open("News.txt", ios::app);
	assert(!input.fail());
	vector<Details> details;
	while (getline(input ,string_type) && getline(input, detail.Title) && getline(input, detail.Writer) &&
		getline(input, detail.Discrepition)&& getline(input, detail.Date )&& 
		getline(input, detail.string_rate) &&
		getline(input, detail.count) &&
		getline(input, detail.spam))
	{

		details.push_back(detail);

	} input.close();
	return details;
}

vector<Details> News::ReadCatogNews (int cato_type) {
	ifstream input;
	input.open("News.txt", ios::app);
	assert(!input.fail());
	vector<Details> details;
	
	
	while (getline(input, string_type) && getline(input, detail.Title) && getline(input, detail.Writer) &&
		getline(input, detail.Discrepition) && getline(input, detail.Date) 
		&& getline(input, detail.string_rate) &&
		getline(input, detail.count) &&
		getline(input, detail.spam))
	{

		stringstream geek(string_type);
		geek >> type;
		if ((type % 10) == cato_type) {
			details.push_back(detail);
		}
	}
	
	input.close();
	return details;
}

bool News::ReadCertainNews(string titl) {

	ifstream input;
	input.open("News.txt");

	while (getline(input, string_type) && 
		getline(input, detail.Title) && 
		getline(input, detail.Writer) &&
		getline(input, detail.Discrepition) && 
		getline(input, detail.Date) && 
		getline(input, detail.string_rate) &&
		getline(input, detail.count) &&
		getline(input, detail.spam))
	{
		transform(titl.begin(), titl.end(), titl.begin(), ::tolower);
		if (titl == detail.Title ) {
			cout << titl << "\n";
			input.close();
			return true;
		}

	} 
	input.close();
	return false;
//	cout << detail.Title << "        " << detail.Writer << "     " << detail.Discrepition << "        " << detail.Date << endl;
}

float News::CalculateRate(string oldRate , float rate , string counter) {
	float old = stof(oldRate);
	old += rate;
	stringstream geek(counter);
	geek >> NumberOfRate;
	cout << NumberOfRate<< endl ;
	++NumberOfRate;
	detail.count = to_string(NumberOfRate);
	return (old / NumberOfRate);
}

void News::ChangeRate( string titl , float rate) {

	bool isFoundTile = ReadCertainNews(titl);
	cout << isFoundTile << endl;
	if (isFoundTile == true ) {
		ofstream tempfile;
		tempfile.open("temp.txt");
		ifstream input;
		input.open("News.txt");
		while (getline(input, string_type) &&
			getline(input, detail.Title) &&
			getline(input, detail.Writer) &&
			getline(input, detail.Discrepition) && 
			getline(input, detail.Date )&&
			getline(input, detail.string_rate) &&
			getline(input, detail.count) &&
			getline(input, detail.spam))
		{
			transform(titl.begin(), titl.end(), titl.begin(), ::tolower);
			if (titl != detail.Title)
			{
				tempfile << string_type << "\n"
					<< detail.Title << "\n"
					<< detail.Writer << "\n"
					<< detail.Discrepition << endl
					<< detail.Date << endl
					<< detail.string_rate << endl
					<< detail.count << endl
					<< detail.spam << endl;
			
			}
			else
			{
				float newRate = CalculateRate(detail.string_rate, rate, detail.count);
				if (newRate <= 2) {
					continue;
				}
				cout << newRate << endl;
				tempfile << string_type << "\n"
					<< detail.Title << "\n"
					<< detail.Writer << "\n"
					<< detail.Discrepition << endl
					<< detail.Date << endl
					<< to_string(newRate)<< endl
					<< detail.count << endl
					<< detail.spam << endl;
				
			}

		}
		input.close();
		tempfile.close();
		remove("News.txt");
		rename("temp.txt", "News.txt");
		cout << "Done \n";
	}
	else {
		cout << "Sorry, The title that you search about isn't found ." << endl;
		cout << " press 1 To continue to Rate news or press 2 if not " << endl;
		int choose;
		cin >> choose;
		if (choose == 1) {
			return;
		}
		else if (choose == 2) {
			return;
		}
		else
		{
			cout << "Please , Enter 1 or 2 only" << endl;
		}
	}
}

void News::WriteNews(int Type , string detail[]) {
	ofstream input("News.txt", ios::app);
	assert(!input.fail());
	transform(detail[0].begin(), detail[0].end(), detail[0].begin(), ::tolower);
	input << to_string(Type) << endl
		<< detail[0] << endl
		<< detail[1] << endl
		<< detail[2] << endl
		<< detail[3] << endl
		<< to_string(Rate) << endl
		<< to_string(count) << endl 
		<< to_string(NumberOfSpam) << endl;
	system("cls");
	cout << "done\n ";
	cout << Type << endl;
	input.close();
}

int News::EndNumberOfNewsInCatogry(int cato) {
	ifstream input;
	input.open("News.txt", ios::app);
	assert(!input.fail());
	while (getline(input, string_type)&&
		getline(input, detail.Title)&&
		getline(input, detail.Writer)&&
		getline(input, detail.Discrepition)&&
		getline(input, detail.Date)&&
		getline(input, detail.string_rate)&& 
		getline(input, detail.count) &&
		getline(input, detail.spam)) {

		stringstream geek(string_type);
		geek >> type;
		if (cato == (type % 10) ){
			
			count = type; 
		}
	}
	return count ;
}

void News::WriteComment(int type ) {
	ofstream input("Comments.txt", ios::app);
	assert(!input.fail());
	getline(cin, comment);
	input << to_string(type) << endl <<  comment << endl;
	system("cls");
	cout << "done\n ";
	input.close();
}

vector<string> News::ReadComment(int cato_type) {
	ifstream input;
	input.open("Comments.txt", ios::app);
	assert(!input.fail());
	
	vector<string> details;
	while (getline(input, string_type) &&
		getline(input, comment))
	{


		transform(string_type.begin(), string_type.end(), string_type.begin(), ::tolower);
		if (string_type._Equal( to_string(cato_type)) )
			details.push_back(comment);
		
	} 
	input.close();
	return details;
}

void News::ChangeSpam(string titl) {

	bool isFoundTile = ReadCertainNews(titl);
	cout << isFoundTile << endl;
	if (isFoundTile == true) {
		ofstream tempfile;
		tempfile.open("temp.txt");
		ifstream input;
		input.open("News.txt");
		while (getline(input, string_type) &&
			getline(input, detail.Title) &&
			getline(input, detail.Writer) &&
			getline(input, detail.Discrepition) &&
			getline(input, detail.Date) &&
			getline(input, detail.string_rate) &&
			getline(input, detail.count) &&
			getline(input, detail.spam))
		{
			transform(titl.begin(), titl.end(), titl.begin(), ::tolower);
			if (titl != detail.Title)
			{
				tempfile << string_type << "\n"
					<< detail.Title << "\n"
					<< detail.Writer << "\n"
					<< detail.Discrepition << endl
					<< detail.Date << endl
					<< detail.string_rate << endl
					<< detail.count << endl
					<< detail.spam << endl;
			}
			else
			{
				stringstream geek(detail.spam);
				geek >> NumberOfSpam;
				NumberOfSpam++;
				tempfile << string_type << "\n"
					<< detail.Title << "\n"
					<< detail.Writer << "\n"
					<< detail.Discrepition << endl
					<< detail.Date << endl
					<< detail.string_rate << endl
					<< detail.count << endl
					<< to_string(NumberOfSpam) << endl;
				
			}

		}
		input.close();
		tempfile.close();
		remove("News.txt");
		rename("temp.txt", "News.txt");
		cout << "Done \n";
	}
	else {
		cout << "Sorry, The title that you search about isn't found ." << endl;
		cout << " press 1 To continue to Spam news or press 2 if not " << endl;
		int choose;
		cin >> choose;
		if (choose == 1) {
			return;
		}
		else if (choose == 2) {
			return;
		}
		else
		{
			cout << "Please , Enter 1 or 2 only" << endl;
		}
	}
}
