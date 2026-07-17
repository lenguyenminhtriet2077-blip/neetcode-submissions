class LinkedList {
private:
    struct Node
    {
        int val;
        Node* next;

        Node(int val)
        {
            this->val = val;
            this->next = nullptr;
        }
    };
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    int get(int index) {
    Node* curr = head;

    // Nhảy 'index' bước
    for (int i = 0; i < index; i++) {
        if (curr == nullptr) return -1; // Đang nhảy mà hết tàu -> sai
        curr = curr->next;
    }

    // Nhảy xong kiểm tra xem có bị rớt khỏi tàu không
    if (curr == nullptr) return -1; 

    return curr->val; // Lấy giá trị toa đang đứng
}

    void insertHead(int val) {
        Node* nodeToHead = new Node(val);
        nodeToHead->next = head;
        head = nodeToHead;
        return;
    }
    
    void insertTail(int val) {
        Node* nodeToTail = new Node(val);
        Node* curr = head;

        if (head == nullptr)
        {
            head = nodeToTail;
            return;
        }
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = nodeToTail;
        return;
    }

    bool remove(int index) {
        if (head == nullptr)
            return false;
        
        if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        
        Node* prev = head;
        for (int i = 0; i < index - 1; i++)
        {
            if (prev == nullptr)
                return false;
            
            prev = prev->next;
        }

        if (prev == nullptr || prev->next == nullptr)
            return false;
        
        Node* curr = prev->next;
        prev->next = curr->next;
        delete curr;
        return true;
    }

    vector<int> getValues() {
        vector<int> result;
        Node* curr = head;
        while(curr != nullptr)
        {
            result.push_back(curr->val);
            curr = curr->next;
        }

        return result;
    }
};
