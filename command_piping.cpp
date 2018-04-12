#include "rdi_command_piping.h"
#include<string>

using namespace std;

string RDI::execute_command(const string& cmd)
{
	redi::ipstream proc(cmd, redi::pstreams::pstdout | redi::pstreams::pstderr);
	string line, result = "";

	while(getline(proc.out(), line))
	{
	   if(result.size() > 0)
	   {
		   result += '\n';
	   }

	   result += line;
	}

	return result;
}



