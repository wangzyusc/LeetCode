#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void readVector(vector<int>& input){
	string line;
	int num;
	cout << "Input number elements in linked list:" << endl;
    getline(cin, line);
    istringstream stream(line);
  	while(stream >> num){
    	input.push_back(num);
  	}
}

ListNode* readLinkedList(){
	string line;
    int num;
    cout << "Input number elements in linked list:" << endl;
    getline(cin, line);
    istringstream stream(line);
    ListNode* root = new ListNode(0), *ptr = root;
    while(stream >> num){
        ptr->next = new ListNode(num);
	    ptr = ptr->next;
    }
    ptr = root->next;
    delete root;
    return ptr;
}

void viewLinkedList(ListNode* head){
    cout << "[";
    ListNode* ptr = head;
    while(ptr != NULL){
        cout << ptr->val;
        if(ptr->next != NULL){
            cout << ", ";
        }
        ptr = ptr->next;
    }
    cout << "]" << endl;
}

void viewVector(vector<int>& vec){
  int length = vec.size();
    cout << "[";
    for(int i = 0; i < length; i++){
        cout << vec[i];
	if(i < length - 1) cout << ", ";
    }
    cout << "]" << endl;
}
