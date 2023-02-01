#include <iostream>
#include <functional>

using namespace std;

float operate(float a, float b, const function<float (float, float)> &op);

int main()
{
    const string menu{"Selecciona una opcion:\n"
                      "1. Sumar\n"
                      "2. Restar\n"
                      "3. Multiplicar\n"
                      "4. Dividir\n"
                      "5. Salir\n"};
    float a, b;
    int sel;

    do {
        cout << menu << endl;
        cin >> sel;
        if (sel == 5) break;
        cout << "Introduce un numero: ";
        cin >> a;
        cout << "Introduce otro numero: ";
        cin >> b;
        switch (sel) {
        case 1:

            break;
        default:
            break;
        }

    } while (1);

    return 0;
}

float operate(float a, float b, const function<float (float, float)> &op) {
    return op(a, b);
}

auto suma = [](float a, float b) -> float {
    return a+b;
};

auto resta = [](float a, float b) -> float {
    return a-b;
};

auto multiplicacion = [](float a, float b) -> float {
    return a*b;
};

auto dividir = [](float a, float b) -> float {
    if (b == 0.f) throw domain_error("No se puede dividir por 0");
    return a/b;
};
