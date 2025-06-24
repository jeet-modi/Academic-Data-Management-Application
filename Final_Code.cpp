
#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

class Node {
public:
    string sr_no = "";
    string Name = "";
    string Email = "";
    string Interview_date = "";
    string Interview_status = "";
    string Start_time = "";
    string End_time = "";
    string Programme = "";
    string Contact_no;
    string Whatsapp_no;
    string Alt_no;
    string Skype_id = "";
    string Id = "";
    string Package = "";
    string Company = "";
    bool r1 = false;
    bool r2 = false;
    bool r3 = false;
    bool r4 = false;
    bool r5 = false;
    Node* link;
};

void traverseLL(Node* q) {
    while (q != nullptr) {
        cout << q->sr_no << " ";
        cout << q->Name << " ";
        cout << q->Interview_date << " ";
        cout << q->Interview_status << " ";
        cout << q->Start_time << " ";
        cout << q->End_time << " ";
        cout << q->Id << " ";
        cout << q->Email << " ";
        cout << q->Programme << " ";
        cout << q->Contact_no << " ";
        cout << q->Whatsapp_no << " ";
        cout << q->Alt_no << " ";
        cout << q->Skype_id << " ";
        cout << q->Company << " ";
        cout << q->Package << " LPA ";
        cout << q->r1 << " ";
        cout << q->r2 << " ";
        cout << q->r3 << " ";
        cout << q->r4 << " ";
        cout << q->r5 << endl;
        q = q->link;
    }
}

Node* Store_data(Node* &head, const string &filename, Node* last) {
    ifstream file(filename);

    if (!file) {
        cout << "Unable to open file " << filename << endl;
        return last;
    }

    // Storing the round number
    bool round = true;
    string str1 = "";
    getline(file, str1, ',');

    string str;
    // Get company name in string cmpy
    string cmpy;
    getline(file, str);
    getline(file, str);
    getline(file, str);
    stringstream getcmp(str);
    getline(getcmp, cmpy, ',');
    while (cmpy[0] != '[') {
        getline(getcmp, cmpy, ',');
    }

    // Skip lines until "Sr. No." is encountered
    string desiredString = "Sr. No.";
    while (getline(file, str)) {
        if (str.find(desiredString) != string::npos)
            break;
    }

    // Store the data of the student in the element of the node respectively
    while (getline(file, str)) {
        Node* p = new Node;
        stringstream inputstring(str);
        string st;

        getline(inputstring, p->sr_no, ',');
        getline(inputstring, p->Name, ',');
        getline(inputstring, p->Interview_date, ',');
        getline(inputstring, p->Interview_status, ',');
        getline(inputstring, p->Start_time, ',');
        getline(inputstring, p->End_time, ',');
        getline(inputstring, p->Id, ',');
        getline(inputstring, p->Email, ',');
        getline(inputstring, p->Programme, ',');
    	getline(inputstring, p->Contact_no, ',');
    	getline(inputstring, p->Whatsapp_no, ',');
    	getline(inputstring, p->Alt_no, ',');
    	getline(inputstring, p->Skype_id, ',');
    	getline(inputstring, p->Package, ',');
    	p->Company = cmpy.substr(1, cmpy.length() - 2);

    	if (str1 == "Interview Schedule - Round 1") {
        	p->r1 = true;
    	}
    	else if (str1 == "Interview Schedule - Round 2") {
        	p->r2 = true;
    	}
    	else if (str1 == "Interview Schedule - Round 3") {
    	    p->r3 = true;
    	}
    	else if (str1 == "Interview Schedule - HR Round") {
    	    p->r4 = true;
    	}
    	else if (str1 == "Interview Schedule - Final Selection") {
    	    p->r5 = true;
    	}

    	p->link = nullptr;
    	if (head == nullptr) {
    	    head = p;
    	}
    	else {
        	last->link = p;
    	}
    	last = p;
    	}
    file.close();
    return last;
}

void search_node_by_Branch(Node* q) {
    int count = 0;
    string temp;
    cout << "Enter branch name you want to search for:";
    getline(cin, temp);
    while (q != NULL) {
        if (q->Programme == temp) {
            count++;
            cout << q->sr_no << " ";
            cout << q->Name << " ";
            cout << q->Interview_date << " ";
            cout << q->Interview_status << " ";
            cout << q->Start_time << " ";
            cout << q->End_time << " ";
            cout << q->Id << " ";
            cout << q->Email << " ";
            cout << q->Programme << " ";
            cout << q->Contact_no << " ";
            cout << q->Whatsapp_no << " ";
            cout << q->Alt_no << " ";
            cout << q->Skype_id << " ";
            cout << q->r1 << " ";
            cout << q->r2 << " ";
            cout << q->r3 << " ";
            cout << q->r4 << " ";
            cout << q->r5 << endl;
            q = q->link;
        }
        else {
            q = q->link;
        }
    }
    if (count == 0) {
        cout << "Branch name not found" << endl;
    }
}

