#include "rdi_command_piping.h"


std::string exec(const std::string& cmd)
{
    redi::ipstream proc(cmd, redi::pstreams::pstdout|redi::pstreams::pstderr);
    std::string line, result ="";
    while(std::getline(proc.out(), line))
    {
       if(result.size() > 0)
           result+="\n";
       result+=line;
    }
    return result;
}

