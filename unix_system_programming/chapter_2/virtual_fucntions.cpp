#include<iostream>
using namespace std;
class date {
	int year, month, day;
	public:
	date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	};
	
	virtual ~date() {};

	virtual void print() {
		cerr<<year<<'/'<<month<<'/'<<day<<"\n"<<endl;
	};

	virtual void set(int a, int b, int c)  {
		year = a;
		month = b;
		day = c;
	};
};

class derived:public date {
	int x;
	public:
	derived(int a, int b, int c, int d): date(a,b,c), x(d) {};
	~derived() {};
	void print() { date::print(); cout<<"derived:x="<<x<<"\n";};
	virtual void set(int a, int b, int c) {
		x=a;
	};
};

int main() {
	date foo(1991,5,4);
	derived y(1,2,3,4);
	date *p = &y;
	p->print();
	p = &foo;
	p->print();
	return 0;
}
