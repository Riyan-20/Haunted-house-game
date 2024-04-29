#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<string.h>
#include<cstdlib>
#include<time.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define N 10
#define M 10



	/*void Print(int r, int c) {
		system("cls");
		char X = '#', S = ' ';
		char map[N][M] = { {X, X, X, X ,X, X, X, X, X ,X},
		{X, S, S, S ,S, S, S, S, S ,X},
		{X, S, S, S ,S, S, S, S, S ,X},
		{X, S, S, S ,S, S, S, S, S ,X},
		{X, S, S, S ,S, S, S, S, S ,X},
		{X, S, S, S ,S, S, S, S, S ,X},
		{X, S, S, S ,S, S, S, S, S ,X},
		{X, S, S, S ,S, S, S, S, S ,X},
		{X, S, S, S ,S, S, S, S, S ,X},
		{X, X, X, X ,X, X, X, X, X ,X} };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				if (i == r && j == c) cout << "*";
				else cout << map[i][j];
			cout << endl;
		}
	}*/



template<class T>

class stack {
	class node {
	public:
		node* next;
		T data;
	};
	node* top;
	/*node* tail;*/
	int size_of_stack;
public:

	class iterator
	{
	private : 
		node* current; 
	public : 
		iterator()
		{
			current = nullptr; 
		}

		iterator(node* c)
		{
			current = c; 
		}

		iterator operator++()
		{
			iterator ite=*this; 
			current = current->next;
			return ite;
		}

		T& operator*()
		{
			return current->data; 
		}

		bool operator !=(iterator ite)
		{
			if (current != ite.current)
			{
				return true; 
			}
			else
			{
				return false; 
			}
		}

		bool operator ==(iterator ite)
		{
			if (current == ite.current)
			{
				return true; 
			}
			else
			{
				return false; 
			}
		}
	};

	/*friend ostream& operator <<(ostream& c, list& obj)
	{
		cout << obj;
	}*/

	stack() {
		size_of_stack = 0;
		top = nullptr;
	}


	iterator begin()
	{
		return top;
	}

	

	

	void set_size(int s) {
		size_of_stack = s;
	}
	int get_size() {
		return size_of_stack;
	}

	/*void insert_at_head(T const element) {
		node* temp = new node;
		temp->data = element;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head;
			head = temp;

		}
	}
	void insert_at_end(T const element) {
		node* temp = new node;
		temp->data = element;
		temp->next = 0;
		if (head == 0) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}*/

	/*void display_coordinates(list<int>& oX, list<int>& oY) {
		node* tempX = oX.head;
		node* tempY = oY.head;
		while (tempX != nullptr && tempY != nullptr) {
			cout << "( " << tempX->data << " , " << tempY->data << " )" << endl;
			tempX = tempX->next;
			tempY = tempY->next;
		}
	}*/
	void push(T n) {
		node* temp = new node; 
		temp->next = nullptr;
		temp->data = n;
		if (top == nullptr) {
			size_of_stack++;
			top = temp;
			return;
		}
			temp->next = top;
			size_of_stack++;
			top = temp;
			return;
		
	}
	
	void pop() {
		node* top_next = top->next;
		delete top;
		top = nullptr;
		top = top_next;
		size_of_stack--;
	}

	T& get_top() {
		return top->data;
	}
	
	friend ostream& operator<<(ostream& out, stack& o) {
		out << "steps : " << o.get_size()<<endl;
		for (int a = o.get_size(); a >= 0; a--) {
			cout << o.get_top();
			o.pop();
		}
		return out;
	}

void remove_Duplicates() 
{ 
    node* current = top; 
    node* next_next; 
    if (current == NULL) 
    return; 
    while (current->next != NULL) 
    { 
    if (current->data == current->next->data) 
    {         
        next_next = current->next->next; 
        free(current->next); 
        current->next = next_next; 
    } 
    else
    { 
        current = current->next; 
    } 
    } 
} 
void print_coordinate()
{
	this->remove_Duplicates();
	this->print_coordinates(*this);
}
bool isEmpty()
{
	return (top==nullptr);
}
	void print_coordinates(stack<T>&s) {
		if(s.isEmpty())
		return;
		T data=s.get_top();
		s.pop();
		print_coordinates(s);
		cout<<data;
	}
};

class coordinates {
private:
	int x;
	int y;
	int room_num=0;
public:
	coordinates() {
		x = 0;
		y = 0;
		room_num = 0;
	}
	coordinates(int X, int Y, int Rm_num) {
		x = X;
		y = Y;
		room_num = Rm_num;
	}
	bool operator==(coordinates const& obj)

