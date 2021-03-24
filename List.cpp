class Node {
    public:
        int val;
        Node* next;
        Node(int x):val{x}, next{NULL}{}
    };

class MyLinkedList {
public:
    int len;
    Node* head;
    //Node* tail;
    /** Initialize your data structure here. */
    MyLinkedList() {
        len = 0;
        head = NULL;
        //tail = head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index > len-1)
            return -1;
        if (index < 0 || len <= 0)
            return -1;

        int idx=0;
        auto curr = head;
        while(idx < index){
            idx++;
            curr = curr->next;
        }
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto nn = new Node(val);
        if(len == 0){
            head = nn;
            len++;
        }
        else{
            nn->next = head;
            head = nn;
            len++;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto nn = new Node(val);
        if(len == 0){
            head = nn;
            len++;
        }
        else{
            auto cur = head;
            while(cur->next != NULL){
                cur = cur->next;
            }
            cur->next = nn;
            len++;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        auto cur = head;
        auto nn = new Node(val);
        if(index == 0)
            addAtHead(val);
        else if(index == len)
            addAtTail(val);
        else if(index > 0 && index < len){
            for(int i = 0; i < index-1; i++)
                cur = cur->next;
            nn->next = cur->next;
            cur->next = nn;
            len++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index > len-1) return;
        auto cur = head;
        if(len == 1 && index == 0){
            head = NULL;
            len--;
        }
        else if(len == 2 && index == 1){
            head->next = NULL;
            len--;
        }
        else if(len >= 2){
            auto curnxtp1 = head->next->next;
            if(index)
            {
                while(index-1){
                    index--;
                    cur = cur->next;
                    curnxtp1 = cur->next->next;
                }
                std::cout << cur->val << std::endl;
                cur->next = curnxtp1;
                len--;
            }
            else{
                head = head->next;
                len--;
            }
            
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
