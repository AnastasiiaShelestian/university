#include <iostream>
using namespace std;

// Функция импликации
bool implication(bool a, bool b) {
    return !a || b;
}

int main() {
    // Выводим заголовок таблицы истинности
    cout << " P | Q | R | (P→Q) | (Q→R) | ((P→Q)→(Q→R)) | (¬R→¬P) | ((P→Q)→(Q→R))→(¬R→¬P)" << endl;
    cout << "---------------------------------------------------------------" << endl;

    // Перебираем все комбинации P, Q, R
    for (bool P : {false, true}) {
        for (bool Q : {false, true}) {
            for (bool R : {false, true}) {
                // Вычисляем необходимые значения
                bool PQ = implication(P, Q);
                bool QR = implication(Q, R);
                bool PQ_QR = implication(PQ, QR);
                bool notR_notP = implication(!R, !P);
                bool final_result = implication(PQ_QR, notR_notP);

                // Выводим строку таблицы истинности
                cout << " " << P << " | " << Q << " | " << R << " |   " << PQ << "   |   " << QR << "   |     " << PQ_QR << "     |    " << notR_notP << "    |         " << final_result << endl;
            }
        }
    }

    return 0;
}