	{
		if (this->room_num == obj.room_num && this->x == obj.x && this->y == obj.y)
			return true;
		return false;
	
	}
	void set_room_num(int rm) {
		room_num = rm;
	}
	int get_room_num() {
		return room_num;
	}
	void set_X_coordinates(int X) {
		x = X;
	}
	int get_X_coordinates() {
		return x;
	}
	void set_Y_coordinates(int Y) {
		y = Y;
	}
	int get_Y_coordinates() {
		return y;
	}
	friend ostream& operator<<(ostream&out,coordinates &o) {
		cout << "Room Num : " << o.get_room_num() << endl;
		cout << "( " << o.get_X_coordinates() << " , " << o.get_Y_coordinates() << " )" << endl;
		return out;
	}
};

//template<class T>
//
//class stack
//{
//private:
//	class node
//	{
//		T data;
//		node* next;
//
//	};
//
//	node* top;
//
//public:
//
//};

class Room
{
private:
	int roomNo;
	int rows;
	int cols;
	int startingx;
	int startingy;
	char** matrix;

public:
	Room() {
		roomNo = 0;
		rows = 0;
		cols = 0;
		startingx = -1;
		startingy = -1;
		matrix = 0;
	}

	Room(int rm, int r, int c, int x, int y, char** m) {
		roomNo = rm;
		rows = r;
		cols = c;
		startingx = x;
		startingy = y;
		matrix = new char* [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new char[cols];
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = m[i][j];
			}
		}

	}


	friend ostream& operator<<(ostream& c, Room& obj)
	{
		c << obj;
		return c;
	}


};

class Hauntedhouse
{
private:
	stack<Room> house;

	int totalRooms;
	int RoomWithTreasure;
	stack<coordinates>mov_coordinates;
	int curr_room;
	bool first_room_check = false;
	int first_room;
	int count = 0;
	int room_With_treasure;

public:

	Hauntedhouse()
	{
		totalRooms = 0;
		RoomWithTreasure = -1;
	}


	void getRowsCols(string a, int& ro, int& co, int& SX, int& SY) {
		ifstream file;
		file.open(a);

		int p = 0;
		string* str = new string[15];

		while (file.eof() == 0) {
			getline(file, str[p]);
			p++;
		}

		ro = str[0][0] - '0';
		co = str[0][2] - '0';

		SX = str[1][0] - '0';
		SY = str[1][2] - '0';
	}

	void readfile(string a, char** Mtrix) {
		ifstream file;
		file.open(a);

		int p = 0;
		string* str = new string[15];

		while (file.eof() == 0) {
			getline(file, str[p]);
			p++;
		}
		file.close();

		int ro = str[0][0] - '0';
		int co = str[0][2] - '0';
		int i = 0;

        ro = ro + 2;

		int j = 2, m = 0;
		for (int k = 0; k < ro; k++,j++) {
			m = 0;
			for (int l = 0; m!=str[j].size(); m++) {
				if (str[j][m] != ' ') {
					Mtrix[k][l] = str[j][m];
					l++;
				}
			}
		}
	}

	int treasure_Room(string a,int num){
		ifstream file;
		file.open(a);

		int p = 0;
		string* str = new string[15];

		while (file.eof() == 0) {
			getline(file, str[p]);
			p++;
		}
		file.close();

		int ro = str[0][0] - '0';
		int co = str[0][2] - '0';
		int i = 0;

		ro = ro + 2;
		int found = 0;;
		int j = 2, m = 0;
		for (int k = 0; k < ro; k++, j++) {
			m = 0;
			for (int l = 0; m != str[j].size(); m++) {
				if (str[j][m] == 'T') {
					found = num;
					break;
				}
			}
			if (found != 0) {
				break;
			}
		}
		return found;
		
	}

	int portal(int i,int room_No,int T_rooms, int x, int y) {
		int R_num = 0;
		srand(time(0));    
		int coin = rand() % 2; // head=1,tail=0
		if (i == 1) {
			return -1;
		}
		if (coin == 1) {          // if head comes
		    R_num = rand() % (T_rooms)+1;
			return R_num;
		}
		if (coin == 0) { // if tail comes
			x = x + 1;
			return room_No;
		}
		

		
	}

	

