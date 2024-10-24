#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

class QueueRing
{
	int* Wait;
	int MaxQueueLength;
	int QueueLength;

public:
	QueueRing(int m);
	~QueueRing();

	void Add(int c);
	bool Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Show();

	int GetValue() const;
};

int QueueRing::GetValue() const
{
	if (QueueLength == 0) return 0; 
	return Wait[0];
}

void QueueRing::Show()
{
	cout << "\n-------------------------------------\n";
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}

QueueRing::~QueueRing()
{
	delete[] Wait;
}

QueueRing::QueueRing(int m)
{
	MaxQueueLength = m;
	Wait = new int[MaxQueueLength];
	QueueLength = 0;
}

void QueueRing::Clear()
{
	QueueLength = 0;
}

bool QueueRing::IsEmpty()
{
	return QueueLength == 0;
}

bool QueueRing::IsFull()
{
	return QueueLength == MaxQueueLength;
}

int QueueRing::GetCount()
{
	return QueueLength;
}

void QueueRing::Add(int c)
{
	if (!IsFull()) Wait[QueueLength++] = c;
}

bool QueueRing::Extract()
{
	if (!IsEmpty()) 
	{
		int temp = Wait[0];

		for (int i = 1; i < QueueLength; i++)
		{
			Wait[i - 1] = Wait[i];
		}
		Wait[QueueLength - 1] = temp;
		return 1;
	}
	else {return 0;}
}

void Rotate(QueueRing& QUR)
{
	int count = rand() % 10 + 1; 
	for (int i = 0; i < count; i++)
	{
		QUR.Extract();
	}
}

void CheckWin(QueueRing& q1, QueueRing& q2, QueueRing& q3)
{
	if (q1.GetValue() == q2.GetValue() && q1.GetValue() == q3.GetValue()) cout << "You win!!" << endl << endl;
	else { cout << "Try again" << endl << endl; }
}

int main()
{
	srand(time(0));

	int const size = 5;
	QueueRing QUR1(size);
	QueueRing QUR2(size);
	QueueRing QUR3(size);

	for (int i = 0; i < size; i++)
	{
		QUR1.Add(i);
		QUR2.Add(i);
		QUR3.Add(i);
	}

	bool isExit = false;
	do
	{
		system("cls");
		cout << "Press Enter to rotate... ";
		cin.get();

		cout << endl << endl << " ";

		Rotate(QUR1);
		Rotate(QUR2);
		Rotate(QUR3);
		/*QUR1.Show();
		QUR2.Show();
		QUR3.Show();*/

		cout << "  " << QUR1.GetValue() << "  " << QUR2.GetValue() << "  " << QUR3.GetValue() << endl << endl;

		CheckWin(QUR1, QUR2, QUR3);

		cout << "Enter 0 to exit or any other number to play again: ";
		int exitChoice;
		cin >> exitChoice;
		if (exitChoice == 0) isExit = true;

	} while (!isExit);

	return 0;
}
