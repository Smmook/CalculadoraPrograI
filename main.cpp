// Trabajo para matrícula Progra I

#include <iostream>
#include <functional>
#include <array>

using namespace std;

float operate(float a, float b, const function<float (float, float)> &op) {
    return op(a, b);
}

/** funciones
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
**/

int main()
{
    const string menu{"Selecciona una opcion:\n"
                      "0. Sumar\n"
                      "1. Restar\n"
                      "2. Multiplicar\n"
                      "3. Dividir\n"
                      "4. Salir\n"};

    array<function<float (float, float)>, 4> funciones;
    funciones.at(0) = [](float a, float b) -> float {
        return a+b;
    };

    funciones.at(1) = [](float a, float b) -> float {
        return a-b;
    };

    funciones.at(2) = [](float a, float b) -> float {
        return a*b;
    };

    funciones.at(3) = [](float a, float b) -> float {
        if (b == 0.f) throw domain_error("No se puede dividir por 0");
        return a/b;
    };

    float a, b;
    int sel;

    do {
        do {
            cout << menu << endl;
            cin >> sel;
        } while (sel < 0 || sel > 4);
        if (sel == 4) break;
        cout << "Introduce un numero: ";
        cin >> a;
        cout << "Introduce otro numero: ";
        cin >> b;
        try {
            float res{operate(a, b, funciones.at(sel))};
            cout << "\nResultado: " << res << "\n\n";
        } catch(domain_error e) {
            cout << "No se puede dividir por 0!\n";
        }

    } while (1);

    return 0;
}


