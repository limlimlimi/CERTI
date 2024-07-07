#include<iostream>
using namespace std;

#define MAX_TABLE 5 // size of table
#define MAX_KEY 8 // include null
#define MAX_DATA 12 // num of datas for hash table
#define DELETE_COUNT 6 // num of datas for deletion
#define FIND_COUNT 8 // num of datas for finding

typedef struct {
	char key[MAX_KEY];
	int value;
	Node* next;
}Node;

Node* tb[MAX_TABLE]; //hash table
char keys[MAX_DATA][MAX_KEY]; //keys
int values[MAX_DATA]; //values

void Init()
{
}

void my_str_cpy(char* dest, const char* src)
{
}

int my_str_cmp(const char* str1, const char* str2)
{
}

int has(const char* str)
{
}

void add(const char* key, int value)
{
}

void del(const char* key, int* value)
{
}

bool find(const char* key)
{
}

void print_hash()
{
}

int main()
{
}

