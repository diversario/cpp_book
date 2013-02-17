#include "../../../Includes/std_lib_facilities.h"

vector<int> gv;

void f(vector<int> v) {
    vector<int> lv(v);

    for (int i=0; i<lv.size(); i++) {
        cout << "lv: " << lv[i] << endl;
    }

    vector<int> lv2(gv);

    for (int i=0; i<lv2.size(); i++) {
        cout << "lv2: " << lv2[i] << endl;
    }
}

int main(){
    for (int i=0; i<10; i++){
        gv.push_back(pow(2, i));
    }

    f(gv);

    vector<int> vv;
    vv.push_back(1);
    for (int i=1; i<10; i++){
        vv.push_back(i*vv[i-1]);
    }

    f(vv);
    keep_window_open();
}