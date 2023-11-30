#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *console_box = new ConsoleBox;  // suponemos que ya se ha incicializado

void load_script(const char* filename, bool show_script =false)
{
    string script;
    FILE *f = nullptr;
    try
    {
        f = fopen(filename, "rb");
        if (!f)
        {
            throw "Error al abrir el archivo";
        }
        fseek(f, 0, SEEK_END);
        auto size = ftell(f);
        fseek(f, 0, SEEK_SET);
        script.resize(size);
        fread(&script[0], 1, size, f);
        fclose(f);
        if (show_script)
        {
            console_box->new_text();
            console_box->set_text(script);
        }
    }
    catch (const char *error)
    {
        if (f)
        {
            fclose(f);
        }
        console_box->new_text();
        console_box->set_text(error);
    }
        return;
}