#include<iostream>
#define SPACE 10
using namespace std;
class TreeNode 
{
	public:
    	int value;
  		TreeNode * left;
  		TreeNode * right;

 	    TreeNode() 
	   	{
    		value = 0;
    		left = NULL;
    		right = NULL;
  	   	}
  		TreeNode(int v) 
  		{
    		value = v;
    		left = NULL;
    		right = NULL;
  		}
};

class BST 
{
	public:
    TreeNode * root;
  	BST() 
	{
    	root = NULL;
  	}
  	bool isTreeEmpty() 
	{
    	if (root == NULL) 
		{
      		return true;
    	} 
		else 
		{
      		return false;
    	}
  	}

  	void InsertNode(TreeNode * new_Node) 
	{
    	if (root == NULL) 
		{
      		root = new_Node;
      		cout << "\n\t\t\t\t  <<Value Inserted as root node>> " << endl;
    	} 
		else 
		{	
      		TreeNode * temp = root;
      		while (temp != NULL) 
			{
        		if (new_Node -> value == temp -> value) 
				{
          			cout << "\n\t\tValue Already exist," <<"Insert another value!" << endl;
          			return;
        		} 
				else if ((new_Node -> value < temp -> value) && (temp -> left == NULL)) 
				{
          			temp -> left = new_Node;
          			cout << "\n\t\t\t\t  <<Value Inserted to the left>> " << endl;
          			break;
        		} 
				else if (new_Node -> value < temp -> value) 
				{
          			temp = temp -> left;
        		} 
				else if ((new_Node -> value > temp -> value) && (temp -> right == NULL)) 
				{
          			temp -> right = new_Node;
          			cout << "\n\t\t\t\t  <<Value Inserted to the right>> " << endl;
          			break;
        		} 
				else 
				{
          			temp = temp -> right;
        		}
      		}
    	}
  	}
  	
  	/*TreeNode* insertRecursive(TreeNode *r, TreeNode *new_Node)
	{
		if(r==NULL)
		{
			r=new_Node;
			cout <<"Insertion successful"<<endl;
			return r;
		}
	
		if(new_Node->value < r->value)
		{
			r->left = insertRecursive(r->left,new_Node);
		}
		else if (new_Node->value > r->value)  
		{
			r->right = insertRecursive(r->right,new_Node);
		}
	   else
	   {
	     	cout << "No duplicate values allowed!" << endl;
	     	return r; 
		}
		return r;
	}*/

  	void Print2D(TreeNode * r ,int space) 
  	{
    	if (r == NULL) // Base case  
      		return;
    	space += SPACE; // Increase distance between levels 
    	Print2D(r -> right, space); // Process right child first
		cout<<endl;  
    	for (int i = SPACE; i < space; i++)   
      		cout << " ";  
    	cout << r -> value << "\n"; 
    	Print2D(r -> left, space); // Process left child    
  	}

  	void printPreorder(TreeNode * r)    //(current node, Left, Right) 
  	{
    	if (r == NULL)
      	return;
    	// first print data of node 
    	cout << r -> value << " ";
    	// then recur on left sutree 
    	printPreorder(r -> left);
    	// now recur on right subtree 
    	printPreorder(r -> right);
  	}

  	void printInorder(TreeNode * r) //  (Left, current node, Right)
  	{
    	if (r == NULL)
      	return;
    	// first recur on left child 
    	printInorder(r -> left);
    	// then print the data of node 
    	cout << r -> value << " ";
    	// now recur on right child 
    	printInorder(r -> right);
  	}
  	
  	void printPostorder(TreeNode * r) //(Left, Right, Root)
  	{
    	if (r == NULL)
      	return;
    	// first recur on left subtree 
    	printPostorder(r -> left);
    	// then recur on right subtree 
    	printPostorder(r -> right);
    	// now deal with the node 
    	cout << r -> value << " ";
  	}

