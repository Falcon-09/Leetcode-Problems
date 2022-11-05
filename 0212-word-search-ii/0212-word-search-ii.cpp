class Trie {
public:
    Trie() {}
    void addWord(string word,Trie* root) {
        Trie* temp = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!temp->children[index]) {
                temp->children[index] = new Trie();
            }
            temp = temp->children[index];
        }
        temp->end = true;
    }
    Trie* children[26] = {};
    bool end = false;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> results;
        if (words.empty() || board.empty()) {
            return results;
        }
        Trie* root = new Trie();
        for (string &word : words) {
            root->addWord(word, root);
        }
        unordered_map<string, int> table;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                string temp = "";
                dfs(board, temp, i, j, table, root);
            }
        }
        for (auto &val : table) {
            results.push_back(val.first);
        }
        return results;
    }
    
    void dfs(vector<vector<char>>& board, string& word, int row, int col, unordered_map<string, int>& table, Trie* curr) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[row].size() || 
            board[row][col] == '*') {
            return;
        }
        char c = board[row][col];
        if (!curr->children[c - 'a']) {
            return;
        }
        curr = curr->children[c - 'a'];
        word.push_back(c);
        if (curr->end) {
            table[word]++;
        }
        board[row][col] = '*';
        dfs(board, word, row - 1, col, table, curr);
        dfs(board, word, row + 1, col, table, curr);
        dfs(board, word, row, col - 1, table, curr);
        dfs(board, word, row, col + 1, table, curr);
        board[row][col] = c;
        word.pop_back();
    }
};