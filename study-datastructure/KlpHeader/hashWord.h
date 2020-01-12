#define WORD_LEN     10
#define ull unsigned long long

struct HashWord {
	char name[WORD_LEN + 1];
	ull hashVal; // for hash compare
	HashWord* next; //for hash table
};

#define MAX_HASH_WORD 10000
HashWord HashWordBA[MAX_HASH_WORD];
int hwIdx; // init

#define BUCKET_SIZE 21
HashWord* HashTable[BUCKET_SIZE];

ull calculateHashVal(char str[]) { // hash type is ull not int
	ull hash = 0;
	int i = 0;
	while (str[i] != 0) {
		hash = (hash << 5) + (str[i] - 'a' + 1); // (hash << 5) << and + - priority 1hour
		i++;
	}
	return hash;
}

void addToHashTable(HashWord* node) {
	int pos = node->hashVal % BUCKET_SIZE; 
	HashWord* head = HashTable[pos];
	node->next = head; // head is 0 or not ?
	HashTable[pos] = node;
}

HashWord* getHashWord(char str[]) {
	ull hashVal = calculateHashVal(str);
	HashWord* head = HashTable[hashVal % BUCKET_SIZE];
	while (head != 0) {
		if (head->hashVal == hashVal) { //hashVal is faster than memcpy
			return head;
		}
		head = head->next;
	}
	return 0;
}

HashWord* creatNewHashWord(char str[]) {
	HashWord* p = &HashWordBA[hwIdx++];
	mstrcpy(p->name,str);
	p->hashVal = calculateHashVal(str);
	p->next = 0;
	return p;
}
