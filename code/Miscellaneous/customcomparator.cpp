//Custom Comparator
struct edges{
    int a, b, w;
    bool operator<(const edges &y) { return w < y.w; }
};
