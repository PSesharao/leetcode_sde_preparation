/*

https://leetcode.com/problems/lru-cache/


Using unordered_map or map is giving TLE for larger test cases , we can use 

vector<node*> map ; 

and initialize it in constructor 

    LRUCache(int cap) {
        capacity = cap ;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
        size = 0 ; 
        map = vector<node*>  (10009 , nullptr ) ; // as 0 <= key <= 104
    }

*/


#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define MAX 200010

void init_code()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// getting TLE need to look into 
class node {
    public:
        int key;
        int val;
        node * next;
        node * prev;
    node(int _key, int _val) {
        key = _key;
        val = _val;
        next = nullptr ; 
        prev = nullptr ; 
    }
};

class LRUCache {
public:

    int capacity ;
    // unordered_map < int, node * > map ; 
    vector<node*> map ; // (10009 , nullptr ) ; 
    //map < int, node * > map ; 
    node * head ;
    node * tail ;
    int size  ; 
    LRUCache(int cap) {
        capacity = cap ;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
        size = 0 ; 
        map = vector<node*>  (10009 , nullptr ) ; 
    }
    
    int get(int key) {

        if (map[key]!=nullptr ) {
            node * resnode = map[key] ; 
            int res = resnode -> val;
            //map.erase(key);
            //map.erase(map.begin() + key);
            map[key] = nullptr ; 
            deletenode(resnode);
            addnode(new node(key , res ));
            map[key] = head -> next;
            return res;

        }

        return -1;
    }
    
      void put(int key, int value) {
            if (map[key]!=nullptr ) {
              node * existingnode = map[key];
              //map.erase(key);
              //map.erase(map.begin() + key);
              map[key] = nullptr ; 
              deletenode(existingnode);
            }
            if (size == capacity) {
              // this will be least recently used node  
              //map.erase(map.begin() + (tail -> prev -> key) );
              map[tail -> prev -> key] = nullptr ;   
              deletenode(tail -> prev);
              
            }

            addnode(new node(key, value));
            map[key] = head -> next;
            
      }

    void addnode(node * newnode) {
        size++ ; 
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deletenode(node * delnode) {
        size -- ; 
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
        delnode-> next = nullptr ; 
        delnode -> prev = nullptr ; 
        delete delnode ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}