  	TreeNode * Search(int v) 
  	{
    	if (root == NULL) 
		{
      		return root;
    	} 
		else 
		{
      		TreeNode * temp = root;
      		while (temp != NULL) 
	  		{
        		if (v == temp -> value) 
				{
          			return temp;
        		} 
				else if (v < temp -> value) 
				{
          			temp = temp -> left;
        		}
				else 
				{
          			temp = temp -> right;
        		}
      		}
      		return NULL;
    	}
  	}

  	/*TreeNode * recursiveSearch(TreeNode * r, int val) 
  	{
    	if (r == NULL || r -> value == val)
      	return r;

    	else if (val < r -> value)
      	return recursiveSearch(r -> left, val);

    	else
      	return recursiveSearch(r -> right, val);
  	}*/

  	int Height(TreeNode * r) 
  	{
    	if (r == NULL)
      	return -1;
    	else 
		{
      	// compute the height of each subtree
      	int leftheight = Height(r -> left);
      	int rightheight = Height(r -> right);

      	//use the larger one*/
      	if (leftheight > rightheight)
        	return (leftheight + 1);
      	else 
		  	return (rightheight + 1);
    	}
  	}

  	// Print nodes at a given level 
  	void printGivenLevel(TreeNode * r, int level) 
  	{
    	if (r == NULL)
      		return;
    	else if (level == 0)
      		cout << r -> value << " ";
    	else // level > 0  
    	{
      		printGivenLevel(r -> left, level - 1);
     		printGivenLevel(r -> right, level - 1);
    	}
  	}
  	
  	void printLevelOrderBFS(TreeNode * r) 
  	{
    	int h = Height(r);
    	for (int i = 0; i <= h; i++)
      	printGivenLevel(r, i);
  	}
  	
	TreeNode * minValueNode(TreeNode * Node) 
  	{
    	TreeNode * current = Node;
    	// loop down to find the leftmost leaf
   		while (current -> left != NULL) 
		{
      		current = current -> left;
    	}
    	return current;
  	}

  	TreeNode * DeleteNode(TreeNode * r, int v) 
  	{
  		TreeNode * temp = root;
    	// base case 
    	if (r == NULL) 
		{
      		return NULL;
    	}
    	// If the key to be deleted is smaller than the root's key, 
    	// then it lies in left subtree 
    	else if (v < r -> value) 
		{
     		r -> left = DeleteNode(r -> left, v);
    	}
    	// If the key to be deleted is greater than the root's key, 
    	// then it lies in right subtree 
    	else if (v > r -> value) 
		{
      		r -> right = DeleteNode(r -> right, v);
    	}
    	// if key is same as root's key, then This is the node to be deleted 
    	else 
		{
      		// node with only one child or no child 
      		if ( r -> left == NULL)
	  		{
        		TreeNode * temp = r -> right;
        		delete r;
        		return temp;
      		} 
			else if (r -> right == NULL) 
	  		{
        		TreeNode * temp = r -> left;
        		delete r;
        		return temp;
      		} 
			else 
	  		{
        		// node with two children: Get the inorder successor (smallest 
        		// in the right subtree) 
        		TreeNode * temp = minValueNode(r -> right);
        		// Copy the inorder successor's content to this node 
        		r -> value = temp -> value;
        		// Delete the inorder successor 
        		//r -> right = DeleteNode(r -> right, temp -> value);
        		DeleteNode(r->right, temp->value); 
      		}
    	}
    	return r;
  	}

};