void search_node_by_year(Node* q) {
    int count = 0;
    string year,temp;   
    cout << "Enter the year of batch you want to search for:";
    getline(cin, year);
    while (q != NULL) {
        temp=q->Id.substr(0,4);
        if (temp == year) {
            count++;
            cout << q->sr_no << " ";
            cout << q->Name << " ";
            cout << q->Interview_date << " ";
            cout << q->Interview_status << " ";
            cout << q->Start_time << " ";
            cout << q->End_time << " ";
            cout << q->Id << " ";
            cout << q->Email << " ";
            cout << q->Programme << " ";
            cout << q->Contact_no << " ";
            cout << q->Whatsapp_no << " ";
            cout << q->Alt_no << " ";
            cout << q->Skype_id << " ";
            cout << q->r1 << " ";
            cout << q->r2 << " ";
            cout << q->r3 << " ";
            cout << q->r4 << " ";
            cout << q->r5 << endl;
            q = q->link;
        }
        else {
            q = q->link;
        }
    }
    if (count == 0) {
        cout << "Batch not found" << endl;
    }
}

Node* merge2sortedLL_id(Node* temp1, Node* temp2) {
    Node* dummy = new Node();
    Node* temp = dummy;

    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->Id <= temp2->Id) {
            temp->link = temp1;
            temp = temp1;
            temp1 = temp1->link;
        }
        else {
            temp->link = temp2;
            temp = temp2;
            temp2 = temp2->link;
        }
    }

    if (temp1 == nullptr) {
        temp->link = temp2;
    }
    else if (temp2 == nullptr) {
        temp->link = temp1;
    }

    return dummy->link;
}

Node* findMiddleElement_id(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->link != nullptr && fast->link->link != nullptr) {
        fast = fast->link->link;
        slow = slow->link;
    }
    return slow;
}

Node* mergeSort_id(Node* head) {
    if (head == nullptr || head->link == nullptr) {
        return head;
    }

    Node* middle = findMiddleElement_id(head);
    Node* rightHead = head;
    Node* leftHead = middle->link;
    middle->link = nullptr;

    leftHead = mergeSort_id(leftHead);
    rightHead = mergeSort_id(rightHead);

    return merge2sortedLL_id(leftHead, rightHead);
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->link;
        delete temp;
    }
}

void search_node_by_name(Node* q) {
    int count = 0;
    string temp;
    cout << "Enter Name you want to search for :";
    getline(cin, temp);
    while (q != NULL) {
        if (q->Name == temp) {
            count++;
            cout << q->sr_no << " ";
            cout << q->Name << " ";
            cout << q->Interview_date << " ";
            cout << q->Interview_status << " ";
            cout << q->Start_time << " ";
            cout << q->End_time << " ";
            cout << q->Id << " ";
            cout << q->Email << " ";
            cout << q->Programme << " ";
            cout << q->Contact_no << " ";
            cout << q->Whatsapp_no << " ";
            cout << q->Alt_no << " ";
            cout << q->Skype_id << " ";
            cout << q->r1 << " ";
            cout << q->r2 << " ";
            cout << q->r3 << " ";
            cout << q->r4 << " ";
            cout << q->r5 << endl;
            q = q->link;
        }
        else {
            q = q->link;
        }
    }
    if (count == 0) {
        cout << "Name not found" << endl;
    }
}

void search_node_by_ID(Node* q) {
    int count = 0;
    string temp;
    cout << "Enter ID of student you want to search for :";
    getline(cin, temp);
    while (q != NULL) {
        if (q->Id == temp) {
            count++;
            cout << q->sr_no << " ";
            cout << q->Name << " ";
            cout << q->Interview_date << " ";
            cout << q->Interview_status << " ";
            cout << q->Start_time << " ";
            cout << q->End_time << " ";
            cout << q->Id << " ";
            cout << q->Email << " ";
            cout << q->Programme << " ";
            cout << q->Contact_no << " ";
            cout << q->Whatsapp_no << " ";
            cout << q->Alt_no << " ";
            cout << q->Skype_id << " ";
            cout << q->r1 << " ";
            cout << q->r2 << " ";
            cout << q->r3 << " ";
            cout << q->r4 << " ";
            cout << q->r5 << endl;
            q = q->link;
        }
        else {
            q = q->link;
        }
    }
    if (count == 0) {
        cout << "Id not found" << endl;
    }
}

