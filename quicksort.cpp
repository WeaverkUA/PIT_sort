/*Тривав черговий день Школи програмування та інформаційних технологій. Максиму
було смертельно нудно… «Чим би зайнятися? – нудьгував Максим. І тут на очі йому
потрапила велика коробка з крейдою. «Евріка!» - вигукнув Максим і терміново
відправився малювати лінії на асфальті. Під час роботи до нього приєднався Тимофій
і хлопці почали наввипередки малювати відрізки, змагаючись у кого буде довший.
Через певний час з’ясувалося, що крейда закінчилася, а на доріжках табору з’явилося
багато відрізків, розташованих на одній прямій. Частина з них накладалася один на
одного, але й були незафарбовані ділянки. Льова зацікавився цими лініями і оскільки
вони з Борею, як математики, не можуть не створити задачу на рівному місці, блакитна
паралель отримала чергове завдання.
Отже, відомі координати лівих та правих кінців відрізків на координатній прямій.
Потрібно знайти довжину зафарбованої частини числової прямої.*/

#include <iostream>
using namespace std;
int mas[1000000];

void in_mas(int mas[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        cin >> mas[i];
    }
}

void out_mas(int mas[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        cout << mas[i] << " ";
    }
    cout << '\n';
}

void quick_sort_mas(int left, int right)
{
    int i=left, j=right;
    int etalon = mas[(left+right)/2];
    cout << etalon << " ";
    while(i<=j)
    {
        while(mas[i]<etalon)i++;
        while(mas[j]>etalon)j--;
        if(i<=j)
        {
            swap(mas[i], mas[j]);
            i++; j--;
        }
    }
    if(left<j)quick_sort_mas(left, j);
    if(i<right)quick_sort_mas(i, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    in_mas(mas, N);
    quick_sort_mas(1, N);
    cout << '\n';
    out_mas(mas, N);
    return 0;
}