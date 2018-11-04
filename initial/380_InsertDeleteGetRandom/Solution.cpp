#include "../IOLib.hpp"

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        count = 0;
        capacity = 10;
        nums = new int[capacity];
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index.find(val) != index.end()) return false;
        nums[count] = val;
        index[val] = count;
        count++;
        if(count > capacity * 0.8){
            capacity *= 2;
            int* _nums = new int[capacity];
            for(int i = 0; i < count; i++){
                _nums[i] = nums[i];
            }
            int* tmp = nums;
            nums = _nums;
            delete[] tmp;
        }
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index.find(val) == index.end()) return false;
        int idx = index[val];
        index.erase(val);
        count--;
        nums[idx] = nums[count];
        if(idx != count){
            index[nums[idx]] = idx;
        }
        if(count < capacity * 0.2 && capacity > 10){
            capacity /= 2;
            int* _nums = new int[capacity];
            for(int i = 0; i < count; i++){
                _nums[i] = nums[i];
            }
            int* tmp = nums;
            nums = _nums;
            delete[] tmp;
        }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % count];
    }
private:
    int count;
    int capacity;
    int* nums;
    unordered_map<int, int> index;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
  RandomizedSet obj;
  bool res[5] = {false};
  res[0] = obj.insert(0);
  res[1] = obj.insert(0);
  res[2] = obj.remove(0);
  res[3] = obj.insert(1);
  res[4] = obj.remove(0);
  for(bool r: res){
    cout << (r ? "true" : "false") << endl; 
  }
  return 0;
}
