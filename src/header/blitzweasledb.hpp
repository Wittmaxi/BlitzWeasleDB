#ifndef BWDB_HPP
#define BWDW_HPP
#include <map>
#include <string>
#include <vector>

namespace BWDB {
    class Column_base {};

    template <class A = std::string, A COL_NAME = "nothing", class ENTRY_TYPE = std::string> 
    class Column : Column_base {
    public: 
        std::map <ENTRY_TYPE, int> elem_to_rowid;
        A col_name = COL_NAME;
    };


    template<Column... columns>
    class Row {
    public:
        std::vector<Column_base*> input = {(*columns)...};    
    };

    template<Column... Entries>
    class Database {

    };
}

#endif