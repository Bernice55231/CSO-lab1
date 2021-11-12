The lab asks us to write a few C functions manipulating strings, and to write a hash table which can be used to lookup keys in O(1) time.

Linked List
We are required to implement a linked list, where each node stores a key/value tuple (of type kv_t). The linked list should be sorted alphbetically by each node's key.

Follow the instructions in list.c to implement the skeleton functions, list_init, list_insert_with_accum, list_find and list_get_all_tuples.


Hash table
In Python or Java, a hash table implementation is readily available to use as part of the language's core library (dictionary in Python, or HashTable from java.util.* in Java). However, C's core library has no hash tale implementation and therefore we must implement our own (or download a 3rd party library).
Our hash table stores a collection of key/value tuples. It uses a hash function (hashcode) to map a tuple according to its key to one entry among the hash table's array of entries (also called buckets). The same key always maps to the same location, but different keys may also map to the same location, a scenario referred to as ``collision''. Our hash table handles ``collision'' by chaining; in particular, each entry points to a linked list of key-value tuples. Therefore, if multiple tuples map to the same entry, they can be chained together via the corresponding linked list. In the hash table example pictured above, tuples <key="hello", val=1> and <key="hehaw", val=1> map to the same entry at index 1. Therefore, these two tuples are chained together in a linked list of 2 nodes. By contrast, there is no collision at index 5 and tuple <key="world", val=1> is the only node in its linked list.