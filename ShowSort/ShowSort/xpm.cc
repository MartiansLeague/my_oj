
#include "xpm.h"

class Xpm {
private:
	FILE* f = NULL;
	char* hp = {
		"/* XPM */\n"
		"static const char * sample_xpm[] = {\n"
		"/* columns rows colors chars-per-pixel */\n"
	};
	char * e = {
		"};"
	};
	char *sizep = { "\"%d %d %d %d\",\n" };//widght,hight,color,pixel
	char *colorp = { "\"%1c %1c %s\",\n" };

	char cnbuffer[32];//颜色名字缓冲区
	char *rgbp = "#%02x%02x%02x";//RGB 颜色名字模板

	int w;
	int h;
	List<char *> body;
public:
	Xpm(char * name) {

		f = fopen(name, "w");
		if (f == NULL)
			printf("error open file %s ", name);
	}
	void size(int widght, int hight, int colors, int pixel) {
		fprintf(f, sizep, widght, hight, colors, pixel);
	}
	void rgb(char name, int   r, int   g, int   b) {
		sprintf(cnbuffer, rgbp, r, g, b);
		color(name, 'c', cnbuffer);
	}
	void  color(char name, int mod, char * colorname) {
		fprintf(f, colorp, name, mod, colorname);
	}
	void head() {
		fwrite(hp, strlen(hp), 1, f);
	}
	void end() {
		fwrite(e, sizeof(e), 1, f);

	}
	void row(char * c) {
		body.append(c);
	}
	void build() {
		int h = body.length();
		int w = strlen(body.front());
		head();
		size(w, h, 64, 1);
		for (int i = 0; i < 64; i++) {
			rgb('#' + i, i*4, i*4, i*4);
		}
		for (char ** i = body.begin(); i < body.end(); i++) {
			fprintf(f,"\"%s\"", *i);
			if (i != body.end()-1) fprintf(f, ",\n");
		}
		end();

	}
	void test() {
		head();
		size(2, 2, 2, 1);
		rgb('a', 0, 0, 0);
		rgb('b', 255, 0, 255);
		fprintf(f,"\"ab\",\n\"ba\",\n");
		end();
		//fflush(f);
		fclose(f);
	}
};