#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
      int val;
      ListNode *next;
      public:
      ListNode(){
        val = 0;
        next = nullptr;
      }
      ListNode(int x){
        val=x;
        next=nullptr;
      }
      ListNode(int x, ListNode *next) : val(x),next(next) {
        // val = x;
        // next = next;
      }
  };

ListNode* convertToLinkedList(vector<int> &arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i=1;i<arr.size();i++){
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover= mover->next;
    }
    return head;
}

ListNode* removeHead(ListNode* head){
    ListNode* temp = head;
    head=head->next;
    delete(temp);
    return head;
}
ListNode* removeTail(ListNode* head){
    ListNode* temp = head;
    if(head==nullptr || head->next==nullptr){
        delete head;
        return nullptr;
    }
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
    return head;
}
ListNode* removeKthNode(ListNode* head,int k,int n){  
    if(head==NULL ||  k <= 0 || k > n) return head;
    if(k==1) return removeHead(head);
    if(k==n) return removeTail(head);
    ListNode* temp = head;
    int cnt=1;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
        if(cnt==k-1) break;
    }
    ListNode* del = temp->next;
    temp->next = del->next;
    delete(del);
    return head;
}
ListNode* reverseLinkedList(ListNode* head){
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr!=nullptr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
ListNode* addTwoLinkedList(ListNode* head1,ListNode* head2){
    ListNode* dummyHead = new ListNode(-1);
    ListNode* dummyTail = dummyHead;
    int carry=0;
    while(head1 || head2 || carry!=0){
        int sum = 0;
        sum+=carry;
        if(head1){
            sum+=head1->val;
            head1=head1->next;
        }
        if(head2){
            sum+=head2->val;
            head2=head2->next;
        }
        carry=sum/10;
        ListNode* temp = new ListNode(sum%10);
        dummyTail->next=temp;
        dummyTail=dummyTail->next;
    }
    return dummyHead->next;
}
ListNode* oddEvenList(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* odd = head;
    ListNode* evenHead = head->next;//sochne wali baat h bhai 
    ListNode* even = head->next;
    while(even!=nullptr && even->next!=nullptr){//this condition 
        odd->next  = odd->next->next;
        even->next = even->next->next;
        odd=odd->next;
        even=even->next;  
    }
    odd->next = evenHead;
    return head;
}
ListNode* segregate(ListNode* head){
    ListNode* zeroHead = new ListNode(-1);  
    ListNode* oneHead  = new ListNode(-1); 
    ListNode* twoHead  = new ListNode(-1); 

    ListNode* one = oneHead;
    ListNode* zero = zeroHead;
    ListNode* two = twoHead;
    ListNode* temp = head;

    while(temp!=NULL){
        if(temp->val == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->val == 1){
            one->next = temp;
            one = one->next;
        }else{
            two->next = temp;
            two = two->next;
        }
        temp=temp->next;
    }

    zero->next = (oneHead->next!=nullptr) ? oneHead->next : twoHead->next;
    one->next  = twoHead->next;
    two->next = NULL; //necessary condition
    ListNode* newNode =  zeroHead->next; 
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);
    return newNode; 
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;  
    ListNode* slow = head;
    for(int i=1;i<=n;i++) fast=fast->next;
    if(fast==NULL){
        return head->next;
    }
    while(fast->next != NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next = slow->next->next;
    return head;
}


bool isPalindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){//yha yaad rkhna
        slow=slow->next;
        fast=fast->next->next;
    }
    //slow is on middle
    ListNode* newHead = reverseLinkedList(slow->next); 
    ListNode* curr1 = newHead;
    ListNode* curr2 = head;
    while(curr1!=NULL){
        if(curr1->val != curr2->val){
            return false;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return true;
}
int helper(ListNode* temp){
    if(temp==NULL) return 1;
    int carry = helper(temp->next);
    temp->val+=carry;
    if(temp->val < 10){
        return 0;
    }
    temp->val = 0;
    return 1;

}
ListNode* addOneToLinkedList(ListNode* head){
    if(head==NULL) return new ListNode(1);
    int carry = helper(head);
    if(carry==1){
        ListNode* temp = new ListNode(1);
        temp->next = head;
        head = temp;
    }
    return head;
}
//brute force
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> mp; // we are storing pointer
        while(headA!=NULL){
            mp[headA] = 1;
            headA = headA->next;
        }

        while(headB){
            if(mp.find(headB)!=mp.end()){
                return headB;
            }
        headB = headB->next;
        }    
        return nullptr;
    }
    // ek treeka ye bhi ho skta dono ki lenegth nikaalo and bdi lenegth se chote ko minus kro jo aaye utna bde waale ko aage bdahao then ccompare kro


