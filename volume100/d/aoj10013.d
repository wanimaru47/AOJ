import std.stdio;
import std.string;
import std.conv;

int main()
{
    while (true) {
        string[] str = readln().split();
        if (str[0] == "0" && str[1] == "0") break;
        for (int i = 0; i < str[0].to!int(); i++) {
            for (int j = 0; j < str[1].to!int(); j++) {
                char s;
                if (i == 0 || i == str[0].to!int() - 1 || j == 0 || j == str[1].to!int() - 1) s = '#';
                else s = '.';
                write(s);
            }
            writeln();
        }
        writeln();
    }
    
    return 0;
}
