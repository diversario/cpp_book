#include "../std_lib_facilities.h"
#include "Point.h"

void build_vector(vector<Point>& p, int amount) {
    while(--amount >= 0) {
        Point point;
        if (cin >> point) p.push_back(point);
        else throw runtime_error("cin fucked up");
    }
}

void save_to_file(vector<Point>& p, string path) {
    cout << "Writing file...\n";

    ofstream ofs(path.c_str());
    
    if (!ofs) throw runtime_error("Cannot open output file.");

    for (int i=0; i < p.size(); i++) {
        ofs << p[i];
    }

    ofs.close();
}

/************************************************************************/
/* Comment!                                                                     */
/************************************************************************/
void read_from_file(vector<Point>& p, string path) {
    cout << "Reading from file...\n";

    ifstream ifs(path.c_str());

    if (!ifs) throw runtime_error("Cannot open input file.");

    char ch1, ch2, ch3;
    int x, y;

    while (ifs >> ch1 >> x >> ch2 >> y >> ch3) {
        if (ch1 != '(' || ch2 != ',' || ch3 != ')') error("Bad point format");
        else {
            Point point(x,y);
            p.push_back(point);
        }
    }

    ifs.close();
}

int main() {
    vector<Point> original_points
                , processed_points;

    int total = 2;
    
    cout << "Enter " << total << " points:\n";

    build_vector(original_points, total);
    save_to_file(original_points, "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Drills\\10.1\\points.txt");
    
    keep_window_open();

    read_from_file(processed_points, "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Drills\\10.1\\points.txt");

    for (int i=0; i < processed_points.size(); i++) {
        cout << processed_points[i];
    }

    if (processed_points.size() != original_points.size()) {
        printf("Different amounts");
        return 1;
    }

    for (int i=0; i < processed_points.size(); i++) {
        if (original_points[i] != processed_points[i]) {
            printf("Data mismatch");
            return 2;
        }
    }

    keep_window_open();

    return 0;
}