void UserAcount()
{
	string response,u,p,forget,newpas,username, password;
	bool RegisSuccess = false;
	bool LoginSuccess = false;
	bool confirmSuccess;
	cout<<"\n\tAre you new here --->";
	cin>>response;
	if(response == "yes" || response == "YES")
	{
		cout<<"\tKindly Register Yourself First ... \n"<<endl;
		cout<<"\t\t\t  *****************  Register  *******************"<<endl;
		cout<<"\t\tEnter the UserName : ";
		cin>>u;
		cout<<"\t\tEnter the password : ";
		cin>>p;
		cout<<endl;
		cout<<"\t\t\t  <<Thankyou, you'r successfully Register!!>> \n"<<endl;
		cout<<"\t\t\t  *****************  Login  *********************"<<endl;
		do
		{
			cout<<"\t\tEnter the UserName : ";
			cin>>username;
			cout<<"\t\tEnter your Password : ";
			cin>>password;
			if(username == u && password == p)
			{
				cout<<"\n\n\t\t\t\t   <<<< Successfully Loginn >>>> "<<endl<<endl;
				cout<<"\t\tHello! "<<username<<" We'r glade that you'r here!"<<endl;
				RegisSuccess = true;
			}
			else 
			{
				cout<<"\t\t\t\t  Sorry, Login Error "<<endl;
				cout<<"\n\t\tPlease try to Login again..\n"<<endl;
			}
		}
		while(!RegisSuccess);
	}
	else 
	{
		cout<<"\tOkay, Then you can Login here First ... \n" <<endl;
		cout<<"\t\t\t  *****************  Login  *********************"<<endl;
		cout<<"\t\tIf you already Register then you can Login here! "<<endl;
		do
		{
			cout<<"\t\tEnter the UserName : ";
			cin>>username;
			cout<<"\t\tEnter your Password : ";
			cin>>password;
			if(username == "bst" && password == "admin")
			{
				cout<<"\n\t\t\t\t  <<Successfully Login>>  \n"<<endl;
				cout<<"\t\tHello! "<<username<<" We'r glade that you'r here!"<<endl;
				LoginSuccess = true;
			}
			else 
			{
				cout<<"\n\t\t\t  Sorry, Incorrect UserName Password "<<endl;
				cout<<"\n\t\tPlease try to Login again..\n"<<endl;
				cout<<" \t\tAre you forget your password ... ";
				cin>>forget;
				if(forget == "yes" || forget == "YES")
				{
					cout<<"\n\t\t\t  *************  Change Password  ***************"<<endl;
					cout<<"\t\tEnter new password : ";
					cin>>newpas;
					do
					{
						cout<<"\t\tConfirm Password : ";
						cin>>password;
						if(password == newpas)
						{
							cout<<"\n\t\t\t\t  <<Password Change Successfully>> "<<endl;
							confirmSuccess = true;
							cout<<"\n\t\tThen, you can Login here again ... "<<endl;
							do
							{
								cout<<"\t\tUserName : ";
								cin>>username;
								cout<<"\t\tPassword : ";
								cin>>password;
								{
									if(username == "bst" && password == newpas)
									{
										cout<<"\n\t\t\t\t  <<Successfully Login>> \n"<<endl;
										cout<<"\t\tHello! "<<username<<" We'r glade that you'r here!";
										cout<<endl;
										LoginSuccess = true;
									}
									else
									{
										cout<<"\n\t\t\t  Sorry, Incorrect UserName Password "<<endl;
										cout<<"\n\t\tPlease try to Login again..\n"<<endl;
									}
								}
							}
							while(!LoginSuccess);
						}
						else
						{
							cout<<"\t\t\t\t  <<Incorrect Password>> "<<endl;
							cout<<"\t\tAgian ... "<<endl;
						}
					}
					while(!confirmSuccess);
				}
			}
		}
		while(!LoginSuccess);
	}
}

