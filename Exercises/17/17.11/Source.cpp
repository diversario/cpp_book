#include "../../../Includes/std_lib_facilities.h"

class Link {
public:
    string value;
    Link(const string& v, Link* p=0, Link* s=0)
        : value(v), prev(p), succ(s) {}

    Link* insert(Link* n);
    Link* add(Link* n);
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
    if (n==0) return this;

    n->prev = this;
    if (this->succ) this->succ->prev = n;
    n->succ = this->succ;
    this->succ = n;
    return n;
}

Link* Link::erase() {
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

Link* Link::find(const string& s) {
    Link* p = this;

    while(p) {
        if (p->value == s) return p;
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
    while (l) {
        cout << l->value << endl;
        l = l->next();
    }
}

int main () {
    Link* norse_gods = new Link("Thor");
    norse_gods = norse_gods->insert(new Link("Odin"));
    norse_gods = norse_gods->insert(new Link("Zeus"));
    norse_gods = norse_gods->insert(new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = greek_gods->insert(new Link("Athena"));
    greek_gods = greek_gods->insert(new Link("Mars"));
    greek_gods = greek_gods->insert(new Link("Poseidon"));
    
    Link* g = greek_gods->find("Mars");
    if (g) g->value = "Ares";

    Link* n = norse_gods->find("Zeus");
    if (n == norse_gods) norse_gods = n->next();

    n->erase();
    greek_gods = greek_gods->insert(n);
    
    print_all(norse_gods);
    cout << "======================" << endl;
    print_all(greek_gods);

    keep_window_open();
}