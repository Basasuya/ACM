auto Overlap = [](pair<int, int> X, pair<int, int> Y) -> bool { 
    if(X.first > Y.first) {
        swap(X, Y);
    }
    return Y.first >= X.first && Y.first <= X.second;
};

auto GetIntersection = [](pair<int, int> X, pair<int, int> Y) -> pair<int, int> {
    return make_pair(max(X.first, Y.first), min(X.second, Y.second));
};

auto GetUnion = [](pair<int, int> X, pair<int, int> Y) -> pair<int, int> {
    return make_pair(min(X.first, Y.first), max(X.second, Y.second));
};