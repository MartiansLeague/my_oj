#include <xpm.cc>
int main() {
	Xpm x("test.xpm");
	char * a = "#1";
	char *b = "1#";
	x.row(a);
	x.row(b);
	x.build();

}