void search_node_by_Company(Node* q) {
    int count = 0;
    string temp;
    cout << "Enter company name you want to search for:";
    getline(cin, temp);
    while (q != NULL) {
        if (q->Company == temp) {
            count++;
            cout << q->sr_no << " ";
            cout << q->Name << " ";
            cout << q->Interview_date << " ";
            cout << q->Interview_status << " ";
            cout << q->Start_time << " ";
            cout << q->End_time << " ";
            cout << q->Id << " ";
            cout << q->Email << " ";
            cout << q->Programme << " ";
            cout << q->Contact_no << " ";
            cout << q->Whatsapp_no << " ";
            cout << q->Alt_no << " ";
            cout << q->Skype_id << " ";
            cout << q->r1 << " ";
            cout << q->r2 << " ";
            cout << q->r3 << " ";
            cout << q->r4 << " ";
            cout << q->r5 << endl;
            q = q->link;
        }
        else {
            q = q->link;
        }
    }
    if (count == 0) {
        cout << "Company name not found" << endl;
    }
}

Node* merge2sortedLL_package_asc(Node* temp1, Node* temp2) {
    Node* dummy = new Node();
    Node* temp = dummy;

    while (temp1 != nullptr && temp2 != nullptr) {
        int a = stoi(temp1->Package);
        int b = stoi(temp2->Package);
        if (a <= b) {
            temp->link = temp1;
            temp = temp1;
            temp1 = temp1->link;
        }
        else {
            temp->link = temp2;
            temp = temp2;
            temp2 = temp2->link;
        }
    }

    if (temp1 == nullptr) {
        temp->link = temp2;
    }
    else if (temp2 == nullptr) {
        temp->link = temp1;
    }

    return dummy->link;
}

Node* findMiddleElement_package_asc(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->link != nullptr && fast->link->link != nullptr) {
        fast = fast->link->link;
        slow = slow->link;
    }
    return slow;
}

Node* Sortbypackage_asc(Node* head) {
    if (head == nullptr || head->link == nullptr) {
        return head;
    }

    Node* middle = findMiddleElement_package_asc(head);
    Node* rightHead = head;
    Node* leftHead = middle->link;
    middle->link = nullptr;

    leftHead = Sortbypackage_asc(leftHead);
    rightHead = Sortbypackage_asc(rightHead);

    return merge2sortedLL_package_asc(leftHead, rightHead);
}

void mean_package(Node* q){
    int count=0,sum=0,pkg;
    while(q!=NULL)
    {
     pkg=stoi(q->Package);
     sum+=pkg;
     count++;
     q=q->link;
    }cout<<"Mean Package = "<<(sum/count)<<endl;
}

int findLength(Node* head) {
    int length = 0;
    while (head != nullptr) 
    {
        length++;
        head = head->link;
    }
    return length;
}

void Median_package(Node* head){
    int l=findLength(head);
    Sortbypackage_asc(head);
    Node* temp=findMiddleElement_id(head);
    if(l%2!=0)
    {
        int p1=stoi(temp->Package);
        int p2=stoi(temp->link->Package);
        cout<<"Median Package = "<<(p1+p2)/2<<endl;
    }
    else
    {
        cout<<"Median Package = "<<temp->Package<<endl;
    }
}

void acceptance_rate(Node* head)
{
    Node* p = head;
    string str;
    cout << "Enter the name of the company: ";
	getline(cin,str);
    double R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;
    while (p != nullptr)
    {
		if(str == p->Company)
		{
			if(p->r1)
			R1++;
			if(p->r2)
			R2++;
			if(p->r3)
			R3++;
			if(p->r4)
			R4++;
			if(p->r5)
			R5++;
		}
        p = p->link;
    }
	cout<<"Number of Students selected in Round 1: "<<R1<<endl;
    cout<<"Number of Students selected in Round 2: "<<R2<<endl;
    cout<<"Number of Students selected in Round 3: "<<R3<<endl;
    cout<<"Number of Students selected in Round 4: "<<R4<<endl;
    cout<<"Number of Students selected in Round 5: "<<R5<<endl;
    // double ar2,ar3,ar4,ar5;
	// ar2 = (R2/R1)*100;
	// cout<<"Net acceptance rate in Round 2: "<<ar2<<endl;
	// ar3 = (R3/R2)*100;
	// cout<<"Net acceptance rate in Round 3: "<<ar3<<endl;
	// ar4 = (R4/R3)*100;
	// cout<<"Net acceptance rate in Round 4: "<<ar4<<endl;
	// ar5 = (R5/R4)*100;
	// cout<<"Net acceptance rate in Round 5: "<<ar5<<endl;
}

