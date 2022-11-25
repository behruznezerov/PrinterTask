#include <iostream>
#include <assert.h>
#include <windows.h>
using namespace std;

class worker {

	int workerid; int age; string name; string surname;



public:

	int pagecount;

	static int Id;

	worker() {
		workerid = ++Id;
		name = "";
		surname = "";
		age = 0;
		pagecount = 0;
	}

	worker(string n, string s, int a, int p) {

		workerid = ++Id;
		name = n;
		surname = s;
		age = a;
		pagecount = p;

	}

	string getname() {
		return name;
	}

	string getsurname() {
		return surname;
	}

	int workerid() {
		return workerid;
	}

	int workerage() {
		return age;
	}

	int  workerpagecount() {
		return pagecount;
	}

	worker& operator=(const worker& oth) {

		workerid = oth.workerid;
		name = oth.name;
		surname = oth.surname;
		age = oth.age;
		pagecount = oth.pagecount;

		return *this;

	}

	friend ostream& operator<<(ostream& out, const worker& obj) {
		system("cls");
		cout << "Name : " << obj.name
			<< " Surname : " << obj.surname
			<< " Id : " << obj.workerid
			<< " Age : " << obj.age
			<< " Pagecount : " << obj.pagecount;
		for (int i = 0; i < 4; i++)
		{
			Sleep(1000);
			cout << ".";
		}
		return out;
	}

};

int worker::Id = 0;

class workerQueue {

	worker* arr = nullptr;
	int capacity = 0;
	int count = 0;
	int front = 0;
	int rear = -1;

public:

	workerQueue() = default;

	workerQueue(int size) {
		capacity = size;
		arr = new worker[capacity];
		front = 0;
		rear = -1;
		count = 0;
	}

	bool isempty() { return rear == -1; }
	bool isfull() { return count == capacity; }

	void Enqueue(worker& value) {
		assert(!isfull() && "Queue is full");
		arr[++rear] = value;
		count++;
	}

	void dequeue() {
		assert(!isempty() && "Queue is empty");
		for (int i = 0; i < count - 1; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
		rear--;
	}

	int count() {
		return count;
	}

	worker& peek() {
		assert(!isempty() && "Queue is empty");
		return arr[front];
	}

	worker& operator[](int index) {
		return arr[index];
	}

	workerQueue& operator=(const workerQueue& oth) {
		arr = oth.arr;
		capacity = oth.capacity;
		rear = oth.rear;
		count = oth.count;
		return *this;
	}

	~workerQueue() { delete[] arr; }

};

class printer {

	workerQueue queue;

public:

	printer(workerQueue& value) {
		queue = value;
	}

	void Start() {
		for (int i = 0; queue.count() != 0;)
		{
			for (; queue[i].pagecount > 0; queue[i].pagecount--)
			{
				cout << queue[i];
			}
			queue.dequeue();
		}
	}
};

int main() {

	worker Behruz("Behruz", "Nezerov", 16, 7);
	worker Elgun("Elgun", "Eyyubov", 18, 4);
	worker Kenan("Kenan", "Esgerov", 17, 2);
	workerQueue row(3);
	row.Enqueue(Behruz);
	row.Enqueue(Elgun);
	row.Enqueue(Kenan);
	printer canon(row);
	canon.Start();

}