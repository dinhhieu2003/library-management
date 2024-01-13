#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <cstddef>
#include "LinkedList.h"
#include "DuLieuThuVien.h"
#include "Node.h"

template<typename T>
class AVLTree{
	public:
		T data;
		AVLTree *left;
		AVLTree *right;
		AVLTree(T data)
		{
			this->data = data;
			left = right = NULL;
		}
		int height(AVLTree *root);
		int different(AVLTree *root);
		AVLTree *rotateLL(AVLTree *root);
		AVLTree *rotateRR(AVLTree *root);
		AVLTree *rotateLR(AVLTree *root);
		AVLTree *rotateRL(AVLTree *root);
		AVLTree *insertByMaDG(AVLTree *root, T data);
		AVLTree *insertByMaDS(AVLTree *root, T data);
		AVLTree *insertByMaCS(AVLTree *root, T data);
		AVLTree *insertByName(AVLTree *root, T data);
		AVLTree *insertBySLSach(AVLTree *root, T data);
		AVLTree *insertByTenSach(AVLTree *root, T data);
		AVLTree *deleteNode(AVLTree *root, string key);
		AVLTree *balance(AVLTree *root);
		AVLTree *maxValueNode(AVLTree *root);	
		
		AVLTree *searchNodeMaDG(AVLTree *root, string data);
		AVLTree *searchNodeMaCS(AVLTree *root, string data);
		AVLTree *searchNodeMaDS(AVLTree *root, string data);
		
		AVLTree<T>* searchNodeCuonSach(AVLTree<T>* root, string maCuonSach);
		
		void printName(AVLTree *root);
		void printName_MaDG(AVLTree *root);
};

template<typename T>
void AVLTree<T>::printName(AVLTree *root) 
{
	if (root == NULL)
    	return;
	printName(root->left);
	
	cout << root->data.tenDG <<" - "<<root->data.maDG<< endl;
	
	printName(root->right);
}

template<typename T>
void AVLTree<T>::printName_MaDG(AVLTree *root) 
{
	if (root == NULL)
    	return;
	printName_MaDG(root->left);
	
	cout << root->data.maDG << " - " << root->data.tenDG << endl;
	
	printName_MaDG(root->right);
}

template<typename T>
AVLTree<T> *AVLTree<T>::rotateLL(AVLTree *parent)
{
	AVLTree *Temp;
	Temp = parent->left;
	parent->left = Temp->right;
	Temp->right = parent;
	return Temp;
}

template<typename T>
AVLTree<T> *AVLTree<T>::rotateRR(AVLTree *parent)
{
	AVLTree *Temp;
	Temp = parent->right;
	parent->right = Temp->left;
	Temp->left = parent;
	return Temp;
}

template<typename T>
AVLTree<T> *AVLTree<T>::rotateLR(AVLTree *parent)
{
	AVLTree *Temp;
	Temp = parent->left;
	parent->left = rotateRR(Temp);
	return rotateLL(parent);
}

template<typename T>
AVLTree<T> *AVLTree<T>::rotateRL(AVLTree *parent)
{
	AVLTree *Temp;
	Temp = parent->right;
	parent->right = rotateLL(Temp);
	return rotateRR(parent);
}

template<typename T>
AVLTree<T> *AVLTree<T>::insertByMaDG(AVLTree *root, T data)
{
	if(root==NULL)
		{
			root = new AVLTree<T>(data);
		}
	else if(root->data.compareMaDG(root->data,data) > 0)
		{
			root->left = insertByMaDG(root->left, data);
			root = balance(root);
		}
		else
		{
			root->right = insertByMaDG(root->right, data);
			root = balance(root);
		}
	return root;
}

template<typename T>
AVLTree<T> *AVLTree<T>::insertByMaDS(AVLTree *root, T data)
{
	if(root==NULL)
		{
			root = new AVLTree<T>(data);
		}
	else if(root->data.compareMaDS(root->data,data) > 0)
		{
			root->left = insertByMaDS(root->left, data);
			root = balance(root);
		}
		else
		{
			root->right = insertByMaDS(root->right, data);
			root = balance(root);
		}
	return root;	
}


template<typename T>
AVLTree<T> *AVLTree<T>::insertByName(AVLTree *root, T data)
{
	if(root==NULL)
		{
			root = new AVLTree<T>(data);
		}
	else if(root->data.compareName(root->data,data) > 0)
		{
			root->left = insertByName(root->left, data);
			root = balance(root);
		}
		else
		{
			root->right = insertByName(root->right, data);
			root = balance(root);
		}
	return root;
}

template<typename T>
AVLTree<T> *AVLTree<T>::insertBySLSach(AVLTree *root, T data)
{
	if(root==NULL)
		{
			root = new AVLTree<T>(data);
		}
	else if(root->data.soSachDaMuon > data.soSachDaMuon)
		{
			root->left = insertBySLSach(root->left, data);
			root = balance(root);
		}
		else
		{
			root->right = insertBySLSach(root->right, data);
			root = balance(root);
		}
	return root;
}

