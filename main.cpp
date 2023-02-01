// Trabajo para matrícula Progra I

#include <iostream>
#include <functional>

using namespace std;

float operate(float a, float b, const function<float (float, float)> &op) {
    return op(a, b);
}

auto sumar = [](float a, float b) -> float {
    return a+b;
};

auto restar = [](float a, float b) -> float {
    return a-b;
};

auto multiplicar = [](float a, float b) -> float {
    return a*b;
};

auto dividir = [](float a, float b) -> float {
    if (b == 0.f) throw domain_error("No se puede dividir por 0");
    return a/b;
};

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
        do {
            cout << menu << endl;
            cin >> sel;
        } while (sel < 1 || sel > 5);
        if (sel == 5) break;
        cout << "Introduce un numero: ";
        cin >> a;
        cout << "Introduce otro numero: ";
        cin >> b;
        float res{0.f};
        switch (sel) {
        case 1:
            res = operate(a, b, sumar);
            break;
        case 2:
            res = operate(a, b, restar);
            break;
        case 3:
            res = operate(a, b, multiplicar);
            break;
        case 4:
            try {
                res = operate(a, b, dividir);
            } catch(domain_error e) {
                cout << "No se puede dividir por cero!\n";
            }
            break;
        default:
            cout << "Error" << endl;
            break;
        }

        cout << "\nResultado: " << res << "\n\n";

    } while (1);

    return 0;
}


