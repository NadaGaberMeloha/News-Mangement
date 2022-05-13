#pragma once
#include <iostream>
#include "Admin.h"
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

struct Details {
	string Title;
	string Writer;
	string Discrepition;
	string Date;
	string string_rate;
	string count ;
	string spam; 
};

class News
{

	string comment;
	int count=0;
	float Rate;
	int total=0;
	int type = 0 ; 
	int NumberOfRate =0;
	int NumberOfSpam = 0;
public :
	void ChangeSpam(string);
	Details detail;
	string	string_type;
	News(void);
	vector<Details> ReadNews();
	vector<Details> ReadCatogNews(int);
	bool ReadCertainNews(string);
	void WriteNews(int , string[]);
	void WriteComment(int);
	float CalculateRate(string , float , string );
	vector<string> ReadComment(int);
	int EndNumberOfNewsInCatogry(int);
	void ChangeRate(string , float);
};
