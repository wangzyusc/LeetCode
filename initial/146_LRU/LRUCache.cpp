#include "../IOLib.hpp"

using namespace std;

class LRUCache {
private:
    struct DLListNode{
        int key;
        DLListNode* next;
        DLListNode* prev;
        DLListNode(int num){
            key = num;
            next = NULL;
            prev = NULL;
        };
    };
    unordered_map<int, int> map;
    DLListNode* head;
    DLListNode* tail;
    int capacity;
    int volume;
public:
    LRUCache(int capacity) {
        this->head = NULL;
        this->tail = NULL;
        this->capacity = capacity;
        this->volume = 0;
    }

    int get(int key) {
        if(volume == 0) return -1;
        DLListNode* ptr = head;
        while(ptr != NULL && ptr->key != key){
            ptr = ptr->next;
        }
        if(ptr == NULL) return -1;
        //now ptr should be exactly the node containing key
        if(volume == 1 || ptr == head) return map[key];
        //now volume is greater than 1 and ptr is not head
        if(ptr == tail){
            tail = tail->prev;
            tail->next = NULL;
            if(tail->prev == NULL) tail->prev = ptr;
        }
        else{
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
        }
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        return map[key];
    }

    void put(int key, int value) {
        if(head == NULL){
            head = new DLListNode(key);
            tail = head;
            volume++;
            //map.insert({key, value});
            //return;
        }
        else if(volume == 1){
            //map.insert({key, value});
            if(head->key != key){
                DLListNode* node = new DLListNode(key);
                node->next = head;
                head->prev = node;
                head = node;
                volume++;
            }
            //return;
        }
        //now the list has at least two nodes
        else{
            DLListNode* ptr = head;
            while(ptr != NULL && ptr->key != key){
                ptr = ptr->next;
            }
            if(ptr != NULL){
                if(ptr != head){
                    if(ptr == tail){
                        tail = ptr->prev;
                        tail->next = NULL;
                        if(tail->prev == NULL) tail->prev = ptr;
                    }
                    else{
                        ptr->prev->next = ptr->next;
                        ptr->next->prev = ptr->prev;
                    }
                    ptr->prev = NULL;
                    ptr->next = head;
                    head->prev = ptr;
                    head = ptr;
                }
            }
            else{
                DLListNode* node = head;
                head = new DLListNode(key);
                head->next = node;
                node->prev = head;
                volume++;
            }
        }
        if(volume > capacity){
            DLListNode* last = tail->prev;
            last->next = NULL;
            delete tail;
            tail = last;
            volume--;
        }
        auto it = map.find(key);
        if(it == map.end()){//map.insert({key, value});
        	pair<int, int> item(key, value);
        	map.insert(item);
        }
        else it->second = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(void){
    LRUCache obj(10);
	//obj.put(1,1);
	obj.put(7,28);
	//obj.put(2,2);
	obj.put(7,1);
	obj.put(8,15);
	//obj.put(4,1);
	cout << obj.get(6) << endl;
	obj.put(10,27);
	obj.put(8,10);
	//obj.put(4,1);
	cout << obj.get(8) << endl;
	obj.put(6,29);
	obj.put(1,9);
	cout << obj.get(6) << endl;
	obj.put(10,7);
	cout << obj.get(1) << endl;
	cout << obj.get(2) << endl;
	cout << obj.get(13) << endl;
	obj.put(8,30);
	obj.put(1,5);
	cout << obj.get(1) << endl;
	obj.put(13,2);
	cout << obj.get(12) << endl;
}
