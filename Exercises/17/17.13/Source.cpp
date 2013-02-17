#include "../../../Includes/std_lib_facilities.h"

struct God {
    God(const char* n, const char* m, const char* v, const char* w)
        : name(n), myth(m), vehicle(v), weapon(w) {}

    string name;
    string myth;
    string vehicle;
    string weapon;
};

class Link {
public:
    God* value;
    Link(God* v, Link* p=0, Link* s=0)
        : value(v), prev(p), succ(s) {}

    Link* insert(Link* n);
    Link* add(Link* n);
    Link* add_ordered(Link* n);
    Link* erase();
    Link* find(const string& v);
    const Link* find(const string& s) const;
    Link* advance(int n) const;
    Link* next() const;
    Link* previous() const;
private:
    Link* prev;
    Link* succ;
};

Link* Link::insert(Link* n) {
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
} 

Link* Link::add(Link* n) {
    n->prev = this;
    if (succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

Link* Link::add_ordered(Link* n) {
    if (n==0) return this;

    if (n->value->name.c_str()[0] > value->name.c_str()[0]) return add(n);
    else if (n->value->name.c_str()[0] < value->name.c_str()[0]) return insert(n);
    else return add(n);
}

Link* Link::erase() {
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

Link* Link::find(const string& s) {
    Link* p = this;

    while(p) {
        if (p->value->name == s) return p;
        p = p->succ;
    }

    return 0;
}

Link* Link::advance(int n) const {
    const Link* p = this;

    if (0<n) {
        while (n--) {
            if (p->succ == 0) return 0;
            p = p->succ;
        }
    } else if (n<0) {
        while(n++) {
            if (p->prev == 0) return 0;
            p = p->prev;
        }
    }

    return const_cast<Link*>(p);
}

Link* Link::next() const {
    if (!succ) return 0;
    return succ;
}

Link* Link::previous() const {
    if (!prev) return 0;
    return prev;
}

void print_all(Link* l) {
    while (l->previous()) l = l->previous();
    while (l) {
        cout << l->value->name << endl
             << '\t' << l->value->myth << endl
             << '\t' << l->value->vehicle << endl
             << '\t' << l->value->weapon << endl;
        l = l->next();
    }
}

int main () {
    Link* norse_gods = new Link(new God("Thor", "Norse", "legs", "hammer"));
    norse_gods = norse_gods->insert(new Link(new God("Odin", "Norse", "Sleipher", "")));
    norse_gods = norse_gods->insert(new Link(new God("Zeus", "Greek", "", "lightning")));
    norse_gods = norse_gods->insert(new Link(new God("Freia", "Norse", "dunno", "boobs")));

    Link* greek_gods = new Link(new God("Hera", "Greek", "wings", "chest"));
    greek_gods = greek_gods->insert(new Link(new God("Athena", "Greek", "car", "gun")));
    greek_gods = greek_gods->insert(new Link(new God("Mars", "Roman", "jet", "war")));
    greek_gods = greek_gods->insert(new Link(new God("Poseidon", "Greek", "herring", "water")));

    Link* g = greek_gods->find("Mars");
    if (g) {
        g->value->name = "Ares";
        g->value->myth = "Greek";
    }

    Link* n = norse_gods->find("Zeus");
    if (n == norse_gods) norse_gods = n->next();

    n->erase();
    greek_gods = greek_gods->insert(n);
    
    /*print_all(norse_gods);
    cout << "======================" << endl;
    print_all(greek_gods);*/

    Link* ordered_gods = new Link(new God("Thor", "Norse", "legs", "hammer"));
    ordered_gods = ordered_gods->add_ordered(new Link(new God("Odin", "Norse", "Sleipher", "")));
    ordered_gods = ordered_gods->add_ordered(new Link(new God("Zeus", "Greek", "", "lightning")));
    ordered_gods = ordered_gods->add_ordered(new Link(new God("Freia", "Norse", "dunno", "boobs")));

    print_all(ordered_gods);

    keep_window_open();
}