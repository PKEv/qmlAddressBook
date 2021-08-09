#include "contactsreader.h"

namespace  {
    const std::vector<Contact> mockData {
        {"sdas", "asdasd","343423423"},
        {"dsfsdfds", "dsfdsfs", "2321321"},
        {"", "dfsdfsdfs", "343423234"}
};
}


std::pair<bool, std::vector<Contact> > ContactsReader::requestContactsBrowse()
{
    return std::make_pair(true, mockData);
}
