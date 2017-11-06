#include "../IOLib.hpp"

/***
Note the forward function to skip the empty vectors.
The invariant here is that each time after calling next, the iterator is always pointing to
the next valid number in the 2d vector.
Time: see comments.
Space: O(1)
***/
class Vector2D {
public:
    //O(n) since it calls forward, but normally, O(1)
    Vector2D(vector<vector<int>>& vec2d) {
        it2d = vec2d.begin();
        end2d = vec2d.end();
        if(hasNext()){
            it1d = it2d->begin();
            forward();
        }
    }

    //O(n)
    int next() {
        int res = *it1d;
        ++it1d;
        forward();
        return res;
    }

    //O(1)
    bool hasNext() {
        return it2d != end2d;
    }
private:
    //O(n)
    void forward(){
        while(it2d != end2d && it1d == it2d->end()){
            ++it2d;
            if(it2d != end2d) it1d = it2d->begin();
            //else it1d = nullptr;
        }
    }
private:
    vector<vector<int>>::iterator it2d;
    vector<vector<int>>::iterator end2d;
    vector<int>::iterator it1d;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
