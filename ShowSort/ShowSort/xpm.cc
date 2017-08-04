
#include "xpm.h"
#include <cmath>

typedef struct 
{
	int r, g, b;
} RGB;
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

	RGB HSB_2_RGB(double H, double S, double B) {

		double r, g, b;
		H = (H >= 360) ? 0 : H;

		if (S == 0) {

			r = B * 255;

			g = B * 255;

			b = B * 255;

		}
		else {

			int  i = (int)(floor((H / 60.0))) % 6;

			double f = H / 60 - i;

			double p = B * (1 - S);

			double q = B * (1 - S * f);

			double t = B * (1 - S * (1 - f));

			switch (i) {

			case 0:

				r = B, g = t, b = p;

				break;

			case 1:

				r = q; g = B; b = p;

				break;

			case 2:

				r = p; g = B; b = t;

				break;

			case 3:

				r = p; g = q; b = B;

				break;

			case 4:

				r = t; g = p; b = B;

				break;

			case 5:

				r = B; g = p; b = q;

				break;

			}

			r = r * 255;

			g = g * 255;

			b = b * 255;

		}
		RGB a{ r, g, b } ;
		std::cout << r << " "<<g <<" "<< b << std::endl;
		return a;
	};

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
		size(w, h, 36, 1);
		for (int i = 0; i < 36; i++) {
			RGB a = HSB_2_RGB(i * 10, 0.9, 0.75);
			rgb('#' + i,a.r,a.g,a.b);
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