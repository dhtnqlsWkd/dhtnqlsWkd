#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
	string name;
	string phonenumber;
	string address;
	string birth;
public:
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}

	void setPhonenumber(string num) {
		phonenumber = num;
	}
	string getPhonenumber() {
		return phonenumber;
	}

	void setAddress(string address) {
		this->address = address;
	}
	string getAddress() {
		return address;
	}

	void setBirth(string birth) {
		this->birth = birth;
	}
	string getBirth() {
		return birth;
	}

	Person() {}
	Person(string name, string phonenumber, string address, string birth) {
		setName(name);
		setPhonenumber(phonenumber);
		setAddress(address);
		setBirth(birth);
	}
};

class Contacts {
protected:
	vector<Person> contacts;

public:
	void InsertContact() {
		string name, phonenumber, address, birth;

		cout << "이름을 입력하시오 : ";
		cin >> name;
		cout << "전화번호를 입력하시오 : ";
		cin >> phonenumber;
		cout << "주소를 입력하시오 : ";
		cin >> address;
		cout << "출생일을 입력하시오 : ";
		cin >> birth;

		Person p(name, phonenumber, address, birth);

		contacts.push_back(p);
	}

	void SearchContact() {
		string name;
		int num = 0;

		cout << "찾을 연락처의 이름을 입력하시오 : ";
		cin >> name;

		for (auto it = contacts.begin(); it != contacts.end(); it++) {
			if (it->getName() == name) {
				cout << "연락처가 존재합니다" << endl;
				cout << "이름 : " << it->getName() << endl;
				cout << "전화번호 : " << it->getPhonenumber() << endl;
				cout << "주소 : " << it->getAddress() << endl;
				cout << "출생일 : " << it->getBirth() << endl;
				num++;
			}
		}

		if (num == 0)
			cout << "연락처가 존재하지 않습니다" << endl;
	}

	void DeleteContact() {
		string name;
		vector<vector<Person>::iterator> it_arr;
		string yes_or_no;
		int num;

		cout << "삭제할 연락처의 이름을 입력하시오 : ";
		cin >> name;

		for (auto it = contacts.begin(); it != contacts.end(); it++) {
			if (it->getName() == name) {
				cout << "이름 : " << it->getName() << endl;
				cout << "전화번호 : " << it->getPhonenumber() << endl;
				cout << "주소 : " << it->getAddress() << endl;
				cout << "출생일 : " << it->getBirth() << endl;

				it_arr.push_back(it);
			}
		}

		if (it_arr.size() == 0) {
			cout << "연락처가 존재하지 않습니다" << endl;
			return;
		}

		if (it_arr.size() == 1) {
			cout << "연락처를 삭제하시겠습니까?(y/n) : ";
			cin >> yes_or_no;

			if (yes_or_no == "y")
				contacts.erase(it_arr[0]);
			else if (yes_or_no == "n");
			else
				cout << "잘못 입력했습니다" << endl;
		}

		if (it_arr.size() > 1) {
			for (int i = 0; i < it_arr.size(); i++) {
				cout << "이름 : " << it_arr[i]->getName() << endl;
				cout << "전화번호 : " << it_arr[i]->getPhonenumber() << endl;
				cout << "주소 : " << it_arr[i]->getAddress() << endl;
				cout << "출생일 : " << it_arr[i]->getBirth() << endl;
			}

			cout << "몇번 째 연락처를 삭제하시겠습니까? : ";
			cin >> num;

			contacts.erase(it_arr[num - 1]);
		}
	}

