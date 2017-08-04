struct Point {
	int x;
	int y;
};
class PointConsumer {
public:
	void set_point(Point p) {};
	//void set_points(initializer_list<Point> my_list) {};
};
int main() {
	PointConsumer pc{};
	pc.set_point({});
	pc.set_point({ 3, 4 });
}