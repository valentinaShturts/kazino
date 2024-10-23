#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class QueueRing
{
	// Очередь
	int* Wait;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	QueueRing(int m);

	//Деструктор
	~QueueRing();

	// Добавление элемента
	void Add(int c);

	// Извлечение элемента
	bool Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();

	int GetValue() const;
};

int QueueRing::GetValue() const
{
	return Wait[0];
}
void QueueRing::Show() 
{
	cout << "\n-------------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}

QueueRing::~QueueRing()
{
	//удаление очереди
	delete[]Wait;
}

QueueRing::QueueRing(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

void QueueRing::Clear()
{
	// Эффективная "очистка" очереди 
	QueueLength = 0;
}

bool QueueRing::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool QueueRing::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int QueueRing::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}

void QueueRing::Add(int c)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull())
		Wait[QueueLength++] = c;
}

bool QueueRing::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// который вошел первым и сдвигаем очередь	
	if (!IsEmpty()) {
		//запомнить первый
		int temp = Wait[0];

		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];

		//забрасываем первый "вытолкнутый элемент в конец"
		Wait[QueueLength - 1] = temp;
		return 1;

	}
	else return 0;
}

void Rotate(QueueRing QUR)
{
	int count = rand() % 5;

	/*for (int i = 0; i < count; i++)
	{
		QUR.Extract();
	}*/
}

void CheckWin(QueueRing q1, QueueRing q2, QueueRing q3)
{
	if (q1.GetValue() == q2.GetValue() && q1.GetValue() == q3.GetValue()) cout << "You win!!" << endl << endl;
	else { cout << "Try again" << endl << endl; }
}
void main()
{
	srand(time(0));

	int const size = 10;
	//создание очереди
	QueueRing QUR1(size);
	QueueRing QUR2(size);
	QueueRing QUR3(size);
	

	for (int i = 0; i < size; i++) 
	{
		QUR1.Add(i);
		QUR2.Add(i);
		QUR3.Add(i);
	}
	QUR1.Show();
	bool isExit = false;
	char temp;
	do
	{
		cout << "Enter smth to rotate...";
		cin >> temp;
		Rotate(QUR1);
		Rotate(QUR2);
		Rotate(QUR3);
		cout << "  " << QUR1.GetValue() << "  " << QUR2.GetValue() << "  " << QUR1.GetValue() << endl << endl;
		CheckWin(QUR1, QUR2, QUR3);
		cout << "Enter - 1, if you want to exit...";
		cin >> isExit;
	} while (!isExit);
}

