#pragma once
enum authority { Reader, Author, Admin };

class User{
public:
	authority auth;
	
};