	void loadRooms()
	{
		ifstream in;
		in.open("House.txt");
		string* houseFile = new string[10];
		int r = 0;
		while (in.eof() == 0)
		{
			getline(in, houseFile[r]);
			r++;
		}
		in.close();

		int total_rooms = stoi(houseFile[0]);

		cout << "Total Rooms : " << total_rooms << endl;

		int row = 0, col = 0, startX = 0, startY = 0;

		srand(time(0));    //starting with a random room
		int roomNum = rand() % (total_rooms)+1;

		int room_with_treasure=0;   //finding room with treasure
		for (int i = 1; i <= total_rooms; i++) {
			room_with_treasure = treasure_Room( houseFile[i],i);
			if (room_with_treasure != 0) {
				break;
			}    
		}
		
		int c = 0;
		int flag=0;
		while (1) {

			getRowsCols(houseFile[roomNum], row, col, startX, startY);
			char** Mtrix = new char* [row];

			for (int m = 0; m < row; m++) {
				Mtrix[m] = new char[col];
			}

			readfile(houseFile[roomNum], Mtrix);
			
			Room R(roomNum, row, col, startX, startY, Mtrix);
			
			if (roomNum == room_with_treasure) {
				flag = 1;
			}

			/*house.insert_at_end(R); 
			list<int>oX;
			list<int>oY;*/
			int check=display(roomNum,row,col,startX, startY, Mtrix);
            
			c++;
			
			if (check == 1) {
				cout << "You won the Game :)" << endl;
			
				/*stack<coordinates>::iterator ite = mov_coordinates.begin();

				while (ite!=nullptr) {
		            if(ite!=NULL)
					cout << *ite;
					
					
					++ite;
				}*/

				mov_coordinates.print_coordinate();

				break;
			}

			else if (check == 0) {
				cout << "You are eaten up by a Devil :(" << endl;
				break;
			}
			else if (check == -1) {
				cout << "You left the game ..." << endl;
				break;
			}
			else if (check == 2) {
				roomNum = room_with_treasure;
			}
			else if (check == 3) {
				roomNum=portal(c,roomNum,total_rooms,startX,startY);
				if (roomNum == -1) {
					cout<< "Game is ended ..." << endl;
					break;
				}
			}
			
		}


	}

	int display(int rm,int r, int c,int &x, int &y, char **m) {
		printroom(r,c,x,y,m);
		int a = 0;
		int l = 0;
		while (1)
		{
			l = 0;
			a = 0;
			switch ((a = _getch())) {
			case KEY_UP:
				if (x > 0) { 
					if (m[x - 1][y] != 'X') {
                     x = x - 1;}
					 }
				printroom(r, c, x, y, m);
				break;
			case KEY_DOWN:
				if (x < r - 1) {
					if (m[x + 1][y] != 'X') {
                    x = x + 1;}
					 }
				printroom(r, c, x, y, m);
				break;
			case KEY_LEFT:
				if (y > 0) {
					if (m[x][y - 1] != 'X') {
                    y = y - 1; }
					}	
				printroom(r, c, x, y, m);
				break;
			case KEY_RIGHT:
				if (y < c - 1) {
					if (m[x][y + 1] != 'X') {
						y = y + 1;}
					}
				printroom(r, c, x, y, m);
				break;
			default:
				break;
			}

			/*if (flag == 1) {
				oX.insert_at_end(x);
				oY.insert_at_end(y);
			}*/

			if (m[x][y] == 'T') {
				return 1;
				break;
			}
			if (m[x][y]=='D') {
				return 0;
				break;
			}
			if (m[x][y] == 'G') {
				return 2;
				break;
			}
			if (m[x][y] == 'P') {
				return 3;
				break;
			}
			l++;
			if (l == 1) {
            coordinates obj(x, y, rm);
			mov_coordinates.push(obj);
			}
			

		}
	}

	void printroom(int r,int c,int x, int y,char **m)
	{
		/*list<Room>::iterator ite = house.begin();

			while (ite != house.end())
			{
				cout << *ite; 
			}*/
		 
		system("cls");

		 for (int a = -2; a < c; a++) {
				cout << "#";
		}
			cout<<endl;

		for (int i = 0; i < r; i++) {
			
			cout << "#";

			for (int j = 0; j < c; j++) {

				if (i == x && j == y) {
					cout << "*";
				}
				else if (m[i][j] == 'X') {
					cout << m[i][j];
				}
				else {
					cout << " ";
				}
			}
			
			cout << "#"<< endl;
		}   
		
		for (int b = -2; b < c; b++) {
			cout << "#";
		}
		cout << endl;



	}



};


int main() {

	Hauntedhouse H;
	H.loadRooms();

	system("Pause");
	return 0;
}