//optimal 
ListNode *getIntersectionNodeOptimal(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return nullptr;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2) return temp1;
            if(temp1==nullptr) temp1 = headB;
            if(temp2==nullptr) temp2 = headA;
        }
        return temp1;
    }

    ListNode* middleNode(ListNode* head) {
        //one pass
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }

    //https://drive.google.com/file/d/1EZQXpBEzzIG5Znnr-n8uVe_zoQmmSdj5/view?usp=sharing/
    ListNode *detectCycleLengthOfLoop(ListNode *head) {
      if(head==NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(slow==fast){
            ListNode* p = head;
            while(p!=slow){
                p=p->next;
                slow=slow->next;
            }
            return slow;
        }
        return NULL;
    }



        ListNode* deleteMiddle(ListNode* head) {
                if(head==NULL || head->next==NULL) return NULL;
                ListNode* slow = head;
                ListNode* fast = head;
                fast=head->next->next; //slow ko ek piche rkhna h na
                while(fast!=NULL && fast->next!=NULL){
                    slow=slow->next;
                    fast=fast->next->next;
                }
                ListNode* middle = slow->next;
                slow->next = slow->next->next;
                delete(middle);
                return head;
        }   

        /*
        delete all occurences of k from a doubly linked list 
        void deleteAllOccurOfX(struct Node** head, int k) {
        Node* temp = *head;
        
        while (temp != nullptr) {
            if (temp->data == k) {
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;

                // If the node to be deleted is the head node
                if (temp == *head) {
                    *head = nextNode;
                }

                // Adjust the pointers of the neighboring nodes
                if (nextNode != nullptr) {
                    nextNode->prev = prevNode;
                }
                if (prevNode != nullptr) {
                    prevNode->next = nextNode;
                }

                // Free the current node
                delete temp;

                // Move to the next node
                temp = nextNode;
            } else {
                // Move to the next node
                temp = temp->next;
            }
        }
    } //gfg


    
    //find pairs with given sum -- gfg
    //doubly linked list , 2 pointer approach

    Node* findTail(Node* head){
    Node* tail = head;
    while(tail->next != NULL){
        tail=tail->next;
    }
    return tail;
}
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
       //***************two pointer*********************
        
        vector<pair<int, int>> ds;
        if(head==NULL) return ds; 
        Node* left  = head;
        Node* right = findTail(head);
        while(left->data<right->data){
            if(left->data + right->data == target ){
                ds.push_back({left->data,right->data});
                left = left->next;
                right= right->prev;
            }
            else if(left->data + right->data < target){
                left = left->next;
            }
            else{
                right = right->prev;
            }
        }
        return ds;
        }


    //remove duplicates from a sorted linked list // array ko elekr smjho
        Node * removeDuplicates(struct Node *head)
    {
        Node* temp = head;
        while(temp!=NULL && temp->next != NULL){
            Node* nextNode = temp->next;
            while(nextNode!=NULL && temp->data == nextNode->data){
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                free(duplicate);
            }
            temp->next = nextNode;
            if(nextNode)nextNode->prev = temp;
            temp = temp->next;
        }
        return head;
    }

    */ 
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;
        ListNode* list1ptr = list1;
        ListNode* list2ptr = list2;

        while( list1ptr != NULL && list2ptr != NULL ){
            if( list1ptr->val <= list2ptr->val ){
            ptr->next = list1ptr;
            ptr = ptr->next;
            list1ptr = list1ptr->next;
            }else{
            ptr->next = list2ptr;
            ptr = ptr->next;
            list2ptr = list2ptr->next;
        }
    }
    while(list1ptr != NULL ){
            ptr->next = list1ptr;
            ptr = ptr->next;
            list1ptr = list1ptr->next;

    }
    while(list2ptr != NULL ){
            ptr->next = list2ptr;
            ptr = ptr->next;
            list2ptr = list2ptr->next;
    }
    ptr->next = NULL;
    return dummy->next;
    }  


     ListNode* mergeTwoSortedLists(ListNode* left,ListNode* right){
        ListNode* ptr1 = left;
        ListNode* ptr2 = right;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val < ptr2->val){
                ListNode* temp = new ListNode(ptr1->val);
                ptr1=ptr1->next;
                dummyTail->next = temp;
                dummyTail=dummyTail->next;
            }
            else{
                ListNode* temp = new ListNode(ptr2->val);
                ptr2=ptr2->next;
                dummyTail->next = temp;
                dummyTail=dummyTail->next;
            }
        }
        dummyTail->next = (ptr1!=NULL) ? ptr1 : ptr2;
        return dummyHead->next;
    }


    //merge k sorted list 
    ListNode* mergeSort(vector<ListNode*>& lists,int start,int end){
        if(start>end) return NULL;
        if(start==end) return lists[start];
        int mid = start+(end-start)/2;
        ListNode* left  = mergeSort(lists,start,mid);
        ListNode* right = mergeSort(lists,mid+1,end);
        return mergeTwoSortedLists(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //brute force : array push and sort and convert to ll
        //priority queue node->val,node , dummy me  head and push head->next to pq
        //merge two ll again merge by third ....
        //divide and conquer


        // if(lists.size()==0) return NULL;
        // ListNode* dummyHead = new ListNode(-1);
        // ListNode* dummyTail = dummyHead;
        // priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        // for(auto head:lists){
        //     if(head!=NULL) pq.push({head->val,head});
        // }
        // while(!pq.empty()){
        //     ListNode* minNode = pq.top().second; pq.pop();
        //     if(minNode->next != NULL) pq.push({minNode->next->val,minNode->next});
        //     dummyTail->next = minNode;
        //     dummyTail=dummyTail->next;
        // }
        // return dummyHead->next;
        int n=lists.size();
        return mergeSort(lists,0,n-1);
    }  


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    //flattening alinked list : gfg
    // https://drive.google.com/file/d/1zIPUKsj9GC9yNoY9Fj6lY50iBbAiX5K0/view?usp=sharing
    aise socho ki don linked list ko merge krna h
    Node* merge(Node* head1,Node* head2){
      Node* dummyHead = new Node(-1);
      Node* dummyTail = dummyHead;
      Node* l1=head1;
      Node* l2=head2;
      while(l1!=NULL && l2!=NULL){
          if(l1->data < l2->data){
              dummyTail->bottom = l1;
              dummyTail=dummyTail->bottom;
              l1=l1->bottom;
          }
          else{
              dummyTail->bottom = l2;
              dummyTail=dummyTail->bottom;
              l2=l2->bottom;
          }
      }
      
      if(l1!=NULL){
          dummyTail->bottom = l1;
      }
      if(l2!=NULL){
          dummyTail->bottom = l2;
      }
      return dummyHead->bottom;
  }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
       if(root==NULL || root->next==NULL) return root;
       Node* mergedHead = flatten(root->next);
       return merge(root,mergedHead);
    }
  */


