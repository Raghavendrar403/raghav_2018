#ifndef MENU_H
#define MENU_H
class menu {
	private:
		char* title;
	protected:
		static int num_fields;
	public:
		// constructor function
		menu(const char* str) {
			title = new char[strlen(str)+1];
			strcpy(title,str);
			num_fields = 0;
		};

		/* constructor function */
		menu() {
			title = 0;
			num_fields = 0;
		};
		
		/* destructor function */
		~menu() {
			delete title;
		};

		void incr_field(int) {
			num_fields += size;
		};
		
		static int fields() {
			return num_fields;
		};

		char *name() {
			return title;
		
};
#endif	/* menu.h */