int main() 
{
  	BST obj;
  	system("color f9");
  	cout<<"\t\t  Esha Akram --------------------------------------------- 20-NTU-CS-1100\n"<<endl;
	cout<<"\t\t--------------- GRAPHICALL REPRESENTATION OF BINARY SEARCH TREE ------------"<<endl;
	UserAcount();
	int option, val;
	cout<<"\t\t********************************************************************** " <<
	"\n\n\t\t\t\t\t Welcom to My Page \t\t\n\n\t\t***************************   MAIN MENU   ****************************"<<endl;
	do
	{
		cout<<" \n\tSelect Option Number .Enter 0 to Exit. "<<endl;
		cout<<"\t\t\t\t\t  1. Insert Node " <<endl;
		cout<<"\t\t\t\t\t  2. Search Node " << endl;
		cout<<"\t\t\t\t\t  3. Delete Node "<<endl;
		cout<<"\t\t\t\t\t  4. Print the BST " <<endl;
		cout<<"\t\t\t\t\t  5. Height of Tree "<<endl;
		cout<<"\t\t\t\t\t  6. Clear Screen " <<endl;
		cout<<"\t\t\t\t\t  0. Exit Program" <<endl;
		cout<<"\n\t\tWhat Operation do you want to perform?--->";
		cin>>option;
		TreeNode* new_Node = new TreeNode();
		TreeNode* r = obj.root;
		switch(option)
		{
			case 0:
				break;
			case 1:
		        cout<<"\t\t\t  *****************  INSERT  *********************"<<endl;
				cout<<"\t\tEnter Value of TreeNode you want to Insert into BST -->";
				cin>>val;
				new_Node->value = val;
				obj.InsertNode(new_Node);
				cout<<endl;
				break;
			case 2:
		        cout<<"\t\t\t  *****************  SEARCH  *********************"<<endl;
		        cout<<"\t\tEnter Value of TreeNode you want to Search in BST -->";
		        cin>>val;
		    	new_Node = obj.Search(val);
		        if (new_Node != NULL) 
				{
					if(val < r->value)
					{
        		    	cout << "\n\t\t\t\t <<Value Found on Left side>> " << endl;
        		    }
        		    else if(val > r->value)
        		    {
        		    	cout << "\n\t\t\t\t <<Value Found on Right side>> " << endl;
        		    }
        		    else if(val == r->value)
        		    {
        		    	cout << "\n\t\t\t\t <<value Found as a root Node >>"<<endl;
					}
					
				} 
				else 
				{
				    cout << "\t\tOpps!! This Value NOT Found in BST." << endl;
      			}
				break;
			case 3:
		        cout<<"\t\t\t  *****************  DELETE  *********************"<<endl;
		        cout<<"\t\tEnter Value of TreeNode you want to Delete in BST -->";
		        cin>>val;
		        new_Node = obj.Search(val);
		        if (new_Node != NULL) 
				{
                    obj.DeleteNode(obj.root, val);
                    cout << "\n\t\t\t\t  <<Value Successfully Deleted>>  " << endl;
                } 
				else 
				{
        			cout << "\t\tOpps!! This Value NOT found in BST." << endl;
     			}
				break;
			case 4:
		        cout<<"\t\t\t  *****************  PRINT  *********************"<<endl;
		        cout<<"\n\t\t\t\t  <<BINARY SEARCH TREE>> "<<endl;
		        cout<<"\n\n";
				obj.Print2D(obj.root,15);
				cout << endl;
				cout << "\n\t\t\t  Print Level Order BFS: ";
      			obj.printLevelOrderBFS(obj.root);
      			cout<<endl;
      	      	cout <<"\t\t\t  PRE-ORDER: ";
              	obj.printPreorder(obj.root);
              	cout<<endl;
      	      	cout <<"\t\t\t  IN-ORDER: ";
      	      	obj.printInorder(obj.root);
      	      	cout<<endl;
      	      	cout <<"\t\t\t  POST-ORDER: ";
      	      	obj.printPostorder(obj.root);
      	      	cout<<endl;
				break;
			case 5:
      			cout << "\t\t\t\t  <<TREE HEIGHT>> " << endl;
      			cout << "\n\t\t\tHeight : " << obj.Height(obj.root) << endl;
     		break;
			case 6:
				system("cls");
				break;
			default:
				cout<<"\n\t\t\t Sorry, this Operation does'nt Exixt in the system!!"<<endl;
				cout<<"\n\t\tPlease, select proper Operation number from Menu : "<<endl;
				cout<<"\n\t\t\t\t  <<--------------------------->> "<<endl;
		}
	}
	while(option != 0);
	cout<<"\t\t****************************   END HERE   *********************************"<<endl;
	return 0;
}
