 #include<bits/stdc++.h>
 using namespace std;
  
  class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
  };

  class Trie {
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        //assumption, word will be in capital
        int index= word[0] - 'A';
        TrieNode* child;

        //present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        //recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }


    //serach 
    bool searchUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index= word[0] - 'A';
        TrieNode* child;

        //present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            return false;
        }

        //recursion
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode* root, string word){
        stack<TrieNode*> wordtoDelete;

        while(word.length()!=0){
            if(!root){
                cout<<"word not present"<<endl;
                return ;
            }
            wordtoDelete.push(root);

            word = word.substr(1);
            int index = word[0] -'A';
            root = root->children[index];
        }

        while(!wordtoDelete.empty()){
            TrieNode* temp = wordtoDelete.top();
            wordtoDelete.pop();

            delete temp;
        }
    }
    void removeword(string word){
        int index = word[0] - 'A';

        //present 
        if(root->children[index] != NULL){
            removeUtil(root->children[index], word);
            root->children[index] = NULL;
        }
        else{
            //absent
            cout<<"word not present"<<endl;
        }
    }
  };

 int main(){
     Trie *t= new Trie();

     t->insertWord("CAT");
     t->insertWord("ARM");
     t->insertWord("TIME");

     cout<<"Present or not search a word in trie: "<<t->searchWord("ARM")<<endl;

     cout<<"Present or not search a word in trie: "<<t->searchWord("CAT")<<endl;
      t->removeword("CAT");
     cout<<"Present or not search a word in trie: "<<t->searchWord("CAT")<<endl;
     
  
   return 0;
 }