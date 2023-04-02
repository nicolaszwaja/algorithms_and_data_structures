#include <iostream>
#include <string>

using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree {
	
	public:
	
	struct Node {
		int value;
        Node* parent;
		Node* right=nullptr;
		Node* left=nullptr;
	};
	
	BinaryTree(){
        root_ = nullptr;
		size_= 0;
        depth_= 0;
	}

    Node* newNode(int x) {
	    Node* newNode = new Node();
	    newNode->value = x;
	    newNode->left = nullptr;
        newNode->right = nullptr;
	    return newNode;
    }

    // void printBT(const std::string& prefix, const Node* node, bool isLeft){
    //     if( node != nullptr ){
    //         cout <<prefix;
    //         cout << (isLeft ? "|--" : "--" );
    //         cout << node->value << std::endl;
    //         // enter the next tree level - left and right branch
    //         printBT( prefix + (isLeft ? "|   " : "    "), node->left, true);
    //         printBT( prefix + (isLeft ? "|   " : "    "), node->right, false);
    //     }
    // }

    void insert(int x) {
        if(empty()){
            root_ = newNode(x);
            size_=1;
            depth_=1;
            return;
        }
        Node* temproot = root_;
        currdepth = 1;
    
        bool inserted = false;
        while(!inserted){
            if(x>=temproot->value){
                currdepth++;    
                if(temproot->right==nullptr){
                    temproot->right = newNode(x);
                    size_++;
                    if(currdepth>depth_){
                        depth_=currdepth;
                    }
                    inserted = true;
                }
                temproot = temproot->right;
            }
            else if(x<temproot->value){
                currdepth++;
                if(temproot->left==nullptr){
                    temproot->left = newNode(x);
                    size_++;
                    if(currdepth>depth_){
                        depth_=currdepth;
                    }
                    inserted = true;
                }
                temproot = temproot->left;
            }
        }
    }

    Node* search(int x){
        Node* temp = root_;
        
        for(int i=0;i<depth_;i++){
            if(temp==nullptr){
                return nullptr;
            }
            if(temp->value==x){
                return temp;
            }
            else if(x>temp->value){
                temp = temp->right;
            }
            else if(x<temp->value){
                temp = temp->left;
            }
        }
        return nullptr;
    }

    Node* searchRecursiveHelper(Node* temp, int x){
        if (temp == NULL){
             return nullptr;
        }
        else{
                if (temp->value == x)
                    return temp;
                else if(temp->value > x){
                    searchRecursiveHelper(temp->left, x);
                }
                else if(temp->value < x){
                    searchRecursiveHelper(temp->right, x);  
                } 
                                   
        } 
    }          


    Node* searchRecursive(int x){
        return searchRecursiveHelper(root(), x);
    }

    int size(){
        // size_=0;
        // sizeHelper(root());
        return size_;
    }

    // void sizeHelper(Node *root){
    //     if(root==nullptr){
    //         return;
    //     } 
    //     //cout<<root->value<<" ";
    //     size_++;
    //     sizeHelper(root->left);
    //     sizeHelper(root->right);
    // }

    bool empty(){
        return size_==0;
    }

    int minimum(){
        Node* temp = root_;
	    while (temp->left != nullptr) {
			temp = temp->left;
		}
        int min = temp->value;
		
		return min;
    }

    int maximum(){
        Node* temp = root_;
		while (temp->right != nullptr) {
			temp = temp->right;
		}
        int max = temp->value;
		
		return max;
    }

    int depth(){
        return depth_;
    }

    Node* root(){
        return root_;
    }

    void inorder(Node *root){
        if(root==nullptr){
            return;
        } 
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    }

    void preorder(Node *root){
        if(root==nullptr){
            return;
        } 
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root){
        if(root==nullptr){
            return;
        }    
        postorder(root->left);
        postorder(root->right);
        cout<<root->value<<" ";
    }
	
	private:
	Node* root_;
	int size_=0;
    int depth_=0;
    int currdepth=0;
};    

#endif
