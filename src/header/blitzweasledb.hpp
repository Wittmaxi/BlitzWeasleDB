#ifndef BWDB_HPP
#define BWDW_HPP
#include <map>
#include <string>
#include <vector>
#include <functional>

namespace BWDB {
    class ColumnBase {};

    template <class A = std::string, A COL_NAME = "nothing", class ENTRY_TYPE = std::string> 
    class Column : ColumnBase {
    public: 
        std::map <ENTRY_TYPE, int> elem_to_rowid;
        A col_name = COL_NAME;
    };

    class EntryBase {};

    template<Column... columns>
    class Row {
    public:
        std::vector<std::reference_wrapper<ColumnBase>> input = {columns...};
        int rowid;
        template<class A>
        void changeValue (int rowid, A new_value);
        void changeValue (std::string column_name);
        std::string getValue (int rowid);
        std::string getValue (std::string column_name);
    };

    template<Column... columns>
    class Database {
        std::vector<Row<columns...>> rows;
        template<class Entry...>
        void addRow ();
    };
}

#endif