template<typename T>
AVLTree<T> *AVLTree<T>::insertByMaCS(AVLTree *root, T data)
{
	if(root==NULL)
		{
			root = new AVLTree<T>(data);
		}
	else if(root->data.compareMaCS(root->data,data) > 0)
		{
			root->left = insertByMaCS(root->left, data);
			root = balance(root);
		}
		else
		{
			root->right = insertByMaCS(root->right, data);
			root = balance(root);
		}
	return root;
}

template<typename T>
int AVLTree<T>::height(AVLTree *root)
{
	int h=0;
	if(root!=NULL)
	{
		int height_left = height(root->left);
		int height_right = height(root->right);
		int max_height = max(height_left, height_right) + 1;
		h=max_height;
	}
	return h;
}

template<typename T>
int AVLTree<T>::different(AVLTree *root)
{
	int height_left = height(root->left);
	int height_right = height(root->right);
	int factor = height_left - height_right;
	return factor;	
}

template<typename T>
AVLTree<T> *AVLTree<T>::balance(AVLTree *root)
{
	int bal_factor = different(root);
	if(bal_factor > 1)
	{
		if(different(root->left) > 0)
			root = rotateLL(root);
		else
			root = rotateLR(root);
	}
	else if(bal_factor < -1)
		{
			if(different(root->right) > 0)
				root = rotateRL(root);
			else
				root = rotateRR(root);
		}
	return root;
}

template<typename T>
AVLTree<T> *AVLTree<T>::maxValueNode(AVLTree *root)
{
    AVLTree *cur = root;
    while (cur->right != NULL)
        cur = cur->right;
    return cur;
}

template<typename T>
AVLTree<T> *AVLTree<T>::deleteNode(AVLTree *root, string key)
{
    if (root == NULL)
        return root;
    if (root->data.maDG.compare(key) < 0)
        root->right = deleteNode(root->right, key);
    else if (root->data.maDG.compare(key) > 0)
        root->left = deleteNode(root->left, key);
    	else 
		{
        	if (root->left == NULL || root->right == NULL) 
			{
	            AVLTree* temp = root->left;
	            if (root->right != NULL)
	                temp = root->right;
	 
	            if (temp == NULL) 
				{
	                temp = root;
	                root = NULL;
	                delete temp;
	            }
            	else 
				{
                	*root = *temp;
                	delete temp;
            	}
        	}
        	else 
			{
	            AVLTree *temp = maxValueNode(root->right);
	            root->data = temp->data;
	            root->right = deleteNode(root->right, temp->data.maDG);
        	}
    	}
    return root;
}

template<typename T>
AVLTree<T>* AVLTree<T>::searchNodeMaDG(AVLTree *root, string data)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->data.compareStringMaDG(root->data.maDG, data) > 0)
	{
		return searchNodeMaDG(root->left, data);
	}
	else if(root->data.compareStringMaDG(root->data.maDG, data) < 0)
	{
		return searchNodeMaDG(root->right, data);
	}
	else
		return root;
}

template<typename T>
AVLTree<T>* AVLTree<T>::searchNodeMaCS(AVLTree *root, string data)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->data.compareMC(root->data.maCuon,data) > 0)
	{
		return searchNodeMaCS(root->left, data);
	}
	else if(root->data.compareMC(root->data.maCuon,data) < 0)
	{
		return searchNodeMaCS(root->right, data);
	}
	else
		return root;
}

template<typename T>
AVLTree<T>* AVLTree<T>::searchNodeMaDS(AVLTree *root, string data)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->data.compareDS(root->data.maDauSach,data) > 0)
	{
		return searchNodeMaCS(root->left, data);
	}
	else if(root->data.compareDS(root->data.maDauSach,data) < 0)
	{
		return searchNodeMaCS(root->right, data);
	}
	else
		return root;
}

template<typename T>
AVLTree<T>* AVLTree<T>::searchNodeCuonSach(AVLTree<T>* root, string maCuonSach)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->data->data.compareMC(root->data->data.maCuon,maCuonSach) > 0)
	{
		return searchNodeCuonSach(root->left, maCuonSach);
	}
	else if(root->data->data.compareMC(root->data->data.maCuon,maCuonSach) < 0)
	{
		return searchNodeCuonSach(root->right, maCuonSach);
	}
	else
		return root;
}

template<typename T>
AVLTree<T>* AVLTree<T>::insertByTenSach(AVLTree *root, T data)
{
	if(root==NULL)
		{
			root = new AVLTree<T>(data);
		}
	else if(root->data.compareTenSach(root->data,data) > 0)
		{
			root->left = insertByTenSach(root->left, data);
			root = balance(root);
		}
		else
		{
			root->right = insertByTenSach(root->right, data);
			root = balance(root);
		}
	return root;
}

#endif
