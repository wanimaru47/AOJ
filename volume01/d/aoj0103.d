import std.stdio;
import std.string;
import std.conv;

int main()
{
    int n = readln().chomp().to!int();
    while (n--) {
        int times = 3;
        int Hit = 0;
        int result = 0;
        while (times) {
            string str = readln().chomp();
            if (str == "HIT") {
                if (Hit == 3)  result++;
                else Hit++;
            } else if (str == "OUT") {
                times--;
            } else {
                result += (Hit + 1);
                Hit = 0;
            }
        }
        writeln(result);
    }

    return 0;
}
