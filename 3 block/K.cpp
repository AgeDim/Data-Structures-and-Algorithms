#include <stdio.h>
#include <vector>

using namespace std;

struct Sector {
    Sector *last, *next;
    bool free;
    int left, right, position;

    Sector(Sector *prev, Sector *next, bool free, int left, int right, int position);

    void rm() const;
};

int n, m, k, s;
vector<int> js;
Sector *iSector[100000], *jSector[100000];

Sector::Sector(Sector *prev, Sector *next, bool free, int left, int right, int position) {
    this->last = prev;
    this->next = next;
    this->free = free;
    this->left = left;
    this->right = right;
    this->position = position;
    if (prev) prev->next = this;
    if (next) next->last = this;
}

void Sector::rm() const{
    if (last) last->next = next;
    if (next) next->last = last;
}

void swap(int element1, int element2){
    Sector *temp = iSector[element1];
    iSector[element1] = iSector[element2];
    iSector[element2] = temp;
    iSector[element1]->position = element1;
    iSector[element2]->position = element2;
}

bool compare(int i, int j){
    return iSector[i]->right - iSector[i]->left > iSector[j]->right - iSector[j]->left;
}

void siftdown(int position){
    for(;;){
        int q = position;
        if(((position << 1) + 1 < s) && compare((position << 1) + 1, q)){ q = (position << 1 ) + 1;}
        if(((position << 1) + 2 < s) && compare((position << 1) + 2, q)){ q = (position << 1 ) + 2;}
        if(position == q) return;
        swap(position, q);
        position = q;
    }
}

void siftup(int position){
    while(position && compare(position, (position - 1) >> 1)){
        swap(position, (position - 1) >> 1);
        position = (position - 1) >> 1;
    }
}

void pop(){
    --s;
    if(s){
        swap(0, s);
        siftdown(0);
    }
}

void rm(int a){
    swap(a, s - 1);
    --s;
    siftup(a);
    siftdown(a);
}

void rm(Sector *a){
    a->position = s;
    iSector[s] = a;
    siftup(s++);
}

void alloc(int size){
    Sector *c = iSector[0];
    if(!s || (c->right - c->left < size)){
        js[k++] = 0;
        printf("-1\n");
        return;
    }
    js[k++] = 1;
    jSector[k - 1] = new Sector(c->last, c, false, c->left, c->left + size, -1);
    printf("%d\n", 1 + c->left);
    c->left += size;
    if(c->left < c->right){ siftdown(c->position);}
    else{
        c->rm();
        pop();
        delete c;
    }
}

void clear(int index){
    --index;
    if(!((0 <= index) && (index < k) && (js[index] != 2))){
        index = index;
    }
    js[k++] = 2;
    if(!js[index]) return;
    js[index] = 2;
    Sector *c = jSector[index], *sp = c->last, *sn = c->next;
    bool bfp = sp && sp->free;
    bool bfn = sn && sn->free;
    if(!bfp && !bfn){
        c->free = true;
        rm(c);
        return;
    }
    if(!bfp){
        sn->left = c->left;
        siftup(sn->position);
        c->rm();
        delete c;
        return;
    }
    if(!bfn){
        sp->right = c->right;
        siftup(sp->position);
        c->rm();
        delete c;
        return;
    }
    sp->right = sn->right;
    siftup(sp->position);
    c->rm();
    delete c;
    rm(sn->position);
    sn->rm();
    delete sn;
}

int main() {
   js.resize(100000);
   scanf("%d %d", &n, &m);
    s = 1;
    iSector[0] = new Sector(nullptr, nullptr, true, 0, n, 0);
   for(int i = 0;i < m;i++){
       int t;
       scanf("%d", &t);
       if(t > 0){
           alloc(t);
       }else{
           clear(-t);
       }
   }
   return 0;
}