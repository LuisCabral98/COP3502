#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie node struct
typedef struct TrieNode {
    struct TrieNode *children[26]; // Assuming lowercase English letters
    int count; // Number of occurrences of the word ending at this node
} TrieNode;

// Initialize
TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node != NULL) {
        node->count = 0;
        for (int i = 0; i < 26; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

// Inserts word into trie
void insert(TrieNode *root, char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = createTrieNode();
        }
        curr = curr->children[index];
    }
    curr->count++;
}

// Computes number of occurrence
int numberOfOccurrences(TrieNode *root, char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            return 0; // Word not found in the trie
        }
        curr = curr->children[index];
    }
    return curr->count;
}

// Deallocate
void deallocateTrie(TrieNode *root) {
    if (root != NULL) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                deallocateTrie(root->children[i]);
            }
        }
        free(root);
    }
}

// Read the dict from a file 
int readDictionary(char *filename, char **pInWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int numWords = 0;
    char word[256];
    while (fscanf(file, "%s", word) != EOF) {
        pInWords[numWords] = strdup(word);
        numWords++;
    }

    fclose(file);
    return numWords;
}

int main(void) {
    char *inWords[256];
    
    // Read the number of words in the dictionary
    int numWords = readDictionary("dictionary.txt", inWords);
    for (int i = 0; i < numWords; ++i) {
        printf("%s\n", inWords[i]);
    }
    
    TrieNode *root = createTrieNode();
    for (int i = 0; i < numWords; i++) {
        insert(root, inWords[i]);
    }
    
    // Test some words
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (int i = 0; i < 5; i++) {
        printf("\t%s : %d\n", pWords[i], numberOfOccurrences(root, pWords[i]));
    }
    
    deallocateTrie(root);
    
    return 0;
}
