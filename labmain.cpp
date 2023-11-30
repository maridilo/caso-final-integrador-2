// Path: labmain.cpp
#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

// Clase para mostrar texto en la consola
struct ColorConsole
{

    // Colores
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
    static constexpr auto fg_red = "\033[31m";
    static constexpr auto fg_green = "\033[32m";
    static constexpr auto fg_yellow = "\033[33m";
    static constexpr auto fg_magenta = "\033[35m";
    static constexpr auto fg_cyan = "\033[36m";
    static constexpr auto fg_white = "\033[37m";
    static constexpr auto fg_black = "\033[30m";

    // Estilos
    static constexpr auto style_bold = "\033[1m";
    static constexpr auto style_reset = "\033[0m";

};

// Clase para mostrar texto en la consola
struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

// Instancias globales
ConsoleBox *console_box = new ConsoleBox;  // suponemos que ya se ha incicializado

// Función para cargar un script
void load_script(const char* filename, bool show_script =false)
{

    // Variables
    string script;
    FILE *f = nullptr;
    try
    {
        // Abrir el archivo
        f = fopen(filename, "rb");
        if (!f)
        {
            // No se pudo abrir el archivo
            throw "Error al abrir el archivo";
        }

        // Leer el archivo
        fseek(f, 0, SEEK_END);
        auto size = ftell(f);
        fseek(f, 0, SEEK_SET);
        script.resize(size);
        fread(&script[0], 1, size, f);
        fclose(f);
        if (show_script)
        {
            // Mostrar el script
            console_box->new_text();
            console_box->set_text(script);
        }
    }

// Manejo de errores
    catch (const char *error)
    {
        if (f)
        {
            fclose(f);
        }
        console_box->new_text();
        console_box->set_text(error);
    }
    // Manejo de errores
catch (...)
    {
        if (f)
        {
            fclose(f);
        }
        console_box->new_text();
        console_box->set_text("Error desconocido");
    }

    // Cerrar el archivo
    void load_script();
    {
        // Pedir el nombre del archivo
        char filename[256];
        printf("Archivo: ");
        scanf("%499s", filename);
        ::load_script(filename, true);
    }

return;
}

int main()
{
    // Cargar el script
    load_script("script.txt");

    return 0;
}
