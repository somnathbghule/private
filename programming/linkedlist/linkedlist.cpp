#include <iostream>
using namespace std;
class node{
	public:
	node( node *next = NULL, int data = 0 ){
		next_ = next;
		data_ = data;
	}
	int data_;
	node *next_;
};

class list {
public:
	list() {
		head_ = NULL;
	}
	
	void insert(int data){
		node *n = new node( NULL, data);
		if(!head_){
			head_ = n;
		}else{
			n->next_ = head_;
			head_ = n;
		}	


	}
	void show(){
		node *curr = head_;
		while(curr){
			cout<< curr->data_ <<" ";
			curr = curr->next_;
		}
		cout<<endl;
	}
	void mid_of_list(){
		node *slow = head_;
		node *fast = head_->next_;		
		while ( slow->next_ && fast->next_ && fast->next_->next_ ) {
			slow = slow->next_;
			fast = fast->next_->next_;
		}
		cout<<__func__<<endl;
		cout<<"node: "<<slow->next_->data_ <<endl;

	}
	void getnode_n( int index ){
		node *n = head_;	
		int i = 0;
		while ( n && i < index ){
			i++;
			n = n->next_;
		}
		cout<<__func__<<"( "<<index<<" )"<<endl;
		cout<<"node: "<<n->data_ <<endl;
	}
	void getnode_n_from_last(int index){
		node *n =  head_;
		int len = 0;
		while (n){
			n = n->next_;
			len++;
		}
		cout<<"len: "<<len<<endl;
		n = head_;
		int i = len;
		while ( n && (i-1)  > index ){
			n = n->next_;
			i--;
		}
		cout<<__func__<<"( "<<index<<" )"<<endl;
		cout<<"node: "<<n->data_ <<endl;

	}
	void getnode_n_from_last_using_pointers( int index ){
		node *refptr =  head_;
		node *mainptr =  head_;
		int i = 0;
		while ( refptr ){
			refptr = refptr->next_;
			if ( i == index )
				break;
			i++;	
		}
		while( refptr ){
			refptr = refptr->next_;
			mainptr = mainptr->next_;
		}
		cout<<__func__<<"( "<<index<<" )"<<endl;
		cout<<"node: "<<mainptr->data_ <<endl;
	}
	void delete_list_data(){
		node *temp;
		cout<<__func__<<" "<<head_<<endl;
		while(head_){
			temp = head_->next_;	
			delete head_;
			head_ = temp;
		}	
		cout<<__func__<<" "<<head_<<endl;
	}
	void data_occurences(int data){
		node *temp = head_;
		int count = 0;
		while(temp){
			if( temp->data_ == data ){
				count++;
			}
			temp = temp->next_;
		}
		
		cout<<__func__<<endl;
		cout<<"data: "<<data<<" "<<count<<" occurence."<<endl;
	}
private:	
	node *head_;
};

int main(int argc, char **argv){
	list l;

	for ( int i = 5; i >0 ; i-- ) {
		l.insert(i);
	}
	l.insert(1);
	l.insert(3);
	l.show();
	
	//l.mid_of_list();
	//l.getnode_n(4);
	//l.getnode_n_from_last(0);
	//l.getnode_n_from_last_using_pointers(1);
	//l.delete_list_data();
	l.data_occurences(9);
	//return 
	return 0;
}
