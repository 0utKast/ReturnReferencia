#if 0
// VT 92 COD.001
std::string returnByValue(); // returns a copy of a std::string (expensive)
std::string& returnByReference(); // returns a reference to an existing std::string (cheap)
const std::string& returnByReferenceToConst(); // returns a const reference to an existing std::string (cheap)


// VT 92 COD.002
#include <iostream>
#include <string>

const std::string& verNombrePrograma() // devuelve una referencia constante
{
    static const std::string s_nombrePrograma{ "Calculadora" }; // tiene duración estática, 
                                                                //destruida al final del programa

    return s_nombrePrograma;
}

int main()
{
    std::cout << "Este programa se llama " << verNombrePrograma();

    return 0;
}



// VT 92 COD.003
#include <iostream>
#include <string>

const std::string& verNombrePrograma()
{
    const std::string nombrePrograma{ "Calculadora" }; // ahora es una variable local, 
                                                       //destruida cuando la función finaliza

    return nombrePrograma;
}

int main()
{
    std::cout << "Este Programa se llama " << verNombrePrograma();

    return 0;
}


// VT 92 COD.004
#include <iostream>
#include <string>

 int& obtenProxId()
{
    static int s_x{ 0 }; // nota: variable es no-const
    ++s_x; // genera la siguiente id
    return s_x; // y devuelve una referencia a ella
}

int main()
{
    int id1{ obtenProxId() }; // id1 recibe una referencia
    int id2{ obtenProxId() }; // id2 recibe una referencia
    int id3{ obtenProxId() }; // id3 recibe una referencia

    std::cout << id1 << "\n";
    std::cout << id2 << "\n";
    std::cout << id3 << "\n";
    
    return 0;
}






// VT 92 COD.005
#include <iostream>
#include <string>

const int& obtenProxId()
{
    static int s_x{ 0 }; // nota: variable es no-const
    ++s_x; // genera la siguiente id
    return s_x; // y devuelve una referencia a ella
}

int main()
{
    static const int id1{ obtenProxId() }; // id1 recibe una referencia
    static const int id2{ obtenProxId() }; // id2 recibe una referencia
    static const int id3{ obtenProxId() }; // id3 recibe una referencia

    std::cout << id1 << "\n";
    std::cout << id2 << "\n";
    std::cout << id3 << "\n";

    return 0;
}







// VT 92 COD.006
#include <iostream>
#include <string>

// Toma dos objetos std::string, devuelve el primero alfabéticamente
const std::string& primeroAlfabeto(const std::string& a, const std::string& b)
{
    return (a < b) ? a : b; // Podemos usar el operador "<" en std::string 
                            //para determinar cual llega primero alfabéticamente
}

int main()
{
    std::string primero{ "Primero" };
    std::string segundo{ "Segundo" };

    std::cout << primeroAlfabeto(primero, segundo);
    return 0;
}

#endif

// VT 92 COD.007
#include <iostream>
#include <string>

// Toma dos objetos std::string, devuelve el primero alfabéticamente
const std::string& primeroAlfabeto(const std::string& a, const std::string& b)
{
    return (a < b) ? a : b; // Podemos usar el operador "<" en std::string 
                            //para determinar cual llega primero alfabéticamente
}

int main()
{
    std::string primero{ "Primero" };
    std::string segundo{ "Segundo" };
    //recibe el return por valor, como una copia, al no ser variable por referencia
   const std::string recibidoPorValor{ primeroAlfabeto(primero, segundo) };
   //recibe el return por referencia, no como una copia, al ser variable por referencia
   const std::string& recibidoPorReferencia{ primeroAlfabeto(primero, segundo) };

   std::cout << recibidoPorValor <<"\n";
   std::cout << recibidoPorReferencia << "\n";


    return 0;
}




#if 0
#include <iostream>

// takes two integers by non-const reference, and returns the greater by reference
int& max(int& x, int& y)
{
    return (x > y) ? x : y;
}

int main()
{
    int x{ 5 };
    int y{ 6 };

    max(x, y) = 7; // sets the greater of x or y to 7

    std::cout << x << y;
    return 0;
}

#endif  