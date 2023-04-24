#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

// your code goes here

#include <ostream>
#include <iostream>


struct Location {
	int row; 
	int column;

	void operator+=(const Location& l) {
		this->row += l.row;
		this->column += l.column;
	}

	bool operator!=(const Location& l) {
		return !(this->row == l.row && this->column == l.column);
	}

	bool operator==(const Location& l) {
		if (this->row == l.row)
		{
			if (this->column == l.column)
				return true;
		}
		return false;
	}
	friend std::ostream& operator<<(std::ostream& os, const Location& loc) {
		os << "row: " << loc.row << ", column: " << loc.column;
		return os;
	}

};

#endif // MY_HEADER_FILE_H
