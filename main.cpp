#include <QCoreApplication>
#include <QFile>
#include <iostream>

using namespace std;

QByteArray fileData;

void task4(){
    cout << "Task 4" << endl;
    int n, b;
    cin >> n;
    b = 1;
    for (int i = 0; i < n; i++)
    {
        int k = n - i;
        for (int j = k; j > 0; j--)
            cout << " ";
        for (int m = b; m > 0; m--)
        {
            cout << "*";
        }
        b+=2;
        cout << endl;
    }
}

void ReadFromFile(const char* fileName) {
    QFile f(fileName);
    f.open(QIODevice::ReadOnly);

    fileData = f.readAll();

    f.close();
}

void WriteToFile(const int* ar, int size) {
    QFile f("result.txt");
    f.open(QIODevice::WriteOnly);

    for(int i = 0; i < size; i++)
        {
            if(ar[i] != 0){
                char sim = i;
                QTextStream writeStream(&f);
                writeStream << sim << "\t " << ar[i] << "\n";
            }
        }

    f.close();
}

void task1(const char* fileName) {
    ReadFromFile("test.txt");

    int ar[256];
    memset(&ar[0], 0x00, sizeof(int) * 256);

    for (int i = 0; i < fileData.size(); i++) {
        ar[fileData[i]]++;
    }

    WriteToFile(&ar[0], 256);
    cout << "Task 1" << endl;
}

char binNumb[32];
void perevod(int numDecimal) {
    memset(binNumb, 0x00, 32 * sizeof(int));

    for (int i = 0; i < 32; i++) {
        binNumb[i] = ((numDecimal & 1 << i)) ? 0x31 : 0x30;
    }
}
void task2() {
    int numDecimal;
    cout << "Task 2. Vvod" << endl;
    cin >> numDecimal;
    perevod(numDecimal);
    cout << binNumb << endl;
}

float* getAverStr(float* a[], float* b, int n, int m){ // 5
    for (int i = 0; i < n; i++){
        float c = 0;
        for (int j = 0; j < m; j++){
            c += a[i][j];
        }
        b[i] = c / m;
        cout << b[i] << endl;
    }
    return b;
}

void task5(){
    cout << "Task 5. 3x4" << endl;
    int n = 3; int m = 4;
    float* b = new float[m];
    float** a = new float* [m];
    for (int i = 0; i < n; i++){
        a[i] = new float [n];
        for (int j = 0; j < m; j++){
        //    cin >> a[i][j];
            a[i][j] = rand()%100;
        }
    }
    cout << endl << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
    b = getAverStr(a, b, n, m);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    task1("nameOfFile");
    task2();
    task4();
    task5();

    return a.exec();
}
