#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Solution {
private:
    TrieNode* root = new TrieNode(); // Root node of the trie

    void insert(string word) {
        TrieNode* node = root; // start from the root

        for(int i = 0; i < word.size(); i++) {
            int curr = word[i] - 'a';
            if(node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        node->isWord = true;
    }

    // Method to perform DFS search
    void search(vector<vector<char>>& board, int i, int j, int n, int m, TrieNode* node, string word, vector<string>& result,
                vector<vector<int>>& visited) {
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) {
            return; // Return if cell is out of bound or already visited
        }

        char c = board[i][j];
        node = node->children[c - 'a'];
        if (node == NULL) {
            return;
        }

        word += c;
        if (node->isWord) {
            result.push_back(word);
            node->isWord = false; // Prevent duplicate entries
        }
        visited[i][j] = 1;

        search(board, i - 1, j, n, m, node, word, result, visited);
        search(board, i + 1, j, n, m, node, word, result, visited);
        search(board, i, j - 1, n, m, node, word, result, visited);
        search(board, i, j + 1, n, m, node, word, result, visited);

        visited[i][j] = 0; // Backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Trie implementation to efficiently search words on the board
        for(int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }

        int n = board.size();
        int m = board[0].size();

        vector<string> result;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vector<vector<int>> visited(n, vector<int>(m, 0));
                search(board, i, j, n, m, root, "", result, visited);
            }
        }

        return result;
    }
};