void trajectory(Node* head)
{
    Node* q = head;
    string str;
    cout << "Enter the name of the company: ";
	getline(cin,str);
    double R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;
    while (q != nullptr)
    {
		if(str == q->Company)
		{
			if(q->r1)
			R1++;

			if(q->r2)
			R2++;

			if(q->r3)
			R3++;

			if(q->r4)
			R4++;

			if(q->r5)
			R5++;
		}
        q = q->link;
    }
    double ar2,ar3,ar4,ar5;
	ar2 = (R2/R1)*100;
	ar3 = (R3/R2)*100;
	ar4 = (R4/R3)*100;
	ar5 = (R5/R4)*100;
	if(ar2>=70)
	{
		cout<<"The candidate has a good chance of qualifying Round 2 with basic preparation. " << endl;
	}
	if(ar2<70 && ar2>=40)
	{
		cout<<"The candidate has a mediocre chance of qualifying Round 2 and should focus more on Round 2. "<< endl;
	}
	if(ar2<40 && ar2>=10)
	{
		cout<<"The candidate should focus and prepare for this round very diligently as Round 2 is tough and if the candidate is able to clear this round,he will be very close to selection. " << endl;
	}
	if(ar3>=80)
	{
		cout<<"The candidate has a good chance of qualifying Round 3 with basic preparation and must prepare for further rounds in advance. " << endl;
	}
	if(ar3<80 && ar3>=40)
	{
		cout<<"The candidate has a mediocre chance of qualifying Round 3 and should focus more on Round 3. " << endl;
	}
	if(ar3<40 && ar3>=10)
	{
		cout<<"The candidate should focus and prepare for this round very diligently as Round 3 is tough and if the candidate is able to clear this round,he will be very close to selection. " << endl;
	}
	if(ar4>=85)
	{
		cout<<"The candidate has a good chance of qualifying HR Round with basic preparation. " << endl;
	}
	if(ar4<85 && ar4>=40)
	{
		cout<<"The candidate has a mediocre chance of qualifying HR Round and should focus more on his communication skills. " << endl;
	}
	if(ar4<40 && ar4>=10)
	{
		cout<<"The candidate must focus on building his overall personality and enhance his communication skill as lays much emphasis on the HR Round. " << endl;
	}
	if(ar5>=70)
	{
		cout<<"The candidate has a good chance of qualifying Final Round with basic preparation. " << endl;
	}
    if(ar5>=40 && ar5<70)
    {
        cout<<"The candidate must prepare well for this round irrespective of high chances in the Final Round."<<endl;
    }
	if(ar5<80)
	{
		cout<<"The candidate has reached till this stage with extreme dedication and persistence but it is tough to clear this round."<< endl;
	}
}

void max_min_package(Node* head)
{
    head = Sortbypackage_asc(head);
    cout<< "Minimum package: "<<head->Package<<endl;
    while(head->link->link!=NULL)
    {
        head = head->link;
    }

    cout<< "Maximum package: "<<head->Package<<endl;
}

Node* merge2sortedLL_package_dsc(Node* temp1, Node* temp2) {
    Node* dummy = new Node();
    Node* temp = dummy;

    while (temp1 != nullptr && temp2 != nullptr) {
        int a = stoi(temp1->Package);
        int b = stoi(temp2->Package);
        if (a <= b) {
            temp->link = temp1;
            temp = temp1;
            temp1 = temp1->link;
        }
        else {
            temp->link = temp2;
            temp = temp2;
            temp2 = temp2->link;
        }
    }

    if (temp1 == nullptr) {
        temp->link = temp2;
    }
    else if (temp2 == nullptr) {
        temp->link = temp1;
    }

    return dummy->link;
}

Node* findMiddleElement_package_dsc(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->link != nullptr && fast->link->link != nullptr) {
        fast = fast->link->link;
        slow = slow->link;
    }
    return slow;
}

Node* Sortbypackage_dsc(Node* head) {
    if (head == nullptr || head->link == nullptr) {
        return head;
    }

    Node* middle = findMiddleElement_package_dsc(head);
    Node* rightHead = head;
    Node* leftHead = middle->link;
    middle->link = nullptr;

    leftHead = Sortbypackage_dsc(leftHead);
    rightHead = Sortbypackage_dsc(rightHead);

    return merge2sortedLL_package_dsc(leftHead, rightHead);
}

