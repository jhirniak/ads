#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
#include <iterator>

using namespace std;

template<typename K, typename V>
class LRUCache {
  private:
    const int MAX;
    int N = 0;

    typedef typename list<pair<K, V>>::iterator ListIter;
    typedef typename unordered_map<K, ListIter>::iterator MapIter;
    unordered_map<K, ListIter> lookup;
    list<pair<K, V>> lru;

    bool contains(K k) {
      return lookup.find(k) != lookup.end();
    }

    void promote(K k) {
      MapIter mit = lookup.find(k);
      if (mit != lookup.end()) {
          ListIter lit = mit->second;
          pair<K, V> elem(lit->first, lit->second);
          lru.erase(lit);
          lru.push_front(elem);
          lookup[k] = lru.begin();
      }
    }

    void removeLRU() {
      ListIter lit = prev(lru.end());
      lookup.erase(lit->first);
      lru.erase(lit);
      --N;
    }

  public:
    // will not resize as will never cross over the capacity and has MAX buckets
    LRUCache(size_t MAX) : MAX(MAX), lookup(MAX) {};
    ~LRUCache() {}
    void put(K k, V v);
    V get(K k);
};

template<typename K, typename V>
V LRUCache<K, V>::get(K k) {
  MapIter mit = lookup.find(k);
  if (mit != lookup.end()) {
    ListIter lit = mit->second;
    promote(k);
    return lit->second;
  } else {
    throw range_error("Element not in cache.");
  }
}

template<typename K, typename V>
void LRUCache<K, V>::put(K k, V v) {
  MapIter mit = lookup.find(k);

  if (mit != lookup.end()) {
    ListIter lit = mit->second;
    lru.erase(lit);
    lookup.erase(mit);
    --N;
  } else if (N == MAX) {
    removeLRU();
  }

  lru.push_front(pair<K, V>(k, v));
  lookup[k] = lru.begin();
  ++N;
}

int main() {
  LRUCache<int, string> cache(3);
  cache.put(0, "Ala ma kota!");
  cache.put(1, "Kot ma ale!");
  cache.put(2, "Relation bijection.");
  cache.put(3, "Now it will be full!");
  // cout << cache.get(0) << endl; // throws not in cache error correctly
  cout << cache.get(1) << endl;
  cout << cache.get(2) << endl;
  cout << cache.get(3) << endl;
  return 0;
}
