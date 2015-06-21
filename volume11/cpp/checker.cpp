#include <fstream>
#include <iostream>
#include <string>

int main (int argc, char *argv[])
{
    std::ifstream ifs_res(argv[1], std::ifstream::in);
    std::ifstream ifs_ans(argv[2], std::ifstream::in);

    
    while (1) {
        std::string res;
        std::string ans;

        std::getline(ifs_res, res);
        std::getline(ifs_ans, ans);

        if ( ifs_ans.eof() && ifs_res.eof()) { break; }
        
        if (res != ans) std::cout << "FAILE " << res << " " << ans << std::endl;
        else std::cout << "SUCCESS " << res << std::endl;
    }

    return 0;
}
