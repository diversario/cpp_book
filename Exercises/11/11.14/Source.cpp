#include "../../std_lib_facilities.h"

int main() {
    string file = "input.txt";
    string output_file = "output.txt";
    int num;
    vector<int> nums;

    ifstream ifs(file.c_str());
    if (!ifs) error("Could not open file for reading.");

    ofstream ofs(output_file.c_str());
    if (!ofs) error("Could not open file for writing.");

    ofs << scientific << setprecision(8);

    while(ifs >> num) {
        if (nums.size() < 4) nums.push_back(num);

        if (nums.size() == 4) {
            for (int i=0; i<nums.size(); i++) ofs << setw(20) << nums[i];
            ofs << endl;
            nums.clear();
        }
    }

    return 0;
}