	void UpdateContact() {
		string name;
		vector<vector<Person>::iterator> it_arr;
		string yes_or_no;
		int num;

		cout << "수정할 연락처의 이름을 입력하시오 : ";
		cin >> name;

		for (auto it = contacts.begin(); it != contacts.end(); it++) {
			if (it->getName() == name) {
				cout << "이름 : " << it->getName() << endl;
				cout << "전화번호 : " << it->getPhonenumber() << endl;
				cout << "주소 : " << it->getAddress() << endl;
				cout << "출생일 : " << it->getBirth() << endl;

				it_arr.push_back(it);
			}
		}

		if (it_arr.size() == 0) {
			cout << "연락처가 존재하지 않습니다" << endl;
			return;
		}

		if (it_arr.size() == 1) {
			cout << "연락처를 수정하시겠습니까?(y/n) : ";
			cin >> yes_or_no;

			if (yes_or_no == "y") {
				string name, phonenumber, address, birth;

				cout << "이름을 입력하시오 : ";
				cin >> name;
				cout << "전화번호를 입력하시오 : ";
				cin >> phonenumber;
				cout << "주소를 입력하시오 : ";
				cin >> address;
				cout << "출생일을 입력하시오 : ";
				cin >> birth;

				it_arr[0]->setName(name);
				it_arr[0]->setPhonenumber(phonenumber);
				it_arr[0]->setAddress(address);
				it_arr[0]->setBirth(birth);
			}
		}

		if (it_arr.size() > 1) {
			string name, phonenumber, address, birth;

			for (int i = 0; i < it_arr.size(); i++) {
				cout << "이름 : " << it_arr[i]->getName() << endl;
				cout << "전화번호 : " << it_arr[i]->getPhonenumber() << endl;
				cout << "주소 : " << it_arr[i]->getAddress() << endl;
				cout << "출생일 : " << it_arr[i]->getBirth() << endl;
			}

			cout << "몇번 째 연락처를 수정하시겠습니까? : ";
			cin >> num;

			cout << "이름을 입력하시오 : ";
			cin >> name;
			cout << "전화번호를 입력하시오 : ";
			cin >> phonenumber;
			cout << "주소를 입력하시오 : ";
			cin >> address;
			cout << "출생일을 입력하시오 : ";
			cin >> birth;

			it_arr[num - 1]->setName(name);
			it_arr[num - 1]->setPhonenumber(phonenumber);
			it_arr[num - 1]->setAddress(address);
			it_arr[num - 1]->setBirth(birth);
		}
	}

	void DeleteDupContact() {
		string yes_or_no, name, birth;
		int i;
		vector<Person>::iterator it, it_i;
		vector<vector<Person>::iterator> it_arr;

		cout << "중복된 연락처를 삭제하시겠습니까? (y/n) : ";
		cin >> yes_or_no;

		if (yes_or_no == "y") {
			while (1) {
				for (it = contacts.begin(); it != contacts.end(); it++) {
					name = it->getName();
					birth = it->getBirth();
					it_arr.clear();

					for (it_i = it + 1; it_i != contacts.end(); it_i++) {
						if (it_i->getName() == name)
							if (it_i->getBirth() == birth) {
								it_arr.push_back(it_i);
							}
					}

					if (it_arr.size() > 0) {
						for (i = it_arr.size(); i > 0; i--)
							contacts.erase(it_arr[i - 1]);

						break;
					}

					if (it == contacts.end() - 1)
						return;
				}
			}
		}
		else if (yes_or_no == "n");
		else
			cout << "잘못 입력했습니다" << endl;
	}

	Contacts() {
		contacts.clear();
	}
};

void menu();

void main()
{
	menu();
}

void menu()
{
	Contacts c;
	int i;

	while (1) {
		cout << "0 => 종료" << endl;
		cout << "1 => 연락처 추가" << endl;
		cout << "2 => 연락처 검색" << endl;
		cout << "3 => 연락처 삭제" << endl;
		cout << "4 => 연락처 수정" << endl;
		cout << "5 => 중복된 연락처 삭제" << endl;
		cout << "메뉴를 선택하시오 : ";
		cin >> i;

		if (i == 0) {
			cout << "연락처 관리 프로그램을 종료합니다" << endl;
			break;
		}
		else if (i == 1)
			c.InsertContact();
		else if (i == 2)
			c.SearchContact();
		else if (i == 3)
			c.DeleteContact();
		else if (i == 4)
			c.UpdateContact();
		else if (i == 5)
			c.DeleteDupContact();
		else
			cout << "잘못 입력했습니다" << endl;
	}
}