//leetcode : https://leetcode.com/problems/rotate-list/
 ListNode* rotateRight(ListNode* head, int k) {
        //edge cases
        if(!head || !head->next || k==0) return head;

        //count length of linked list
        ListNode* curr_ptr = head;
        int cnt = 1;
        while(curr_ptr->next){
            cnt++;
            curr_ptr = curr_ptr->next;
        }

        //go till that node
        curr_ptr->next = head;
        k=k%cnt;
        k=cnt-k;

        while(k--)  curr_ptr = curr_ptr->next;

        //make the node head and break connection 
        head=curr_ptr->next;
        curr_ptr->next = NULL;
        return head;
        
        
    }


void printLinkedList(ListNode* head){
    cout<<"Priting linked list"<<endl;
    ListNode* curr = head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}
int main(){
    vector<int> arr={1,2,3,4,5};
    vector<int> arr2={9,9,9,9};
    vector<int> arr3={2,1,1,2,0,1,2,0,1,2,0};
    vector<int> arr4={1,2,3,4,3,2,1};

    ListNode* head = convertToLinkedList(arr);
    ListNode* head1 = convertToLinkedList(arr2);
    ListNode* head3 = convertToLinkedList(arr3);
    ListNode* head4 = convertToLinkedList(arr4);

    printLinkedList(head);
    // printLinkedList(removeTail(head));
    // printLinkedList(removeHead(head));
    // int k=3;
    // printLinkedList(removeKthNode(head,k,arr.size()));
    // printLinkedList(reverseLinkedList(head));
    // printLinkedList(addTwoLinkedList(head,head1));
    // printLinkedList(oddEvenList(head));
    // printLinkedList(segregate(head3));
    // printLinkedList(removeNthFromEnd(head,2));
    // printLinkedList(addOneToLinkedList(head1));          //dekhna pdega

    // bool flag = isPalindrome(head4);
    // if(flag==false){
    //     cout<<"not palindrome"<<endl;
    // }else{
    //     cout<<"palindrome"<<endl;
    // }


    // hasCycle(head1);  sochne waali baat ye h ki tm ek gol field me ho aur ek aadmi slow bhaag rha ek fast to pakki baat h ki dono kabhi na kabhi mileoge age ==r
}