void dream_superdream(Node* head)
{ 
    head = Sortbypackage_dsc(head);
    Node* p = head;
    cout<<endl<<"Super - Dream Companies:"<<endl;
    string str = "";
    while(head->link!=nullptr)
    {
        if(head->Package>="25")
        {
            if(str != head->Company){
            cout<<head->Company<<endl;
            str = head->Company;
            }
            else
            str = head->Company;
        }
        head = head->link;
        
    }
    cout<<endl<<"Dream Companies:"<<endl;
    str = "";
    while(p->link!=nullptr)
    {
        if(p->Package>="10" && p->Package<"25")
        {
            if(str != p->Company)
            {
            cout<<p->Company<<endl;
            str = p->Company;
            }
            else
            str = p->Company;
        }
        p = p->link;
    }
    cout<<endl;
}

int main() {
    Node* head = nullptr;
    Node* last = nullptr;
    last = Store_data(head, "Data01_1.csv", last);
    last = Store_data(head, "Data01_2.csv", last);
    last = Store_data(head, "Data01_3.csv", last);
    last = Store_data(head, "Data01_4.csv", last);
    last = Store_data(head, "Data01_5.csv", last);
    last = Store_data(head, "Data02_1.csv", last);
    last = Store_data(head, "Data02_2.csv", last);
    last = Store_data(head, "Data02_3.csv", last);
    last = Store_data(head, "Data02_4.csv", last);
    last = Store_data(head, "Data02_5.csv", last);
    last = Store_data(head, "Data03_1.csv", last);
    last = Store_data(head, "Data03_2.csv", last);
    last = Store_data(head, "Data03_3.csv", last);
    last = Store_data(head, "Data03_4.csv", last);
    last = Store_data(head, "Data03_5.csv", last);
    last = Store_data(head, "Data04_1.csv", last);
    last = Store_data(head, "Data04_2.csv", last);
    last = Store_data(head, "Data04_3.csv", last);
    last = Store_data(head, "Data04_4.csv", last);
    last = Store_data(head, "Data04_5.csv", last);
    last = Store_data(head, "Data05_1.csv", last);
    last = Store_data(head, "Data05_2.csv", last);
    last = Store_data(head, "Data05_3.csv", last);
    last = Store_data(head, "Data05_4.csv", last);
    last = Store_data(head, "Data05_5.csv", last);

    while (1) {
        cout << "1. Search a student placement data using 'Student name'." << endl;
        cout << "2. Search a student placement data using 'Student ID'." << endl;
        cout << "3. Search students placement data using 'Company name'." << endl;
        cout << "4. Search students placement data using 'Branch'." << endl;
        cout << "5. Search students placement data using 'Year'." << endl;
        cout << "6. Sort the data of students according to their 'Student ID'." << endl;
        cout << "7. Sort the data of students according to the 'package'" << endl;
        cout << "8. Find mean and median of the placement" << endl;
        cout << "9. Find the maximum and minimum package in the placement" << endl;
        cout << "10. Find the acceptnce rate of a particular company" << endl;
        cout << "11. Find the tragectory of a particular company" << endl;
        cout << "12. Print Companies offering Dream and Super Dream Packages" << endl;
        cout << "13. Exit/Don't want to perform any operation" << endl;

        int n;
        cout << "Enter the number of operation which you want to perform: ";
        cin >> n;
        cin.ignore();

        switch (n) {
        case 1:
            search_node_by_name(head);
            break;

        case 2:
            search_node_by_ID(head);
            break;

        case 3:
            search_node_by_Company(head);
            break;
        
        case 4:
            search_node_by_Branch(head);
            break;

        case 5:
            search_node_by_year(head);
            break;

        case 6:
            cout<<endl;
            head = mergeSort_id(head);
            traverseLL(head);
            cout<<endl;
            break;

        case 7:
            cout<<endl;
            head = Sortbypackage_asc(head);
            traverseLL(head);
            cout<<endl;
            break;

        case 8:
            mean_package(head);
            Median_package(head);
            break;

        case 9:
            max_min_package(head);
            break;

        case 10:
            acceptance_rate(head);
            break;

        case 11:
            trajectory(head);
            break;

        case 12:
            dream_superdream(head);
            break;

        case 13:
            cout << "Exiting..." << endl;
            exit(1);

        default:
            cout << "Invalid choice. Please enter a number between 1 and 13." << endl;
            break;
        }
    }
    
    freeList(head);
    return 0;
}
