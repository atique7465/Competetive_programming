#include <bits/stdc++.h>
using namespace std;

#define maxn 1024
int n,t,a,b,i,j;
int inp[maxn+1][3],qr[maxn+1];

struct node
{
    int data,d;
    node *left,*right;
};

node* create_node(int data)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->d=1;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void swapnodes()
{
    node *root=create_node(1);
    queue< node* >q;
    q.push(root);
    int c=1;
    while(!q.empty())
    {
        node *cur=q.front();
        if(inp[c][1]!=-1)
        {
            node *nd=create_node(inp[c][1]);
            nd->d = cur->d+1;
            cur->left=nd;
            q.push(nd);
        }
        if(inp[c][2]!=-1)
        {
            node *nd=create_node(inp[c][2]);
            nd->d=cur->d+1;
            cur->right=nd;
            q.push(nd);
        }
        c++;
        q.pop();
    }

    //inorder(root);
    //cout<<endl;

    for(int i=1; i<=t; i++)
    {
        queue<node*>q1;
        q1.push(root);
        while(!q1.empty())
        {
            node *cur2=q1.front();
            if(cur2->d % qr[i] == 0)
            {
                node *temp=cur2->left;
                cur2->left=cur2->right;
                cur2->right=temp;
                //delete temp;
            }

            if(cur2->left!=NULL)
                q1.push(cur2->left);
            if(cur2->right!=NULL)
                q1.push(cur2->right);
            q1.pop();
        }

        inorder(root);
        cout<<endl;
    }
}

int main()
{
    cin >> n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=2; j++)
        {
            cin>>inp[i][j];
        }
    }

    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>qr[i];
    }

    swapnodes();

    return 0;
}

